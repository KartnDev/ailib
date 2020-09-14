//
// Created by Dmitry on 12.09.2020.
//

#ifndef AILIB_CSVREADER_H
#define AILIB_CSVREADER_H

#include <string>
#include <vector>
#include "CSV.h"




template<class DType>
class CSVReader
{
    CSVReader(int labelIndex = 0);
    CSV<DType>& ReadCSVFromFile(std::string path);

private:
    void SetLength(std::string& firstLine);
    void SetDataSize(std::vector<std::string>& dataMatrix);
    void SetFeatureNames(std::string& names);
    void SetDataMatrix(std::vector<std::string>& dataStingMatrix);

    int labelIndex = 0;

    CSV<DType> finalProduct;
};


#endif //AILIB_CSVREADER_H
