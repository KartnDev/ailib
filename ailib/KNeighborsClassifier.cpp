#include "KNeighborsClassifier.h"
#include "mathutils.h"
#include "pch.h"

KNeighborsClassifier::KNeighborsClassifier()
{
	this->nNeighbors = 5;
}

inline KNeighborsClassifier::KNeighborsClassifier(int nNeighbors)
{
	this->nNeighbors = nNeighbors;

}


void KNeighborsClassifier::Fit(vector<vector<int>> trainData, vector<int> trainLabels)
{
	this->trainPointsSize = trainData.size();
	this->trainPointDim = trainData[0].size();

	this->trainFetchData = trainData;

	this->trainFetchLabel = trainLabels;
}


int KNeighborsClassifier::Predict(vector<int> testSingle)
{
	vector<pair<int, double>> result;


	for (int i = 0; i < this->trainPointsSize; i++)
	{
		// TODO rewrite current algorithm
		
		double  dist = ktstd::Math::GetMinkowskiDistance(testSingle, this->trainFetchData[i], 20);
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


vector<int> KNeighborsClassifier::Predict(vector<vector<int>> testData)
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

			dist = ktstd::Math::GetMinkowskiDistance(testData[j], current, 20);
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



		predicts.push_back(mostCommonNearestModel);

	}
	return predicts;
}


int KNeighborsClassifier::FindMostCommon(vector<int> value)
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