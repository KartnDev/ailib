#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

namespace ktstd
{

	class FileUtilities
	{
	public:
		class CSV
		{
		public:
			CSV(string filename);

			int Size();
			vector<vector<string>> GetDataAsLines();
			unordered_map<string, vector<string>> GetDataAsLabels();

		private:
			void _QueryForBytes(string filename);
			int lenght;
			vector<vector<string>> linesOfData;
			unordered_map<string, vector<string>> dataAsLabels;

		};

		const char* ReadFileBinary(const char* filename);

		vector<string> SplitString(string s, char separator);

		inline bool FileExists(const string& name);

		const char* ReadFileBinary(string filename);
	};

}