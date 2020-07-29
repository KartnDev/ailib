#include "file_utilities.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <exception>

namespace ktstd
{
	FileUtilities::CSV::CSV(string filename)
	{
		this->_QueryForBytes(filename);
	}

	int FileUtilities::CSV::Size()
	{
		return this->lenght;
	}

	vector<vector<string>> FileUtilities::CSV::GetDataAsLines()
	{
		return this->linesOfData;
	}
	unordered_map<string, vector<string>> FileUtilities::CSV::GetDataAsLabels()
	{
		return this->dataAsLabels;
	}
 

	void FileUtilities::CSV::_QueryForBytes(string filename)
	{
		FileUtilities file;
		string queryBytes = file.ReadFileBinary(filename.c_str());

		vector<string> vectorOfLines = file.SplitString(queryBytes, '\n');

		this->lenght = vectorOfLines.size();

		int zeroSize = file.SplitString(vectorOfLines[0], ',').size();

		for (size_t i = 0; i < vectorOfLines.size(); i++)
		{
			vector<string> currentSplittedLine = file.SplitString(vectorOfLines[i], ',');

			if (zeroSize == currentSplittedLine.size())
			{
				this->linesOfData.push_back(currentSplittedLine); //squareful matrix
			}
		}

		for (size_t i = 0; i < this->linesOfData[0].size(); i++)
		{

			vector<string> columnAtIndex;
			for (int col_index = 0; col_index < this->linesOfData.size(); col_index++)
			{
				columnAtIndex.push_back(linesOfData[col_index][i]);
			}

			string a = linesOfData[0][i];

			this->dataAsLabels.insert({ a, columnAtIndex });
		}
	}

	std::vector<std::string> FileUtilities::SplitString(std::string s, char separator) 
	{
		std::string temp = "";

		std::vector<std::string> result;

		for (int i = 0; i < s.length(); ++i) 
		{
			if (s[i] == separator) 
			{
				result.push_back(temp);
				temp = "";
			}
			else 
			{
				temp.push_back(s[i]);
			}
		}
		result.push_back(temp);

		return result;
	}

	inline bool FileUtilities::FileExists(const std::string & name)
	{
		return std::filesystem::exists(name);
	}

	const char * FileUtilities::ReadFileBinary(std::string filename)
	{
		return ReadFileBinary(filename.c_str());
	}

	const char * FileUtilities::ReadFileBinary(const char * filename)
	{
		if (FileExists(filename))
		{
			std::ifstream infile(filename);

			//get length of file
			infile.seekg(0, infile.end);
			size_t length = infile.tellg();
			infile.seekg(0, infile.beg);

			//read file
			char *arr = new char[length]; // TODO no allocation here 

			if (length > 0)
			{
				infile.read(arr, length);
			}
			infile.close();

			return arr;

		}
		else
		{
			std::string msg = "file not exists";
			std::string unexisted_file = filename;
			msg = msg + unexisted_file;

			throw new std::exception(msg.c_str());
		}
	}
}