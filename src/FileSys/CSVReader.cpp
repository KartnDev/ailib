//
// Created by Dmitry on 12.09.2020.
//
#include "CSV.h"
#include "CSVReader.h"
#include <fstream>
#include <vector>
#include <exception>
#include <iostream>
#include <cstdio>

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

    }
}

const char* ReadFileBinary(std::string filename)
{
    return ReadFileBinaryStr(filename.c_str());
}

template<class DType>
CSV<DType> CSVReader<DType>::ReadCSVFromFile(std::string path)
{
    CSV<DType> result;

    std::string matrixString = ReadFileBinary(path);
    std::vector<std::string> vectorOfLines = SplitString(matrixString, '\n');

    SetDataSize(vectorOfLines, result);
    SetLength(vectorOfLines[0], result);
    SetFeatureNames(vectorOfLines[0], result);
    SetDataMatrix(vectorOfLines, result);

    return result;
}

template<class DType>
void CSVReader<DType>::SetLength(std::string &firstLine, CSV<DType> & csv)
{
    std::vector<std::string> vectorOfNames = SplitString(firstLine, ',');
    csv.featureCount = vectorOfNames.size() - 1;
}

template<class DType>
void CSVReader<DType>::SetFeatureNames(std::string &names, CSV<DType> & csv)
{
    std::vector<std::string> vectorOfNames = SplitString(names, ',');
    csv.featureNames = &vectorOfNames[0];
}

template<class DType>
void CSVReader<DType>::SetDataSize(std::vector<std::string> &dataMatrix, CSV<DType> & csv)
{
    csv.dataSize = dataMatrix.size() - 1;
}

template<class DType>
void CSVReader<DType>::SetDataMatrix(std::vector<std::string> &dataStingMatrix, CSV<DType> & csv)
{
    DType* dataMatrix = (DType*)malloc(csv.dataSize * csv.featureCount * sizeof(DType));

    int* labels = (int*)malloc(csv.dataSize * sizeof(int));

    for (int i = 0; i < csv.dataSize; i++)
    {
        std::vector<std::string> vectorOfCells = SplitString(dataStingMatrix[i + 1], ',');

        for (int j = 0; j < csv.featureCount - 1; j++)
        {
            if(csv.featureCount ==  vectorOfCells.size())
            {
                if (j != this->labelIndex)
                {
                    dataMatrix[i*csv.featureCount +j] = (DType) (std::stoi(vectorOfCells[j]));;
                }
                else
                {
                    labels[i] = (int) (std::stoi(vectorOfCells[j]));
                }
            }
        }
    }


    csv.labelValues = labels;
    csv.dataMatrix = dataMatrix;
}

template<class DType>
void CSVReader<DType>::SetLabelIndex(int labelIndex)
{
    this->labelIndex = labelIndex;
}



