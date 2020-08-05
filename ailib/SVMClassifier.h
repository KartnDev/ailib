#include "pch.h"

enum Kernal
{
	linear,
	polynomial,
	rbf, // radial basis function
	sigmoid
};



template <class _TVal>
class SVMClassifier // Linear - kernal svm
{
public:
	SVMClassifier();
	SVMClassifier(Kernal kernalType);
	void Fit(vector<vector<_TVal>> trainData, vector<int> trainLabels);
	int Predict(vector<_TVal> testSingle);
	vector<int> Predict(vector<vector<_TVal>> testData);

	static double AssetAccuracy(vector<int> predicted, vector<int> actual);
	double AssetAccuracy(vector<int> actual);

	void SaveModel(string fileLocation);
	void LoadModel(string fileLocation);

private:
	double bCoef;
	vector<double> omega;
	int trainSize;
	Kernal typeKernal;
};

