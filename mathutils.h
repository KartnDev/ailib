#include <vector>

namespace ktstd
{
#define DIMENTIONS 2


	class Math
	{
	public:
		static double StdEuclideanDist(double point1[DIMENTIONS], double point2[DIMENTIONS]) noexcept;
		static double StdEuclideanDist(vector<double> point1, vector<double> point2);
		static double StdEuclideanDist(vector<string> point1, vector<string> point2);
	};


}
