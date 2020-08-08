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



int main(int argc, char **argv) {

	string testFileName = "C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\ailib\\mnist_test.csv";
	string trainFileName = "C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\ailib\\mnist_train.csv";

	auto splittedData = CSVReadAndSplit<unsigned char>(trainFileName, testFileName);



	KNeighborsClassifier<unsigned char> classifier;

	classifier.Fit(std::get<0>(splittedData), std::get<1>(splittedData));


	int right = 0;


	vector<int> predictions = classifier.Predict(std::get<2>(splittedData));

	vector<int> real = std::get<3>(splittedData);

	classifier.AssetAccuracy(real);

	system("pause");

	return 0;
}