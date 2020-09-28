//
// Created by Dmitry on 17.09.2020.
//

#ifndef AILIB_ACTIVATIONFUNCTIONS_H
#define AILIB_ACTIVATIONFUNCTIONS_H

#include "../LinAlg/Matrix.h"
#include <exception>

template<class DType>
Matrix<DType>* Sigmoid(const Matrix<DType>* x, bool derivative=false)
{
    if (!derivative)
    {
        Matrix<DType>* res = x->NegativeRet();

        auto *f = res->ExpRet()->ScalarAddRet(1);

        res = res->ExpRet()->MatDivRet(f);

        return res->PowerRet(2);
    }

    return nullptr;
}

template<class DType>
Matrix<DType>* SoftMax(const Matrix<DType>* x)
{
    Matrix<DType>* exps = (x - x->Max()).ExpRet();
    return exps / Sum(exps, 0);
}

template<class DType>
DType Sum(const Matrix<DType>* x, int axis=0)
{
    throw std::bad_exception();
}


#endif //AILIB_ACTIVATIONFUNCTIONS_H
