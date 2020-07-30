#include "ailib.h"
#include "mathutils.h"
#include "file_utilities.h"
#include <algorithm>
#include <random>

// ailib.cpp : Определяет функции для статической библиотеки.
//
using namespace ktstd;

ktstd::models::KNearestNeighbors::KNearestNeighbors(vector<vector<string>> dataset, int nFolds, int numNeighbors)
{
}

vector<double> ktstd::models::KNearestNeighbors::EvaluateAlgorithm(vector<vector<string>> dataset, int nFolds)
{
	return vector<double>();
}

vector<double> ktstd::models::KNearestNeighbors::PredictClassification(vector<vector<string>> train, vector<double> testRow)
{
	return vector<double>();
}

int _RandRange(int fStart, int fEnd)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(fStart, fEnd); // define the range
	return distr(gen);
}

int _RandRange(int fZeroRange)
{
	return _RandRange(0, fZeroRange);
}


vector<vector<double>> ktstd::models::KNearestNeighbors::CrossValidationSplit(vector<vector<string>> dataset)
{
	vector<vector<double>> datasetSplit;
	vector<vector<string>> dataset_copy(dataset);

	int fold_size = (int) (dataset.size() / nFolds);
	for (size_t i = 0; i < nFolds; i++)
	{
		vector<double> fold;
		while (fold.size() < fold_size) 
		{
			int index = _RandRange(dataset_copy.size());
			fold.push_back(dataset_copy.pop_back(index));
		}
		datasetSplit.push_back(fold);
		return datasetSplit;
	}
	
}

pair<double, double> ktstd::models::KNearestNeighbors::DatasetMinmax(vector<vector<string>> dataset)
{
	return pair<double, double>();
}

double ktstd::models::KNearestNeighbors::accuracy_metric(vector<double> actual, vector<double> predicted)
{
	return 0.0;
}

vector<vector<double>> ktstd::models::KNearestNeighbors::KNearestNeighborsAlg(vector<vector<string>> train, vector<vector<string>> test)
{
	return vector<vector<double>>();
}
