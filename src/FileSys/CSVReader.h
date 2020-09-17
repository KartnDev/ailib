//
// Created by Dmitry on 12.09.2020.
//

#pragma ide diagnostic ignored "OCInconsistentNamingInspection"
#ifndef AILIB_CSVREADER_H
#define AILIB_CSVREADER_H

#include <string>
#include <vector>
#include "CSV.h"




template<class DType>
class CSVReader
{
public:
    CSV<DType> ReadCSVFromFile(std::string path);
    void SetLabelIndex(int labelIndex);
private:
    void SetLength(std::string &firstLine, CSV<DType> & csv);
    void SetDataSize(std::vector<std::string> &dataMatrix, CSV<DType> & csv);
    void SetFeatureNames(std::string &names, CSV<DType> &csv);
    void SetDataMatrix(std::vector<std::string> &dataStingMatrix, CSV<DType> & csv);

    int labelIndex = 0;
};


#endif //AILIB_CSVREADER_H

