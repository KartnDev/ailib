// ailib.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include <vector>
#include <tuple>
#include "mathutils.cpp"
#include <algorithm>

namespace ktstd
{
	typedef std::tuple<std::vector<double>, double, double> TupleResult;
	typedef std::vector <TupleResult> VectorOfTuples;

	typedef std::vector<double> Point;
	typedef std::vector<Point> VectorOfPoints;


	namespace models 
	{
		class KNearestNeighbors 
		{
		public:
			KNearestNeighbors(VectorOfPoints trainData, std::vector<double> trainLabel, int kCores) : kCores(kCores)
			{
				this->trainData = trainData;
				this->trainLabel = trainLabel;
			}

			VectorOfTuples *GetNearestK(Point &testData)
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

		private:
			const int kCores;
			VectorOfPoints trainData;
			std::vector<double> trainLabel;
		};
	}
}
