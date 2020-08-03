#include "pch.h"


template <class _TVal>
class SVMClassifier // Linear - kernal svm
{
public:
	SVMClassifier();
	void Fit(vector<vector<_TVal>> trainData, vector<int> trainLabels);
	int Predict(vector<_TVal> testSingle);
	vector<int> Predict(vector<vector<_TVal>> testData);

	static double AssetAccuracy(vector<int> predicted, vector<int> actual);
	double AssetAccuracy(vector<int> actual);

	void SaveModel(string fileLocation);
	void LoadModel(string fileLocation);
};

