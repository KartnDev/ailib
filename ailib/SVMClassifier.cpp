#include "SVMClassifier.h"


template<typename _TVal>
SVMClassifier<_TVal>::SVMClassifier()
{

}

template<class _TVal>
SVMClassifier<_TVal>::SVMClassifier(Kernal kernalType)
{
}

template<class _TVal>
void SVMClassifier<_TVal>::Fit(vector<vector<_TVal>> trainData, vector<int> trainLabels)
{
}

template<class _TVal>
int SVMClassifier<_TVal>::Predict(vector<_TVal> testSingle)
{
	return 0;
}

template<class _TVal>
double SVMClassifier<_TVal>::AssetAccuracy(vector<int> predicted, vector<int> actual)
{
	return 0.0;
}

template<class _TVal>
double SVMClassifier<_TVal>::AssetAccuracy(vector<int> actual)
{
	return 0.0;
}

template<class _TVal>
void SVMClassifier<_TVal>::SaveModel(string fileLocation)
{
}

template<class _TVal>
void SVMClassifier<_TVal>::LoadModel(string fileLocation)
{
}
