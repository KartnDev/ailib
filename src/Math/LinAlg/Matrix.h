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

    Matrix(const DType* matrix, const int rows, const int cols);
    Matrix(const int rows, const int cols);

    Matrix<DType>& MatMul(const Matrix<DType>& lhsMatrix);

    void Transpose();
    const Matrix<DType>& Transpose() const;

    void MatAdd(const Matrix<DType>& lhsMatrix);
    void MatSub(const Matrix<DType>& lhsMatrix);
    void ScalarMultiply(double scalar);
    void ScalarDivide(double scalar);


};




#endif //AILIB_MATRIX_H
