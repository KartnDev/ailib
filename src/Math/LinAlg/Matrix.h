//
// Created by Dmitry on 12.09.2020.
//

#ifndef AILIB_MATRIX_H
#define AILIB_MATRIX_H

template<class DType>
struct Matrix
{
    DType* matrix;

    int rows, cols;

    Matrix(const DType* matrix, int rows, int cols);
    Matrix(int rows, int cols);

    ~Matrix();

    Matrix<DType>& MatMul(const Matrix<DType>& rhsMatrix) const;

    void Transpose();
    const Matrix<DType>& Transpose() const;

    void Inverse();
    const Matrix<DType>& Inverse() const;

    void MatAdd(const Matrix<DType>& rhsMatrix);
    void MatSub(const Matrix<DType>& rhsMatrix);
    void ScalarMultiply(double scalar);

    void ScalarDivide(double scalar);

    const Matrix<DType>& MatAdd(const Matrix<DType>& rhsMatrix) const;
    const Matrix<DType>& MatSub(const Matrix<DType>& rhsMatrix) const;
    const Matrix<DType>& ScalarMultiply(double scalar) const;
    const Matrix<DType>& ScalarDivide(double scalar) const;

    double Determinant() const;

    void operator*=(const Matrix<DType>& rhsMatrix);
    void operator+=(const Matrix<DType>& rhsMatrix);
    void operator-=(const Matrix<DType>& rhsMatrix);

    DType& At(int i, int j);

    const Matrix<DType>& operator+(const Matrix<DType>& rhsMatrix);
    const Matrix<DType>& operator-(const Matrix<DType>& rhsMatrix);
    const Matrix<DType>& operator*(const Matrix<DType>& rhsMatrix);

};




#endif //AILIB_MATRIX_H
