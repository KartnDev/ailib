#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <omp.h>

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

		public:
			void _QueryForBytes(string filename);
			int lenght;
			vector<vector<string>> linesOfData;
			unordered_map<string, vector<string>> dataAsLabels;

		};

		const char* ReadFileBinary(const char* filename);

		vector<string> SplitString(string s, char separator);

		const char* ReadFileBinary(string filename);
	};

}

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

	const char * FileUtilities::ReadFileBinary(std::string filename)
	{
		return ReadFileBinary(filename.c_str());
	}

	const char * FileUtilities::ReadFileBinary(const char * filename)
	{
		if (1)
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
double StdEuclideanDist(std::vector<string> point1, std::vector<string> point2)
{
	if (point1.size() == point2.size())
	{
		double sum = 0;
		for (size_t i = 0; i < point1.size(); i++)
		{
			sum += (stod(point1[i]) - stod(point2[i])) * (stod(point1[i]) - stod(point2[i])); //  (p-q)^2
		}

		return sqrt(sum);
	}
	else
	{
		throw new std::exception("pointsof the distanse in different dimentions!");
	}
}

double GetMinkowskiDistance(std::vector<string> point1, std::vector<string> point2, double r) {
	double sum = 0.0;


	for (int i = 0; i < point1.size(); i++) {
		sum += pow(stod(point1[i]) - stod(point2[i]), r);
	}
	
	return pow(sum, 1.0 / r);
}



int FindMode(vector<int> value)
{
	int index = 0;
	int highest = 0;
	for (unsigned int a = 0; a < value.size(); a++)
	{
		int count = 1;
		int Position = value.at(a);
		for (unsigned int b = a + 1; b < value.size(); b++)
		{
			if (value.at(b) == Position)
			{
				count++;
			}
		}
		if (count >= index)
		{
			index = count;
			highest = Position;
		}
	}
	return highest;
}


int all = 0;
int right_t = 0;




int main(int argc, char **argv) {

	ktstd::FileUtilities::CSV csvTest("C:\\Users\\Dmitry\\source\\repos\\ailib\\ailib\\mnist_test.csv");

	ktstd::FileUtilities::CSV csvTrain("C:\\Users\\Dmitry\\source\\repos\\ailib\\ailib\\mnist_train.csv");

	
#pragma omp parallel for
	for (int i = 1; i < csvTest.linesOfData.size() - 10; i++)
	{
		vector<pair<int, double>> result;

		vector<string> vectAtIndex = csvTest.linesOfData[i];
		string valueTheIndex = vectAtIndex.at(0);
		vectAtIndex.erase(vectAtIndex.begin());


		double dist;

		for (int i = 1; i < csvTrain.linesOfData.size() / 10; i++)
		{
			vector<string> current = csvTrain.linesOfData[i];
			current.erase(current.begin());


			dist = GetMinkowskiDistance(vectAtIndex, current, 20);

			pair<int, double> current_p(i, dist);
			result.push_back(current_p);

		}

		std::sort(result.begin(), result.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right) {
			return left.second < right.second;
		});

		vector<int> probs;
		for (size_t i = 0; i < 3; i++)
		{
			probs.push_back(stoi(csvTrain.linesOfData[result[i].first][0]));
		}

		int res = FindMode(probs);

		cout << "KNN answer is: " << res << " || real is " << valueTheIndex << endl;

		if (res == stoi(valueTheIndex))
		{
			right_t++;
		}
		all++;
		cout << "right: " << right_t << " || all " << all << endl;
	}
	cout << "+++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "accuracy: " << (double)(right_t / all) << "\n";



	system("pause");

}