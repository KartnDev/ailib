//
// Created by Dmitry on 17.09.2020.
//

#ifndef AILIB_ACTIVATIONFUNCTIONS_H
#define AILIB_ACTIVATIONFUNCTIONS_H

#include "../LinAlg/Matrix.h"
#include <exception>
#include <cmath>
#include <algorithm>

template<class DType>
Matrix<DType> *Sigmoid(const Matrix<DType> *x, bool derivative = false)
{
    Matrix<DType> *result = Matrix<DType>::Create(x->rows, x->cols);
    if (!derivative)
    {
        for (int i = 0; i < x->rows; i++)
        {
            for (int j = 0; j < x->cols; j++)
            {
                result->At(i, j) = 1.0 / (1 + exp(-x->At(i, j)));
            }
        }
    }
    else
    {
        for (int i = 0; i < x->rows; i++)
        {
            for (int j = 0; j < x->cols; j++)
            {
                result->At(i, j) = exp(-x->At(i, j)) / (1 + exp(-x->At(i, j))) / (1 + exp(-x->At(i, j)));
            }
        }
    }

    return result;
}

template<class DType>
Matrix<DType> *SoftMax(const Matrix<DType> *x, bool derivative = false)
{
    Matrix<DType> *result = Matrix<DType>::Create(x->rows, x->cols);

    const int size = x->cols * x->rows;
    DType max = max_element(x->matrix, x->matrix + size);

    for (int i = 0; i < x->rows; i++)
    {
        for (int j = 0; j < x->cols; j++)
        {
            result->At(i, j) = exp(x->At(i, j) - max);
        }
    }

    DType sum = 0;
    for (int i = 0; i < x->rows; i++)
    {
        for (int j = 0; j < x->cols; j++)
        {
            sum += result->At(i, j);
        }
    }
    for (int i = 0; i < x->rows; i++)
    {
        for (int j = 0; j < x->cols; j++)
        {
            result->At(i, j) /= sum;
        }
    }

    if(derivative)
    {
        for (int i = 0; i < x->rows; i++)
        {
            for (int j = 0; j < x->cols; j++)
            {
                result->At(i, j)  *= 1 /
            }
        }
    }
    // TODO REFACTOR IT


    return result;
}


#endif //AILIB_ACTIVATIONFUNCTIONS_H
