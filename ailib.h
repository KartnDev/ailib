#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;


namespace ktstd
{
	namespace models
	{
		class KNearestNeighbors
		{
		public:
			KNearestNeighbors(vector<vector<string>> dataset, int nFolds, int numNeighbors);
			vector<double> EvaluateAlgorithm(vector<vector<string>> dataset, int nFolds);
			vector<double> PredictClassification(vector<vector<string>> train, vector<double>  testRow);

		private:
			int numNeighbors;
			int nFolds;
			vector<vector<string>> trainDataset;

			vector<vector<double>> CrossValidationSplit(vector<vector<string>> dataset);
			pair<double, double> DatasetMinmax(vector<vector<string>> dataset);
			double accuracy_metric(vector<double> actual, vector<double> predicted);
			vector<vector<double>> KNearestNeighborsAlg(vector<vector<string>> train, vector<vector<string>> test);
		};
	}
}
