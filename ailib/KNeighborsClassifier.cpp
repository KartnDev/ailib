#include "KNeighborsClassifier.h"
#include "mathutils.h"
#include "pch.h"



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



template<typename _TVal>
KNeighborsClassifier<_TVal>::KNeighborsClassifier()
{
	this->nNeighbors = 5;
}

template<class _TVal>
KNeighborsClassifier<_TVal>::KNeighborsClassifier(int nNeighbors)
{
	this->nNeighbors = nNeighbors;
}

template<class _TVal>
void KNeighborsClassifier<_TVal>::Fit(vector<vector<_TVal>> trainData, vector<int> trainLabels)
{
	this->trainPointsSize = trainData.size();
	this->trainPointDim = trainData[0].size();

	this->trainFetchData = trainData;

	this->trainFetchLabel = trainLabels;
}

template<class _TVal>
int KNeighborsClassifier<_TVal>::Predict(vector<int> testSingle)
{

	vector<pair<int, double>> result;


	for (int i = 0; i < this->trainPointsSize; i++)
	{
		// TODO rewrite current algorithm

		double  dist = ktstd::KtMath::GetMinkowskiDistance(testSingle, this->trainFetchData[i], 20);
		pair<int, double> current_p(i, dist);

		result.push_back(current_p);
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

template<class _TVal>
vector<int> KNeighborsClassifier<_TVal>::Predict(vector<vector<_TVal>> testData)
{
	vector<int> predicts;

#pragma omp parallel for
	for (int j = 0; j < testData.size(); j++)
	{
		vector<pair<int, double>> result;

		// memory optimize
		double dist;
		vector<int> current;

		for (int i = 0; i < this->trainPointsSize; i++)
		{
			current = this->trainFetchData[i];

			// TODO rewrite current algorithm

			dist = ktstd::KtMath::GetMinkowskiDistance(testData[j], current, 20);
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

		predicts.push_back(mostCommonNearestModel);

	}
	return predicts;
}

template<class _TVal>
double KNeighborsClassifier<_TVal>::AssetAccuracy(vector<int> predicted, vector<int> actual)
{
	return 0.0;
}

template<class _TVal>
double KNeighborsClassifier<_TVal>::AssetAccuracy(vector<int> actual)
{
	return 0.0;
}

template<class _TVal>
void KNeighborsClassifier< _TVal>::SaveModel(string fileLocation)
{
}

template<class _TVal>
int KNeighborsClassifier<_TVal>::FindMostCommon(vector<int> value)
{
	int index = 0;
	int highest = 0;
	for (unsigned int a = 0; a < value.size(); a++)
	{
		int count = 1;
		int Position = value.at(a);
		for (unsigned int b = a + 1; b < value.size(); b++)
		{
			if (value.at(b) == Position)
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


