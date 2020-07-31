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

using namespace std;
using namespace ktstd;


tuple<vector<vector<int>>, vector<int>, vector<vector<int>>, vector<int>> CSVReadAndSplit(string trainFile, string testFile)
{
	FileUtilities::CSV csvTest(testFile);

	FileUtilities::CSV csvTrain(trainFile);

	vector<vector<int>> trainData;
	vector<int> trainLabel;

	for (int i = 1; i < csvTrain.linesOfData.size() - 10; i++)
	{
		vector<int> currentLine;

		for (int j = 1; j < csvTrain.linesOfData[i].size(); j++)
		{
			currentLine.push_back(stoi(csvTrain.linesOfData[i][j]));
		}

		trainData.push_back(currentLine);
	}

	for (int i = 0; i < csvTrain.linesOfData.size() - 10; i++)
	{
		trainLabel.push_back(stoi(csvTrain.dataAsLabels["label"][i]));

	}

	vector<vector<int>> testData;
	vector<int> testLabel;

	for (int i = 1; i < csvTest.linesOfData.size() - 10; i++)
	{
		vector<int> currentLine;

		for (int j = 1; j < csvTest.linesOfData[i].size(); j++)
		{
			currentLine.push_back(stoi(csvTest.linesOfData[i][j]));
		}

		testData.push_back(currentLine);
	}

	for (int i = 0; i < csvTest.linesOfData.size() - 10; i++)
	{
		testLabel.push_back(stoi(csvTest.dataAsLabels["label"][i]));

	}

	tuple<vector<vector<int>>, vector<int>, vector<vector<int>>, vector<int>> result(trainData, trainLabel, testData, testLabel);

	return result;
}






int main(int argc, char **argv) {

	string testFileName = "C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\ailib\\mnist_test.csv";
	string trainFileName = "C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\ailib\\mnist_train.csv";

	auto splittedData = CSVReadAndSplit(trainFileName, testFileName);



	KNeighborsClassifier classifier;

	classifier.Fit(std::get<0>(splittedData), std::get<1>(splittedData));


	int right = 0;


	//vector<int> predictions = classifier.Predict(std::get<2>(splittedData));

	//vector<int> real = std::get<3>(splittedData);

	//for (size_t i = 0; i < real.size(); i++)
	//{
	//	cout << "predicted: " << predictions[i] << " || actual: " << real[i] << endl;
	//	if (predictions == real)
	//	{
	//		right++;
	//	}
	//}

	//double acc = right / real.size();

	//cout << "accuracy: " << acc << "right answers: " << right << endl;
#pragma omp parallel for
	for (int i = 0; i < std::get<2>(splittedData).size(); i++)
	{
		int  prediction = classifier.Predict(std::get<2>(splittedData)[i]);
		cout << "predicted: " << prediction << " || actual: " << std::get<3>(splittedData)[i] << endl;
		if (prediction == std::get<3>(splittedData)[i])
		{
			right++;
		}
	}

	double acc = (double)right / std::get<2>(splittedData).size();

	cout << "accuracy: " << acc*100 << "% Right answers: " << right << endl;
	


	system("pause");

	return 0;
}