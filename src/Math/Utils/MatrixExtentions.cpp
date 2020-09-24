//
// Created by Dmitry on 21.09.2020.
//

#include "MatrixExtentions.h"

#include <random>

#include <iostream>

template<class DType>
Matrix<DType>* RandMatrix(int rows, int cols)
{
    void *allocated = malloc(sizeof(Matrix<DType>));
    Matrix<DType>* result = new(allocated) Matrix<DType>(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result->At(i, j) = rand() % 10;
        }
    }


    return result;
}