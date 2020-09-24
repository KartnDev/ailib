//
// Created by Dmitry on 21.09.2020.
//

#include "MatrixExtentions.h"

#include <random>

#include <iostream>

template<class DType>
Matrix<DType>& RandMatrix(int rows, int cols)
{
    Matrix<DType> result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.At(i, j) = rand() % 100;
        }
    }


    return result;
}