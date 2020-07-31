#include <vector>

namespace ktstd
{
#define DIMENTIONS 2


	class Math
	{
	public:
		static double StdEuclideanDist(int point1[], int point2[], int dim) noexcept;
		double StdEuclideanDist(std::vector<int> point1, std::vector<int> point2);
		static double GetMinkowskiDistance(std::vector<int> point1, std::vector<int> point2, double r);
	};


}
