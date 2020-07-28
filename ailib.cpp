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
	typedef std::tuple<std::vector<double>, double, double> tupleResult;
	typedef std::vector <tupleResult> vectorOfTuples;

	namespace models 
	{
		class KNearestNeighbors 
		{
			

		public:
			KNearestNeighbors(std::vector<std::vector<double>> trainData, std::vector<double> trainLabel, int kCores) : kCores(kCores)
			{
				this->trainData = trainData;
				this->trainLabel = trainLabel;
			}

			std::tuple<std::vector<double>, double, int> GetNearestK(std::vector<double> testData)
			{
				vectorOfTuples neighborsResult;

				for (size_t i = 0; i < this->trainData.size(); i++)
				{
					double dist = Math::StdEuclideanDist(testData, this->trainData[i]);

					tupleResult tuple(this->trainData[i], dist, trainLabel);

					neighborsResult.push_back(tuple);
				} 
				std::sort(neighborsResult.begin(), neighborsResult.end(), 
					[](tupleResult t1, tupleResult t2) -> size_t 
				{
					return std::get<1>(t1) > std::get<1>(t2);
				});
				neighborsResult

			}

		private:
			const int kCores;
			std::vector<std::vector<double>> trainData;
			std::vector<double> trainLabel;
		};
	}
}
