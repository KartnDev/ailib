//
// Created by Dmitry on 12.09.2020.
//
#include "CSV.h"
#include "CSVReader.h"
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





const char* ReadFileBinaryStr(const char * filename)
{
    if (true)
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
        std::string unexistedFile = filename;
        msg = msg + unexistedFile;

        throw std::runtime_error(msg);
    }
}

const char* ReadFileBinary(std::string filename)
{
    return ReadFileBinaryStr(filename.c_str());
}

template<class DType>
CSV<DType>& CSVReader<DType>::ReadCSVFromFile(std::string path)
{
    std::string matrixString = ReadFileBinary(path);
    std::vector<std::string> vectorOfLines = SplitString(matrixString, '\n');

    SetDataSize(vectorOfLines);
    SetLength(vectorOfLines[0]);
    SetFeatureNames(vectorOfLines[0]);
    SetDataMatrix(vectorOfLines);

    return finalProduct;
}

template<class DType>
void CSVReader<DType>::SetLength(std::string& firstLine)
{
    std::vector<std::string> vectorOfNames = SplitString(firstLine, ' ');
    this->finalProduct.featureCount = vectorOfNames.size();
}

template<class DType>
void CSVReader<DType>::SetFeatureNames(std::string& names)
{
    std::vector<std::string> vectorOfNames = SplitString(names, ' ');
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
    DType dataMatrix[finalProduct.dataSize][finalProduct.featureCount];

    int alloc[finalProduct.featureCount];

    finalProduct.labelValues = &alloc[0];

    for (int i = 1; i < dataStingMatrix.size(); i++)
    {
        std::vector<std::string> vectorOfCells = SplitString(dataStingMatrix[i], ' ');
        for (int j = 0; j < vectorOfCells.size(); j++)
        {
            if(j != this->labelIndex)
            {
                dataMatrix[i][j] = (unsigned char)(std::stoi(vectorOfCells[j]));
            }
            else
            {
                finalProduct.labelValues[i] = (unsigned char)(std::stoi(vectorOfCells[j]));
            }
        }
    }
    *this->finalProduct.dataMatrix = dataMatrix[0];
}

template<class DType>
void CSVReader<DType>::SetLabelIndex(int labelIndex)
{
    this->labelIndex = labelIndex;
}



