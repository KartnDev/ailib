#include "KNeighborsBase.h"
#include "ValueException.h"
KNeighborsBase::KNeighborsBase(int nNeighbors, int radius, AlgorithmType algorithm, int leafSize, MetricsType metric, int p, unordered_map<any, any>* metricsParams, int nJobs, any* callback)
{
	this->nNeighbors = nNeighbors;
	this->radius = radius;
	this->algorithm = algorithm;
	this->leafSize = leafSize;
	this->metric = metric;
	this->p = p;
	this->metricsParams = metricsParams;
	this->nJobs = nJobs;
	this->callback = callback;

	_ChekAlgorithmMetrics();
}

void KNeighborsBase::_ChekAlgorithmMetrics()
{
	AlgorithmType algorithmCheck;
	int effective_p;
	if (this->algorithm == autoType)
	{
		if (this->metric == precompute)
		{
			algorithmCheck = brute;
		}
		else if (this->callback != nullptr)
		{
			algorithmCheck = ballTree;
		}
		else
		{
			algorithmCheck = brute;
		}
	} 
	else
	{
		algorithmCheck = this->algorithm;
	}
	if (this->callback != nullptr)
	{
		if (this->algorithm == kdTree)
		{
			// callable metric is only valid for brute force and ball_tree
			throw new ValueException("kd_tree does not support callable metric Function call overhead will result in very poor performance.");
		}
	}
	if (this->metricsParams != nullptr && this->metricsParams->count("p"))
	{
#pragma message ("Parameter p is found in metric_params. The corresponding parameter from constructor is ignored.")
		effective_p = std::any_cast<int>(metricsParams->at("p"));
	}
	else
	{
		effective_p = this->p;
	}

	if ((this->metric == wminkowski || this->metric == minkowski) && effective_p < 1)
	{
		throw new ValueException("p must be greater than one for minkowski metric");
	}
			
}
