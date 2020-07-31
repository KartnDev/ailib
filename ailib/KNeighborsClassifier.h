#pragma once

#include "Classifier.h"
#define singleThread 
#define optionalThread 
#define asyncPool 
#define maxParallel 

#define KERNAL singleThread

enum Algorithm
{
	minkowski,
	wminkowski,
	callback,
	precompute,
	euclidean,
	manhattan,
	cityblock,
	chebyshev
};


class KNeighborsClassifier 
{
public:
	KNeighborsClassifier();
	KNeighborsClassifier(int nNeighbors);
	void Fit(vector<vector<int>> trainData, vector<int> trainLabels);
	int Predict(vector<int> testSingle);
	vector<int> Predict(vector<vector<int>> testData);

private:
	// constructor params
	int nNeighbors;


	// algorithm koef
	int trainPointsSize;
	int trainPointDim;
	vector<vector<int>> trainFetchData;
	vector<int> trainFetchLabel;

	// methods 
	int FindMostCommon(vector<int> value);
};


