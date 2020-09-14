//
// Created by Dmitry on 12.09.2020.
//
#include "CSV.h"
#include "CSVReader.h"
#include <filesystem>
#include <fstream>
#include <vector>
#include <exception>


std::vector<std::string> SplitString(std::string s, char separator)
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

const char* ReadFileBinary(std::string filename)
{
    return ReadFileBinary(filename.c_str());
}

inline bool FileExists(const std::string & name)
{
    return std::filesystem::exists(name);;
}

const char* ReadFileBinary(const char * filename)
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

        throw std::exception(msg.c_str());
    }
}

template<class DType>
CSV<DType>& CSVReader<DType>::ReadCSVFromFile(std::string path)
{
    std::string matrixString = SplitString(path);
    vector<std::string> vectorOfLines = file.SplitString(queryBytes, '\n');

    SetDataSize(vectorOfLines);
    SetLength(vectorOfLines[0]);
    SetFeatureNames(vectorOfLines[0]);
    SetDataMatrix(vectorOfLines);

    return &finalProduct;
}

template<class DType>
void CSVReader<DType>::SetLength(std::string& firstLine)
{
    vector<std::string> vectorOfNames = SplitString(queryBytes, ' ');
    this->finalProduct.featureCount = vectorOfNames.size();
}

template<class DType>
void CSVReader<DType>::SetFeatureNames(std::string& names)
{
    std::vector<std::string> vectorOfNames = SplitString(queryBytes, ' ');
    std::string* featureNames = &vectorOfNames[0];
    this->finalProduct.featureNames = featureNames;
}

template<class DType>
void CSVReader<DType>::SetDataSize(std::vector<std::string>& dataMatrix)
{
    this->finalProduct.dataSize = dataMatrix.size();
}

template<class DType>
void CSVReader<DType>::SetDataMatrix(std::vector<std::string> &dataStingMatrix)
{
    DType dataMatrix[const_cast<int>(dataSize)][const_cast<int>(featureCount)];

    for (int i = 1; i < dataStingMatrix.size(); i++)
    {
        std::vector<std::string> vectorOfCells = SplitString(queryBytes, ' ');
        for (int j = 0; j < vectorOfCells.size(); j++)
        {
            if(j != this->labelIndex)
            {
                dataMatrix[i][j] = dynamic_cast<DType>(std::stold(vectorOfCells[j]));
            }
            else
            {
                labelValues[i] = dynamic_cast<DType>(std::stold(vectorOfCells[j]));
            }
        }
    }
    this->finalProduct.dataMatrix = &dataMatrix;
}

template<class DType>
CSVReader<DType>::CSVReader(int labelIndex = 0)
{
    this->labelIndex = labelIndex;
}

template<class DType>
CSVReader<DType>::CSVReader()
{
    // No impl, just def constructor Created
}
