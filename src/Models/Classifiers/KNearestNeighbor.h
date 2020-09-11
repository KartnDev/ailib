//
// Created by Dmitry on 11.09.2020.
//

#ifndef AILIB_KNEARESTNEIGHBOR_H
#define AILIB_KNEARESTNEIGHBOR_H


#include "IClassifier.h"
#include "IMetrix.h"

template<typename DType>
class KNearestNeighbor : public IClassifier<DType>, IMetrix
{
    void Fit(DType** xData, DType* yData, int dataSize, int featureCount) override;
    DType* Predict(DType** predictFetchData, int dataSize, int featureCount) const override;
    DType Predict(DType* predictVector, int dataSize, int featureCount) const override;
    void SaveModel(std::string path) override;
    void LoadModel(std::string path) override;
};




#endif //AILIB_KNEARESTNEIGHBOR_H
