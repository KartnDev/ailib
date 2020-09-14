//
// Created by Dmitry on 12.09.2020.
//

#include "Matrix.h"

template<class DType>
Matrix<DType>::Matrix(const DType *matrix, const int rows, const int cols)
{
    this->matrix = matrix;
    this->rows = rows;
    this->cols = cols;
}

template<class DType>
Matrix<DType>::Matrix(const int rows, const int cols)
{
    DType alloc[rows][cols];
    this->matrix = alloc[0];
    this->rows = rows;
    this->cols = cols;
}

template<class DType>
Matrix<DType> &Matrix<DType>::MatMul(const Matrix<DType> *lhsMatrix)
{
    return 0;
}
