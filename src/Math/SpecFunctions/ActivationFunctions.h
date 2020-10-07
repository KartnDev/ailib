//
// Created by Dmitry on 17.09.2020.
//

#ifndef AILIB_ACTIVATIONFUNCTIONS_H
#define AILIB_ACTIVATIONFUNCTIONS_H

#include "../LinAlg/Matrix.h"
#include <exception>
#include <cmath>

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
Matrix<DType> *SoftMax(const Matrix<DType> *x)
{
    Matrix<DType> *result = Matrix<DType>::Create(x->rows, x->cols);

    double sum = 0;

    for (int i = 0; i < x->rows; i++)
    {
        for (int j = 0; j < x->cols; j++)
        {
            sum += exp(x->At(i, j));
        }
    }



    for (int i = 0; i < x->rows; i++)
    {
        for (int j = 0; j < x->cols; j++)
        {
            result->At(i, j) = exp(x->At(i, j)) / sum;
        }
    }

    return result;
}

template<class DType>
DType Sum(const Matrix<DType> *x, int axis = 0)
{
    throw std::bad_exception();
}


#endif //AILIB_ACTIVATIONFUNCTIONS_H
