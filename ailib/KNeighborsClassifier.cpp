#include "KNeighborsClassifier.h"
#include "mathutils.h"
#include "pch.h"


#define LOGGING_CONSOLE

using namespace ktstd;

void TemporaryFunction()
{
	KNeighborsClassifier<char> TempObj1;
	KNeighborsClassifier<unsigned char> TempObj2;
	KNeighborsClassifier<int> TempObj3;
	KNeighborsClassifier<unsigned int> TempObj4;
	KNeighborsClassifier<short> TempObj5;
	KNeighborsClassifier<unsigned short> TempObj6;
	KNeighborsClassifier<long> TempObj7;
	KNeighborsClassifier<unsigned long> TempObj8;
	KNeighborsClassifier<long long> TempObj9;
	KNeighborsClassifier<unsigned long long> TempObj410;
	KNeighborsClassifier<double> TempObj11;
	KNeighborsClassifier<float> TempObj12;
}



template<typename _DType>
KNeighborsClassifier<_DType>::KNeighborsClassifier()
{
	this->nNeighbors = 5;
	this->wasPredictionInvoked = false;
}

template<class _DType>
KNeighborsClassifier<_DType>::KNeighborsClassifier(int nNeighbors)
{
	this->nNeighbors = nNeighbors;
	this->wasPredictionInvoked = false;
}

template<class _DType>
void KNeighborsClassifier<_DType>::Fit(vector<vector<_DType>> trainData, vector<int> trainLabels)
{
	this->trainPointsSize = trainData.size();
	this->trainPointDim = trainData[0].size();

	this->trainFetchData = trainData;

	this->trainFetchLabel = trainLabels;
}

template<class _DType>
int KNeighborsClassifier<_DType>::Predict(vector<_DType> testSingle)
{
	vector<pair<int, double>> result;

#pragma omp parallel for
	for (int i = 0; i < this->trainPointsSize; i++)
	{
		// TODO rewrite current algorithm

		double  dist = ktstd::KtMath<_DType>::GetMinkowskiDistance(testSingle, this->trainFetchData[i], 20);
		pair<int, double> current_p(i, dist);
#pragma omp critical
		{
			result.push_back(current_p);
		}
	}

	std::sort(result.begin(), result.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right) {
		return left.second < right.second;
	});

	vector<int> NearestModels;

	for (size_t i = 0; i < this->nNeighbors; i++)
	{
		NearestModels.push_back(this->trainFetchLabel[result[i].first]);
	}

	int mostCommonNearestModel = this->FindMostCommon(NearestModels);


	return mostCommonNearestModel;


}

template<class _DType>
vector<int> KNeighborsClassifier<_DType>::Predict(vector<vector<_DType>> testData)
{
	this->wasPredictionInvoked = true;
	vector<pair<int, int>> predicts;

#pragma omp parallel for
	for (int j = 0; j < testData.size(); j++)
	{
		vector<pair<int, double>> result;

		double dist;
		vector<_DType>current;


		for (int i = 0; i < this->trainPointsSize; i++)
		{
			current = this->trainFetchData[i];

			// TODO rewrite current algorithm

			dist = ktstd::KtMath<_DType>::GetMinkowskiDistance(testData[j], current, 20);
			pair<int, double> currentPair(i, dist);

			result.push_back(currentPair);
			
		}

		std::sort(result.begin(), result.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right) {
			return left.second < right.second;
		});

		vector<int> NearestModels;

		for (size_t i = 0; i < this->nNeighbors; i++)
		{
			NearestModels.push_back(this->trainFetchLabel[result[i].first]);
		}

		int mostCommonNearestModel = this->FindMostCommon(NearestModels);

		pair<int, int> p1(mostCommonNearestModel, j);
#pragma omp critical
		{
			predicts.push_back(p1);
		}
	}

	std::sort(predicts.begin(), predicts.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right) {
		return left.second < right.second;
	});

	for (size_t i = 0; i < predicts.size(); i++)
	{
		predictResult.push_back(predicts.at(i).first);
	}

	return predictResult;
}

template<class _DType>
double KNeighborsClassifier<_DType>::AssetAccuracy(vector<int> predicted, vector<int> actual)
{
	int finitRightAnswerCount = 0;
	for (size_t i = 0; i < predicted.size(); i++)
	{
		bool status = predicted[i] == actual[i];
#ifdef LOGGING_CONSOLE
		string msg = status == 1 ? "True" : "False";
		cout << "KNNClassifier\t\tPredict: " << predicted[i] << " || Actual: " << actual[i] << "\t\tPredict is " << msg << endl;
#endif // LOGGING_CONSOLE
		if (status) finitRightAnswerCount++;
	}
#ifdef LOGGING_CONSOLE
	
	
	cout << "===================================================================\n";


	cout << "Total objects: " << predicted.size() << "\t\tTotal truely answers: " << finitRightAnswerCount << endl;

	cout << "Final accuracy: " << (double)finitRightAnswerCount / predicted.size() * 100 << endl;
#endif // LOGGING_CONSOLE
	return (double)finitRightAnswerCount / predicted.size();
}

template<class _DType>
double KNeighborsClassifier<_DType>::AssetAccuracy(vector<int> actual)
{
	if (wasPredictionInvoked)
	{
		int finitRightAnswerCount = 0;
		for (size_t i = 0; i < predictResult.size(); i++)
		{
			bool status = predictResult[i] == actual[i];
#ifdef LOGGING_CONSOLE
			string msg = status == 1 ? "True" : "False";
			cout << "KNNClassifier\t\tPredict: " << predictResult[i] << " || Actual: " << actual[i] << "\t\tPredict is " << msg << endl;
#endif // LOGGING_CONSOLE
			if (status) finitRightAnswerCount++;
		}
#ifdef LOGGING_CONSOLE
		cout << "===================================================================\n";
		cout << "Dataset training size: " << trainFetchData.size() << endl;

		cout << "Total objects: " << predictResult.size() << "\tTotal truely answers: " << finitRightAnswerCount << endl;

		cout << "Final accuracy: " << (double)finitRightAnswerCount / predictResult.size() * 100 << endl;
#endif // LOGGING_CONSOLE
		return (double)finitRightAnswerCount / predictResult.size();
	}
	else 
	{
		return -1;
	}
}

template<class _DType>
void KNeighborsClassifier< _DType>::SaveModel(string fileLocationData = "") // TODO rewrite its logic code
{

}

template<class _DType>
void KNeighborsClassifier<_DType>::LoadModel(string fileLocation)
{


}

template<class _DType>
int KNeighborsClassifier<_DType>::FindMostCommon(vector<int> value)
{
	int index = 0;
	int highest = 0;
	for (unsigned int a = 0; a < value.size(); a++)
	{
		int count = 1;
		int Position = value.at(a);
		for (unsigned int bCoef = a + 1; bCoef < value.size(); bCoef++)
		{
			if (value.at(bCoef) == Position)
			{
				count++;
			}
		}
		if (count >= index)
		{
			index = count;
			highest = Position;
		}
	}
	return highest;
}


