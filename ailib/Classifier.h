#include "pch.h"
template<typename _DType>
class Classifier
{
public:
	virtual void Fit(vector<vector<_DType>> trainData, vector<int> trainLabels) = 0;
	virtual void Fit(_DType** trainData, int* trainLabels) = 0;
	virtual void Fit(_DType trainData[][], int trainLabels[]) = 0;

	virtual int PredictOne(vector<_DType> testSingle) = 0;
	virtual int PredictOne(_DType* testSingle) = 0;
	virtual int PredictOne(_DType testSingle[]) = 0;

	virtual vector<int> PredictMany(vector<vector<_DType>> testData) = 0;
	virtual vector<int> PredictMany(_DType** testData) = 0;
	virtual vector<int> PredictMany(_DType testData[][]) = 0;

	virtual int* PredictMany(vector<vector<_DType>> testData) = 0;
	virtual int* PredictMany(_DType** testData) = 0;
	virtual int* PredictMany(_DType testData[][]) = 0;


	virtual static double AssetAccuracy(vector<int> predicted, vector<int> actual) = 0;
	virtual static double AssetAccuracy(int* predicted, int* actual) = 0;
	virtual static double AssetAccuracy(int predicted[], int actual[]) = 0;

	virtual double AssetAccuracy(vector<int> actual) = 0;
	virtual double AssetAccuracy(int* actual) = 0;
	virtual double AssetAccuracy(int actual[]) = 0;

	virtual void SaveModel(string fileLocation) = 0;
	virtual void LoadModel(string fileLocation) = 0;
};

