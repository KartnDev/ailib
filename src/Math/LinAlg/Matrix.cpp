//
// Created by Dmitry on 12.09.2020.
//

#include "Matrix.h"

template<class DType>
Matrix<DType>& MatrixMul(const Matrix<DType> &lhsMatrix, const Matrix<DType> &rhsMatrix)
{
    if(lhsMatrix.cols == rhsMatrix.rows)
    {
        Matrix<DType> mat(lhsMatrix.rows, rhsMatrix.rows);

        for (int i = 0; i < lhsMatrix.rows; i++)
        {
            for (int j = 0; j < rhsMatrix.cols; j++)
            {
                mat.matrix[i * mat.cols + j] = 0;
                for (int k = 0; k < lhsMatrix.cols; k++)
                {
                    const DType kLeft = lhsMatrix.matrix[i * lhsMatrix.cols + j];
                    const DType kRight = rhsMatrix.matrix[i * rhsMatrix.cols + j];

                    mat.matrix[i * mat.cols + j] += kLeft * kRight;
                }
            }
        }
        return mat;
    }
    throw std::runtime_error("MatMul took non equality size of matrix s");
}




template<class DType>
Matrix<DType>::Matrix(const DType *matrix, const int rows, const int cols)
{
    this->matrix = matrix;
    this->rows = rows;
    this->cols = cols;
}

template<class DType>
Matrix<DType>::Matrix(int rows, int cols)
{
    auto *alloc = (DType*)malloc(rows * cols * sizeof(DType));

    this->matrix = alloc;
    this->rows = rows;
    this->cols = cols;
}

template<class DType>
Matrix<DType>& Matrix<DType>::MatMul(const Matrix<DType> &lhsMatrix) const
{
    return MatrixMul<DType>(*this, lhsMatrix);
}

template<class DType>
void Matrix<DType>::Transpose()
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::Transpose() const
{

}

template<class DType>
void Matrix<DType>::MatAdd(const Matrix<DType> &lhsMatrix)
{

}

template<class DType>
void Matrix<DType>::MatSub(const Matrix<DType> &lhsMatrix)
{

}

template<class DType>
void Matrix<DType>::ScalarMultiply(double scalar)
{

}

template<class DType>
void Matrix<DType>::ScalarDivide(double scalar)
{

}

template<class DType>
void Matrix<DType>::Inverse()
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::Inverse() const
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::MatAdd(const Matrix<DType> &lhsMatrix) const
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::MatSub(const Matrix<DType> &lhsMatrix) const
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::ScalarMultiply(double scalar) const
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::ScalarDivide(double scalar) const
{

}

template<class DType>
double Matrix<DType>::Determinant() const
{

}

template<class DType>
void Matrix<DType>::operator*=(const Matrix<DType> &rhsMatrix)
{

}

template<class DType>
void Matrix<DType>::operator+=(const Matrix<DType> &rhsMatrix)
{

}

template<class DType>
void Matrix<DType>::operator-=(const Matrix<DType> &rhsMatrix)
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::operator+(const Matrix<DType> &rhsMatrix)
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::operator-(const Matrix<DType> &rhsMatrix)
{

}

template<class DType>
const Matrix<DType> &Matrix<DType>::operator*(const Matrix<DType> &rhsMatrix)
{

}

template<class DType>
DType &Matrix<DType>::At(int i, int j) const
{
    return this->matrix[i * cols + j];
}

template<class DType>
Matrix<DType>::~Matrix()
{

}

