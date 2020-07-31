#include "pch.h"

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
			vector<vector<string>> GetDataAsLines() const;
			unordered_map<string, vector<string>> GetDataAsLabels() const;

// TODO ADD PRIVATE STATE HERE
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