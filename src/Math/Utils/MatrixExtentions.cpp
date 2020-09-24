//
// Created by Dmitry on 21.09.2020.
//

#include "MatrixExtentions.h"

#include <random>

#include <iostream>

template<class DType>
Matrix<DType>* RandMatrix(int rows, int cols)
{
    Matrix<DType>* result = Matrix<DType>::Create(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result->At(i, j) = rand() % 10;
        }
    }


    return result;
}