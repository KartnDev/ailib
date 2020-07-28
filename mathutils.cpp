#include <cmath>
#include <vector>
#include <exception>

namespace ktstd 
{
#define DIMENTIONS 2


	class Math
	{
	public:
		static double StdEuclideanDist(double point1[DIMENTIONS], double point2[DIMENTIONS])
		{
			double sum = 0;
			for (size_t i = 0; i < DIMENTIONS; i++)
			{
				sum += (point1[i] - point2[i]) * (point1[i] - point2[i]); //  (p-q)^2
			}

			return sqrt(sum);
		}
		static double StdEuclideanDist(std::vector<double> point1, std::vector<double> point2)
		{
			if (point1.size() == point2.size()) 
			{
				double sum = 0;
				for (size_t i = 0; i < point1.size(); i++)
				{
					sum += (point1[i] - point2[i]) * (point1[i] - point2[i]); //  (p-q)^2
				}

				return sqrt(sum);
			}
			else
			{
				throw new std::exception("pointsof the distanse in different dimentions!");
			}
		}
	};


}