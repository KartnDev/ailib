//
// Created by Dmitry on 11.09.2020.
//

#ifndef AILIB_KNEARESTNEIGHBOR_H
#define AILIB_KNEARESTNEIGHBOR_H


#include "IClassifier.h"
#include "IMetrix.h"
#include <vector>

template<class DType>
class KNearestNeighbor : public IClassifier<DType>, IMetrix
{
public:
    void Fit(DType** xData, int* yData, int dataSize, int featureCount) override;
    int* Predict(DType** predictFetchData, int predictSize) const override;
    int Predict(DType* predictVector) const override;
    void SaveModel(std::string path) override;
    void LoadModel(std::string path) override;

private:
    int FindMostCommon(std::vector<int> value);

private:
    int kNearestCount;

    DType** fetchedData;
    int* fetchedLabels;

    int featureCount;
    int dataSize;

    double accuracy = -1.0;
    double loss = -1.0;
};




#endif //AILIB_KNEARESTNEIGHBOR_H
