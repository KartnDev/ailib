//
// Created by Dmitry on 12.09.2020.
//

#ifndef AILIB_CSV_H
#define AILIB_CSV_H

#include <string>

template <class DType>
struct CSV
{
    std::string* featureNames;
    DType* dataMatrix;
    int* labelValues;

    int dataSize;
    int featureCount;
};


#endif //AILIB_CSV_H
