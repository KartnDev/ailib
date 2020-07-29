#include <vector>
#include <tuple>


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
			KNearestNeighbors(VectorOfPoints trainData, std::vector<double> trainLabel, int kCores);

			VectorOfTuples *GetNearestK(Point &testData) const;
			

		private:
			const int kCores;
			VectorOfPoints trainData;
			std::vector<double> trainLabel;
		};
	}
}
