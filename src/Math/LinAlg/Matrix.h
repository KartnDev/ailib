//
// Created by Dmitry on 12.09.2020.
//

#ifndef AILIB_MATRIX_H
#define AILIB_MATRIX_H

#include "Vector.h"

template<class DType>
struct Matrix
{
    DType* matrix;

    int rows, cols;
    Matrix<DType>();
    Matrix(const DType* matrix, int rows, int cols);
    Matrix(int rows, int cols);

    ~Matrix();

    static Matrix<DType>* Create(int rows, int cols);

    Matrix<DType>* MatMul(const Matrix<DType>* rhsMatrix) const;


    void Transpose();
    Matrix<DType>* TransposeRet() const;

    void Inverse();
    Matrix<DType>& Inverse() const;

    void MatAdd(const Matrix<DType>& rhsMatrix);
    void MatSub(const Matrix<DType> *rhsMatrix);

    void ScalarMultiply(DType scalar);
    void ScalarDivide(DType scalar);
    void ScalarAdd(DType scalar);
    void ScalarSub(DType scalar);


    Matrix<DType> *NegativeOnePower() const;
    Matrix<DType> *ExpRet() const;
    Matrix<DType> *PowerRet(int powerNum) const;
    Matrix<DType> *NegativeRet() const;

    Matrix<DType>* MatDivRet(const Matrix<DType> *rhsMatrix) const;
    Matrix<DType>& MatAddRet(const Matrix<DType>& rhsMatrix) const;
    Matrix<DType> * MatSubRet(const Matrix<DType> *rhsMatrix) const;
    Matrix<DType>* ScalarMultiplyRet(DType scalar) const;
    Matrix<DType>& ScalarDivideRet(DType scalar) const;
    Matrix<DType>* ScalarAddRet(DType scalar) const;
    Matrix<DType>& ScalarSubRet(DType scalar) const;

    double Determinant() const;
    DType Max() const;
    DType Min() const;

    void operator*=(const Matrix<DType>& rhsMatrix);
    void operator*=(DType scalar);
    void operator/=(DType scalar);
    void operator+=(const Matrix<DType>& rhsMatrix);
    void operator-=(const Matrix<DType>* rhsMatrix);

    DType& At(int i, int j) const;

    Matrix<DType>* SliceRow(int index) const;
    Matrix<DType>* SliceRowAsCol(int index) const;

    Matrix<DType>& operator+(const Matrix<DType>& rhsMatrix) const;
    Matrix<DType>* operator-(const Matrix<DType>* rhsMatrix) const;
    Matrix<DType>& operator*(const Matrix<DType>& rhsMatrix) const;
    Matrix<DType>& operator/(const Matrix<DType>& rhsMatrix) const;

    Matrix<DType>& operator*(DType scalar) const;
    Matrix<DType>& operator/(DType scalar) const;
    Matrix<DType>* operator+(DType scalar) const;
    Matrix<DType>& operator-(DType scalar) const;
};




#endif //AILIB_MATRIX_H
