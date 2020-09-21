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
Matrix<DType>& MatrixAdd(const Matrix<DType> &lhsMatrix, const Matrix<DType> &rhsMatrix)
{
    if(lhsMatrix.cols == rhsMatrix.cols && lhsMatrix.rows == rhsMatrix.rows)
    {
        Matrix<DType> mat(lhsMatrix.rows, rhsMatrix.cols);

        for (int i = 0; i < lhsMatrix.rows; i++)
        {
            for (int j = 0; j < rhsMatrix.cols; j++)
            {
                mat.matrix[i * mat.cols + j] = lhsMatrix.At(i, j) + rhsMatrix.At(i, j);
            }
        }
        return mat;
    }
    throw std::runtime_error("MatAdd took a different sizes of matrix");
}

template<class DType>
Matrix<DType>& MatrixSub(const Matrix<DType> &lhsMatrix, const Matrix<DType> &rhsMatrix)
{
    if(lhsMatrix.cols == rhsMatrix.cols && lhsMatrix.rows == rhsMatrix.rows)
    {
        Matrix<DType> mat(lhsMatrix.rows, rhsMatrix.cols);

        for (int i = 0; i < lhsMatrix.rows; i++)
        {
            for (int j = 0; j < rhsMatrix.cols; j++)
            {
                mat.matrix[i * mat.cols + j] = lhsMatrix.At(i, j) - rhsMatrix.At(i, j);
            }
        }
        return mat;
    }
    throw std::runtime_error("MatAdd took a different sizes of matrix");
}

template<class DType>
Matrix<DType>& MatrixMultiplyScalar(const Matrix<DType> &lhsMatrix, DType scalar)
{
    Matrix<DType> mat(lhsMatrix.rows, lhsMatrix.cols);

    for (int i = 0; i < lhsMatrix.rows; i++)
    {
        for (int j = 0; j < lhsMatrix.cols; j++)
        {
            mat.matrix[i * mat.cols + j] = lhsMatrix.At(i, j) * scalar;
        }
    }
    return mat;
}

template<class DType>
Matrix<DType>& MatrixDivideScalar(const Matrix<DType> &lhsMatrix, DType scalar)
{
    Matrix<DType> mat(lhsMatrix.rows, lhsMatrix.cols);

    for (int i = 0; i < lhsMatrix.rows; i++)
    {
        for (int j = 0; j < lhsMatrix.cols; j++)
        {
            mat.matrix[i * mat.cols + j] = lhsMatrix.At(i, j) / scalar;
        }
    }
    return mat;
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
Matrix<DType>& Matrix<DType>::MatMul(const Matrix<DType> &rhsMatrix) const
{
    return MatrixMul<DType>(*this, rhsMatrix);
}

template<class DType>
void Matrix<DType>::Transpose()
{
    *this = TransposeRet();
}

template<class DType>
const Matrix<DType> &Matrix<DType>::TransposeRet() const
{
    if(cols == rows) // TODO optimize this
    {
        Matrix<DType> mat(rows, cols);
        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mat.At(i, j) = this->At(j, i);
            }
        }
        return mat;
    }
    else
    {
        Matrix<DType> mat(cols, rows);
        for(int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                mat.At(j, i) = this->At(i, j);
            }
        }
        return mat;
    }
}

template<class DType>
void Matrix<DType>::MatAdd(const Matrix<DType> &rhsMatrix)
{
     *this = MatrixAdd<DType>(*this, rhsMatrix);
}

template<class DType>
void Matrix<DType>::MatSub(const Matrix<DType> &rhsMatrix)
{
    *this = MatrixSub<DType>(*this, rhsMatrix);
}

template<class DType>
void Matrix<DType>::ScalarMultiply(DType scalar)
{
    *this = MatrixMultiplyScalar<DType>(*this, scalar);
}

template<class DType>
void Matrix<DType>::ScalarDivide(DType scalar)
{
    *this = MatrixDivideScalar<DType>(*this, scalar);
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
const Matrix<DType> &Matrix<DType>::MatAddRet(const Matrix<DType> &rhsMatrix) const
{
    return MatrixAdd<DType>(*this, rhsMatrix);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::MatSubRet(const Matrix<DType> &rhsMatrix) const
{
    return MatrixSub<DType>(*this, rhsMatrix);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::ScalarMultiplyRet(DType scalar) const
{
    return MatrixMultiplyScalar<DType>(*this, scalar);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::ScalarDivideRet(DType scalar) const
{
    return MatrixDivideScalar<DType>(*this, scalar);
}

template<class DType>
double Matrix<DType>::Determinant() const
{

}

template<class DType>
void Matrix<DType>::operator*=(const Matrix<DType> &rhsMatrix)
{
    this->MatMul(rhsMatrix);
}

template<class DType>
void Matrix<DType>::operator+=(const Matrix<DType> &rhsMatrix)
{
    this->MatAdd(rhsMatrix);
}

template<class DType>
void Matrix<DType>::operator-=(const Matrix<DType> &rhsMatrix)
{
    this->MatSub(rhsMatrix);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::operator+(const Matrix<DType> &rhsMatrix)
{
    return MatrixAdd<DType>(*this, rhsMatrix);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::operator-(const Matrix<DType> &rhsMatrix)
{
    return MatrixSub<DType>(*this, rhsMatrix);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::operator*(const Matrix<DType> &rhsMatrix)
{
    return MatrixMul<DType>(*this, rhsMatrix);
}

template<class DType>
DType &Matrix<DType>::At(int i, int j) const
{
    return this->matrix[i * cols + j];
}

template<class DType>
Matrix<DType>::~Matrix()
{
    free(matrix);
}

template<class DType>
void Matrix<DType>::operator*=(DType scalar)
{
    this->ScalarMultiply(scalar);
}

template<class DType>
void Matrix<DType>::operator/=(DType scalar)
{
    this->ScalarDivide(scalar);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::operator*(DType scalar)
{
    return ScalarMultiplyRet(scalar);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::operator/(DType scalar)
{
    return ScalarDivideRet(scalar);
}

template<class DType>
const Matrix<DType> &Matrix<DType>::PowerRet(int pow) const
{
    Matrix<DType> mat(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            mat.matrix[i * mat.cols + j] = (DType)pow(mat.matrix[i * mat.cols + j], pow);
        }
    }
    return mat;
}

template<class DType>
const Matrix<DType> &Matrix<DType>::ExpRet() const
{
    Matrix<DType> mat(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            mat.matrix[i * mat.cols + j] = (DType)exp(mat.matrix[i * mat.cols + j]);
        }
    }
    return mat;
}

template<class DType>
const Matrix<DType> &Matrix<DType>::NegativeRet() const
{
    Matrix<DType> mat(this->rows, this->cols);

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            mat.matrix[i * mat.cols + j] = - mat.matrix[i * mat.cols + j];
        }
    }
    return mat;
}

template<class DType>
const DType Matrix<DType>::Max() const
{
    return nullptr;
}

template<class DType>
const DType Matrix<DType>::Min() const
{
    return nullptr;
}

