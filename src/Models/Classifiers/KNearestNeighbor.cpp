//
// Created by Dmitry on 11.09.2020.
//

#include "KNearestNeighbor.h"

template<typename DType>
void KNearestNeighbor<DType>::Fit(DType **xData, DType *yData, int dataSize, int featureCount)
{

}

template<typename DType>
DType *KNearestNeighbor<DType>::Predict(DType **predictFetchData, int dataSize, int featureCount) const
{
    return nullptr;
}

template<typename DType>
DType KNearestNeighbor<DType>::Predict(DType *predictVector, int dataSize, int featureCount) const
{
    return nullptr;
}

template<typename DType>
void KNearestNeighbor<DType>::SaveModel(std::string path)
{

}

template<typename DType>
void KNearestNeighbor<DType>::LoadModel(std::string path)
{

}