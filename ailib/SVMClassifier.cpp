#include "SVMClassifier.h"


template<typename _DType>
SVMClassifier<_DType>::SVMClassifier()
{
	this->typeKernal = rbf;
}

template<class _DType>
SVMClassifier<_DType>::SVMClassifier(Kernal kernalType)
{

}


/*
Custom implementation of SVM for binary classification with support for
		Gaussian RBF kernel, Polynomial kernel and Linear kernel. Uses Fast Gradient
		Descent algorithm to minimize smoothed hinge loss.

	Parameters:
	-----------
	kernel: Specifies the kernel type to be used in the algorithm. It must be
	one of 'rbf', 'polynomial, or 'linear'. Kernel hyperparameters are passed
	via the kwagrs parameter. For more infomation of the hyperparameters, refer
	to the kwargs section and the _get_kernel function. It is used to compute
	the similarity between data points. Default is 'rbf'.

	h: Specifies the smoothness coefficient of the smoothed hinged loss. Default
	is 0.5.

	lambda_: Specifies the L2 regularization coefficient. Default is 0.1.

	eps: Specifies the tolerance value for the stopping criterion. Default is
	0.001.

	bt_alpha: Specifies the sufficient decrease factor for backtracking line
	search. Default is 0.5.

	bt_eta: Specifies the factor of decrease of step size at each step in the
	backtracking line search. Default is 0.8.

	max_iter: Specifies the maximum number of iterations the algorithm would run
	for. The algorithm would be forced to terminate even if the convergence
	criterion has not been reached yet. Default is 1000.

	init_weights: Specifies the weight vector of shape (n, 1) with which the
	model must start. Default is set to zero vector of the size (n, 1).

	init_weights_fast: Specifies the initial additional weight vector of shape
	(n, 1) which would be used by the Fast Gradient Descent algorithm. Default
	is set to zero vector of the size (n, 1).

	step_size_init: Specifies the initial step size used by the Fast Gradient
	Descent algorithm. Default is calculated by the _get_init_step_size using
	the smoothness constant.

	kwargs: Specifies any additional parameters required by the kernel. The
	Gaussian RBF kernel requires providing a parameter 'sigma' and Polynomial
	kernel requires parameters 'power' and 'bias'.

	Attributes:
	-----------
	params_: The final weight values of the model which minimize the smoothed
	hinge loss.

	objective_log_: List of objective values calculated at each iteration of
	the Fast Gradient Descent algorithm.

	param_log_: List of updated weights after each iteration of the Fast Gradient
	Descent algorithm.

	"""
*/
template<class _DType>
SVMClassifier<_DType>::SVMClassifier(Kernal kernalType = rbf, double h = 0.5, double lambda = 0.1, double eps = 1e-3, double btAlpha = 0.5, double btEta = 0.8, int maxIter = 1000,
	double * initWeights = nullptr, double * initWeightFast = nullptr, int stepSizeInit = NULL)
{
	this->kernalType = kernalType;
	this->h = h;
	this->lambda = lambda;
	this->eps = eps;
	this->btAlpha = btAlpha;
	this->btEta = btEta;
	this->maxIter = maxIter;
	this->initWeights = initWeights;
	this->initWeightFast = initWeightFast;
	this->stepSizeInit = stepSizeInit;

	this->KernalFunction = this->GetKernel(kernalType);
}

template <typename InputIterator, typename OutputIterator, typename UnaryOperation>
OutputIterator threadedTransform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperation op, unsigned num_threads)
{
	std::size_t numValuesPerThreads = std::distance(first, last) / num_threads;

	std::vector<std::thread> threads;
	threads.reserve(num_threads);

	for (int i = 1; i <= num_threads; ++i) {
		if (i == num_threads) {
			threads.push_back(std::thread(std::transform<InputIterator,
				OutputIterator, UnaryOperation>,
				first, last, result, op));
		}
		else {
			threads.push_back(std::thread(std::transform<InputIterator,
				OutputIterator, UnaryOperation>,
				first, first + numValuesPerThreads,
				result, op));
		}
		first += numValuesPerThreads;
		result += numValuesPerThreads;
	}

	for (auto& thread : threads) thread.join();

	return result;
}

template <typename InputIterator, typename OutputIterator, typename UnaryOperation>
OutputIterator threadedTransform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperation op)
{
	return threadedTransform<InputIterator, OutputIterator, UnaryOperation>(first, last, result, op, std::thread::hardware_concurrency());
}

template <typename T>
typename std::vector<T>::const_iterator maxElement(const std::vector<std::vector<T>>& values)
{
	if (values.empty()) throw std::runtime_error{ "values cannot be empty" };

	std::vector<std::pair<typename std::vector<T>::const_iterator, bool>> maxes(values.size());

	threadedTransform(values.cbegin(), values.cend(), maxes.begin(),
		[](const auto& v) {
		return std::make_pair(std::max_element(v.cbegin(), v.cend()), v.empty());
	});

	auto it = std::remove_if(maxes.begin(), maxes.end(), [](auto p) { return p.second; });

	if (it == maxes.begin()) throw std::runtime_error{ "values cannot be empty" };

	return std::max_element(maxes.begin(), it,
		[](auto lhs, auto rhs) {
		return *lhs.first < *rhs.first;
	})->first;
}

template <typename T>
typename std::vector<T>::const_iterator minElement(const std::vector<std::vector<T>>& values)
{
	if (values.empty()) throw std::runtime_error{ "values cannot be empty" };

	std::vector<std::pair<typename std::vector<T>::const_iterator, bool>> mines(values.size());

	threadedTransform(values.cbegin(), values.cend(), mines.begin(),
		[](const auto& v) {
		return std::make_pair(std::min_element(v.cbegin(), v.cend()), v.empty());
	});

	auto it = std::remove_if(mines.begin(), mines.end(), [](auto p) { return p.second; });

	if (it == mines.begin()) throw std::runtime_error{ "values cannot be empty" };

	return std::min_element(mines.begin(), it,
		[](auto lhs, auto rhs) {
return *lhs.first < *rhs.first;
	})->first;
}

vector<vector<double>> createTransorm(int dimension)
{
	vector<vector<double>> result;

	vector<double> finitMachineHeader;

	for (size_t i = 0; i < dimension; i++)
	{
		finitMachineHeader.push_back(1); // createing ones matrix for start
	}

	for (size_t i = 0; i < dimension; i++)
	{
		result.push_back(finitMachineHeader);
		finitMachineHeader[i] = -1;
	}
	result.push_back(finitMachineHeader);

	for (size_t i = dimension - 1; i > 0; i--)
	{
		finitMachineHeader[i] = -1;
		result.push_back(finitMachineHeader);
	}

	return result;
}
template <typename _DType>
double dot(const std::vector<_DType>& vector1, const std::vector<_DType>& vector2)
{
	if (vector1.empty() || vector1.size() != vector2.size())
	{
		throw std::runtime_error{ "values cannot be empty or vectors different sizes" };
	}

	double sum = 0;

	for (size_t i = 0; i < vector1.size(); i++)
	{
		sum += vector1[i] * vector2[i];
	}
	return sum;
}

std::vector<double> componentalMultiply(const vector<double>& vector1, const vector<double>& vector2)
{
	vector<double> result;


	for (size_t i = 0; i < vector1.size(); i++)
	{
		result.push_back(vector1[i] * vector2[i]);
	}

	return result;

}

double vectorNorm(vector <double> vector)
{
	double sum = 0;

	for (size_t i = 0; i < vector.size(); i++)
	{
		sum += vector[i] * vector[i];
	}
	return sum;
}

std::vector<double> complonentalDecriseByUnit(const vector<double>& vect, double unit)
{
	vector<double> result;


	for (size_t i = 0; i < vect.size(); i++)
	{
		result.push_back(vect[i] - unit);
	}

	return result;
}

void complonentalDecriseByUnitMutable(mutable vector<double>& vect, double unit)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
		vect.push_back(vect[i] - unit);
	}
}

std::vector<double> sign(const vector<double>& vect)
{
	vector<double> result;


	for (size_t i = 0; i < vect.size(); i++)
	{
		int current = 0;
		if (vect[i] > 0)
		{
			current = 1;
		}
		else if (vect[i] < 0)
		{
			current = -1;
		}

		result.push_back(current);
	}

	return result;
}

void sign(mutable vector<double>& vect)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
		int current = 0;
		if (vect[i] > 0)
		{
			current = 1;
		}
		else if (vect[i] < 0)
		{
			current = -1;
		}
		vect[i] = current;
	}
}

int sign(double val)
{
	int current = 0;
	if (val > 0)
	{
		current = 1;
	}
	else if (val < 0)
	{
		current = -1;
	}
	return current;
}


template<class _DType>
void SVMClassifier<_DType>::Fit(vector<vector<_DType>> trainData, vector<int> trainLabels)
{
	this->trainSize = trainLabels.size();

	double maxFeatureVal = maxElement(trainData);
	double minFeatureVal = minElement(trainData);

	vector<double> learningRate{ maxFeatureVal * 0,1, maxFeatureVal*0.01, maxFeatureVal*0.001 };

	vector<pair<vector<double>, double>> lengthVectorW;

	vector<vector<double>> transforms = createTransofm(trainLabels[0].size());

	int bMultiply = 5;
	int bStepSize = 2
	int wOptimum = maxFeatureVal * 0.5;

	for each (double lrate in learningRate)
	{
		this->omega = vector<double>{ wOptimum, wOptimum };

		bool optimized = false;

		while (!optimized)
		{
			for (size_t b = -1 * (maxFeatureVal*bStepSize); b < maxFeatureVal*bStepSize; b += lrate * bMultiply)
			{
				for each (vector<double> transform in transforms)
				{
					vector<double> omegaT = componentalMultiply(w, transformation);

					bool correctlyClassified = true;

					for (size_t index = 0; index < trainData.size(); index++)
					{
						if ((trainLabels[index] * dot(omegaT, trainData[index]) + b) < 1 )
						{
							correctlyClassified = false;
						}
					}
					if (correctlyClassified)
					{
						auto current = make_pair(omegaT, b);

						int index = vectorNorm(omegaT);

						lengthVectorW.insert(index, current);
					}
				}
			}
			if (omega[0] < 0)
			{
				optimized = true;
			}
			else
			{
				complonentalDecriseByUnitMutable(omega, lrate);
			}

			sort(lengthVectorW.cbegin(), lengthVectorW.cend());

			pair<vector<double>, double> pairMinimal = lengthVectorW[0];
			this->omega = pairMinimal.first();
			this->bCoef = pairMinimal.second();

			wOptimum = omega[0] + lrate * 2
		}
	}
}

template<class _DType>
int SVMClassifier<_DType>::Predict(vector<_DType> testSingle)
{
	dot_result = sign(dot(testSingle, omega) + bCoef)
	return dot_result
}

template<class _DType>
double SVMClassifier<_DType>::AssetAccuracy(vector<int> predicted, vector<int> actual)
{
	return 0.0;
}

template<class _DType>
double SVMClassifier<_DType>::AssetAccuracy(vector<int> actual)
{
	return 0.0;
}

template<class _DType>
void SVMClassifier<_DType>::SaveModel(string fileLocation)
{
}

template<class _DType>
void SVMClassifier<_DType>::LoadModel(string fileLocation)
{
}

template<class _DType>
void * SVMClassifier<_DType>::GetKernel(Kernal kernel)
{
	switch (kernal)
	{
	case rbf:
		return 
		break;
	default:
		break;
	}
}

template<class _DType>
double SVMClassifier<_DType>::ComputeObjective(double ** K, int * y, double * beta)
{
	return 0.0;
}

template<class _DType>
double * SVMClassifier<_DType>::ComputeGradient(double ** K, int * y, double * beta)
{
	return nullptr;
}
template<class _DType>
double ** SVMClassifier<_DType>::ComputeGram(double * X, double * Z)
{
	return nullptr;
}

template<class _DType>
int SVMClassifier<_DType>::GetInitStepSize(double ** X)
{
	return 0;
}

template<class _DType>
int SVMClassifier<_DType>::Backtracking(double ** X, int * y, double * beta, int step_size_prev)
{
	return 0;
}

template<class _DType>
int SVMClassifier<_DType>::Fast(double ** X, int * y, double * beta0, double * theta0, int step_size_init)
{
	return 0;
}

template<class _DType>
void SVMClassifier<_DType>::Fit(double ** X, int * y)
{
}

template<class _DType>
int * SVMClassifier<_DType>::Predict(double ** X, double * weights)
{
	return nullptr;
}

template<class _DType>
double SVMClassifier<_DType>::Score(double ** X, int * y, double * weights)
{
	return 0.0;
}
