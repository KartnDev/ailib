//
// Created by Dmitry on 12.09.2020.
//

#include "DistanceMethods.h"
#include <cmath>

template<class DType>
double GetMinkowskiDistance(DType *pointFirst, DType pointSecond, int pointDim, double r)
{
    double sum = 0.0;

    for (int i = 0; i < pointDim; i++)
    {
        sum += pow((pointFirst[i] - pointSecond[i]), r);
    }

    return pow(sum, 1.0 / r);
}