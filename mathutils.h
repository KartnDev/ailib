#include <vector>

namespace ktstd
{
#define DIMENTIONS 2


	class Math
	{
	public:
		static double StdEuclideanDist(double point1[DIMENTIONS], double point2[DIMENTIONS]) noexcept;
		
		static double StdEuclideanDist(std::vector<double> point1, std::vector<double> point2);
		
	};


}
