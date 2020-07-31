#pragma once
#include "mathutils.h"
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

template <class _TVal>
class KNeighborsClassifier 
{
public:
	KNeighborsClassifier();
	KNeighborsClassifier(int nNeighbors);
	
	void Fit(vector<vector<_TVal>> trainData, vector<int> trainLabels);
	int Predict(vector<_TVal> testSingle);
	vector<int> Predict(vector<vector<_TVal>> testData);

	static double AssetAccuracy(vector<int> predicted, vector<int> actual);
	double AssetAccuracy(vector<int> actual);

	void SaveModel(string fileLocation);
	void LoadModel(string fileLocation);

private:
	// constructor params
	int nNeighbors;


	// algorithm koef
	int trainPointsSize;
	int trainPointDim;
	vector<vector<_TVal>> trainFetchData;
	vector<int> trainFetchLabel;

	vector<int> predictResult;
	bool wasPredictionInvoked;

	// methods 
	int FindMostCommon(vector<int> value);

	
};


