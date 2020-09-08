#include "pch.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <omp.h>
#include "../ailib/FileUtilities.h"
#include "../ailib/KNeighborsClassifier.h"
#include "../ailib/KNeighborsClassifier.cpp"
#include "../ailib/LinAlg.h"
#include "../ailib/LinAlg.cpp"

using namespace std;
using namespace ktstd;

template<typename _DType>
tuple<vector<vector<_DType>>, vector<int>, vector<vector<_DType>>, vector<int>> CSVReadAndSplit(string trainFile, string testFile)
{
	FileUtilities::CSV csvTest(testFile);

	FileUtilities::CSV csvTrain(trainFile);

	vector<vector<_DType>> trainData;
	vector<int> trainLabel;

	for (int i = 1; i < csvTrain.linesOfData.size() - 10; i++)
	{
		vector<_DType> currentLine;

		for (int j = 1; j < csvTrain.linesOfData[i].size(); j++)
		{
			currentLine.push_back((_DType)stoi(csvTrain.linesOfData[i][j]));
		}

		trainData.push_back(currentLine);
	}

	for (int i = 0; i < csvTrain.linesOfData.size() - 10; i++)
	{
		trainLabel.push_back(stoi(csvTrain.dataAsLabels["label"][i]));

	}

	vector<vector<_DType>> testData;
	vector<int> testLabel;

	for (int i = 1; i < csvTest.linesOfData.size() - 10; i++)
	{
		vector<_DType> currentLine;

		for (int j = 1; j < csvTest.linesOfData[i].size(); j++)
		{
			currentLine.push_back((_DType)stoi(csvTest.linesOfData[i][j]));
		}

		testData.push_back(currentLine);
	}

	for (int i = 0; i < csvTest.linesOfData.size() - 10; i++)
	{
		testLabel.push_back(stoi(csvTest.dataAsLabels["label"][i]));

	}

	tuple<vector<vector<_DType>>, vector<int>, vector<vector<_DType>>, vector<int>> result(trainData, trainLabel, testData, testLabel);

	return result;
}

void testKNN()
{
	string testFileName = "C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\ailib\\mnist_test.csv";
	string trainFileName = "C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\ailib\\mnist_train.csv";
	auto splittedData = CSVReadAndSplit<unsigned char>(trainFileName, testFileName);

	KNeighborsClassifier<unsigned char> classifier;
	classifier.Fit(std::get<0>(splittedData), std::get<1>(splittedData));

	vector<int> predictions = classifier.Predict(std::get<2>(splittedData));
	vector<int> real = std::get<3>(splittedData);

	classifier.AssetAccuracy(real);
}

template <class T>
std::vector <std::vector<T>> Multiply(std::vector <std::vector<T>> a, std::vector <std::vector<T>> &b)
{
	const int n = a.size();     // a rows
	const int m = a[0].size();  // a cols
	const int p = b[0].size();  // b cols

	std::vector <std::vector<T>> c(n, std::vector<T>(p, 0));
	for (auto j = 0; j < p; ++j)
	{
		for (auto k = 0; k < m; ++k)
		{
			for (auto i = 0; i < n; ++i)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}


int main(int argc, char **argv)
{
	vector<vector<double>> K{   {2,  9,  4,  4,  6,  5,  8,  5,  2, 10},
								{5,  5,  9,  8,  6, 10,  1,  3,  9,  5},
								{3,  9,  3,  5,  8,  8,  9,  9,  9, 10},
								{3, 10,  7,  2,  8,  2,  5,  8,  6,  3},
								{1,  8,  3,  1, 10,  3,  5,  1,  6,  1},
								{4,  2,  1,  8,  6,  6,  2,  2, 10, 10},
								{7,  4,  3,  2,  6,  6,  4,  8,  6,  4},
								{6, 10,  4,  2,  7,  1,  7,  6,  9,  6},
								{5,  3,  6, 10,  1,  1,  7,  6,  6,  3},
								{4, 10,  4,  4,  1,  4,  1,  1,  8, 10} };

	vector<vector<double>> y{ {-1},
								{1},
								{-1},
								{1},
								{-1},
								{1},
								{-1},
								{1},
								{-1},
								{1} };


	vector<vector<double>> v{ {3},
								{7},
								{1},
								{7},
								{8},
								{8},
								{5},
								{4},
								{3},
								{2} };

	vector<vector<double>> KBeta = LinAlg<double>::MatrixMultiply(K, v);

	auto Transmont = LinAlg<double>::Transponse(v);

	vector<vector<double>> KBetaNext = LinAlg<double>::MatrixMultiply(Transmont, KBeta);


	system("pause");

	return 0;
}