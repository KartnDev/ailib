#include "ailib.h"
#include "mathutils.h"
#include <algorithm>

// ailib.cpp : Определяет функции для статической библиотеки.
//
using namespace ktstd;


ktstd::models::KNearestNeighbors::KNearestNeighbors(VectorOfPoints trainData, std::vector<double> trainLabel, int kCores) : kCores(kCores)
{
	this->trainData = trainData;
	this->trainLabel = trainLabel;
}

VectorOfTuples * ktstd::models::KNearestNeighbors::GetNearestK(Point & testData) const
{
	VectorOfTuples neighborsResult;

	for (size_t i = 0; i < this->trainData.size(); i++)
	{
		double dist = Math::StdEuclideanDist(testData, this->trainData[i]);

		TupleResult tuple(this->trainData[i], dist, trainLabel[i]);

		neighborsResult.push_back(tuple);
	}
	std::sort(neighborsResult.begin(), neighborsResult.end(),
		[](TupleResult t1, TupleResult t2) -> size_t
	{
		return std::get<1>(t1) > std::get<1>(t2);
	});

	for (size_t i = 0; i < neighborsResult.size() - this->kCores; i++)
	{
		neighborsResult.pop_back();
	}

	return &neighborsResult;

}
