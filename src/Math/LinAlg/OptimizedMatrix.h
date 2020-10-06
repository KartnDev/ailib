//
// Created by Dmitry on 06.10.2020.
//

#ifndef AILIB_OPTIMIZEDMATRIX_H
#define AILIB_OPTIMIZEDMATRIX_H

#define OPEN_MP_PARALLEL 1
#define STL_PARALLEL 0

#define TYPE_FX float

struct OptimizedMatrix
{
    TYPE_FX* matrix;

    int rows, cols;
    OptimizedMatrix();
    OptimizedMatrix(const TYPE_FX* matrix, int rows, int cols);
    OptimizedMatrix(int rows, int cols);

    ~OptimizedMatrix();

    static OptimizedMatrix& Create(int rows, int cols);

    OptimizedMatrix& MatMul(const OptimizedMatrix& rhsMatrix) const;


    void Transpose();
    OptimizedMatrix& TransposeRet() const;

    void Inverse();
    OptimizedMatrix& Inverse() const;

    void MatAdd(const OptimizedMatrix& rhsMatrix);
    void MatSub(const OptimizedMatrix& rhsMatrix);

    void ScalarMultiply(TYPE_FX scalar);
    void ScalarDivide(TYPE_FX scalar);
    void ScalarAdd(TYPE_FX scalar);
    void ScalarSub(TYPE_FX scalar);


    OptimizedMatrix &NegativeOnePower() const;
    OptimizedMatrix &ExpRet() const;
    OptimizedMatrix &PowerRet(int powerNum) const;
    OptimizedMatrix &NegativeRet() const;

    OptimizedMatrix& MatDivRet(const OptimizedMatrix& rhsMatrix) const;
    OptimizedMatrix& MatAddRet(const OptimizedMatrix& rhsMatrix) const;
    OptimizedMatrix& MatSubRet(const OptimizedMatrix& rhsMatrix) const;
    OptimizedMatrix& ScalarMultiplyRet(TYPE_FX scalar) const;
    OptimizedMatrix& ScalarDivideRet(TYPE_FX scalar) const;
    OptimizedMatrix* ScalarAddRet(TYPE_FX scalar) const;
    OptimizedMatrix& ScalarSubRet(TYPE_FX scalar) const;

    double Determinant() const;
    TYPE_FX Max() const;
    TYPE_FX Min() const;

    void operator*=(const OptimizedMatrix& rhsMatrix);
    void operator*=(TYPE_FX scalar);
    void operator/=(TYPE_FX scalar);
    void operator+=(const OptimizedMatrix& rhsMatrix);
    void operator-=(const OptimizedMatrix& rhsMatrix);

    TYPE_FX& At(int i, int j) const;

    OptimizedMatrix& SliceRow(int index) const;
    OptimizedMatrix& SliceRowAsCol(int index) const;

    OptimizedMatrix& operator+(const OptimizedMatrix& rhsMatrix) const;
    OptimizedMatrix& operator-(const OptimizedMatrix& rhsMatrix) const;
    OptimizedMatrix& operator*(const OptimizedMatrix& rhsMatrix) const;
    OptimizedMatrix& operator/(const OptimizedMatrix& rhsMatrix) const;

    OptimizedMatrix& operator*(TYPE_FX scalar) const;
    OptimizedMatrix& operator/(TYPE_FX scalar) const;
    OptimizedMatrix& operator+(TYPE_FX scalar) const;
    OptimizedMatrix& operator-(TYPE_FX scalar) const;
};


#endif //AILIB_OPTIMIZEDMATRIX_H
