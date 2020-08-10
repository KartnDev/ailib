#include "pch.h"

enum Kernal
{
	linear,
	polynomial,
	rbf, // radial basis function
	sigmoid
};



template <class _DType>
class SVMClassifier // Linear - kernal svm
{
public:
	SVMClassifier();
	SVMClassifier(Kernal kernalType, double h, double lambda, double eps, double btAlpha, double btEta, int maxIter, double* initWeights, double* initWeightFast, int stepSizeInit);

	void Fit(vector<vector<_DType>> trainData, vector<int> trainLabels);
	int Predict(vector<_DType> testSingle);
	vector<int> Predict(vector<vector<_DType>> testData);

	static double AssetAccuracy(vector<int> predicted, vector<int> actual);
	double AssetAccuracy(vector<int> actual);

	void SaveModel(string fileLocation);
	void LoadModel(string fileLocation);

private:

	Kernal kernalType;
	double h;
	double lambda; 
	double eps;
	double btAlpha; 
	double btEta; 
	int maxIter;
	double * initWeights; 
	double * initWeightFast;
	int stepSizeInit;

	void* KernalFunction;

	// outdated params
	double bCoef;
	vector<double> omega;
	int trainSize;

protected:
	void* GetKernel(Kernal kernel = rbf);
	double ComputeObjective(double** K, int* y, double* beta);
	double* ComputeGradient(double** K, int* y, double* beta);
	double** ComputeGram(double* X, double* Z);
	int GetInitStepSize(double**  X);
	int Backtracking(double** X, int* y, double* beta, int step_size_prev);
	int Fast(double** X, int* y, double* beta0, double* theta0, int step_size_init);
	void Fit(double** X, int* y);
	int* Predict(double** X, double* weights = nullptr);
	double Score(double** X, int* y, double* weights = nullptr);
};

