#include "MultioutputMixin.h"
#include "BaseEstimator.h"

#include "pch.h"


class KNeighborsBase : public BaseEstimator, public MultioutputMixin
{
public:

	enum AlgorithmType
	{
		autoType,
		brute,
		kdTree,
		ballTree
	};
	enum MetricsType
	{
		minkowski,
		wminkowski,
		callback,
		precompute,
		euclidean,
		l2,
		p,
		manhattan,
		cityblock,
		l1,
		chebyshev,
		infinity
	};


	 KNeighborsBase(int nNeighbors = NULL, int radius = NULL, AlgorithmType algorithm = autoType, int leafSize = 30, MetricsType metric = minkowski,
					int p = 2, unordered_map<any, any>* metricsParams = nullptr, int nJobs = NULL,  any* callback = nullptr);



private:

	void _ChekAlgorithmMetrics();



	int nNeighbors;
	int radius;
	AlgorithmType algorithm;
	int leafSize;
	MetricsType metric;
	int p;
	unordered_map<any, any>* metricsParams;
	int nJobs = NULL;
	any* callback;
};

