//
// Created by Dmitry on 11.09.2020.
//

#include "KNearestNeighbor.h"
#include "../../Math/Utils/DistanceMethods.h"
#include <set>
#include <vector>

template<class DType>
void KNearestNeighbor<DType>::Fit(DType **xData, int *yData, int dataSize, int featureCount)
{
    this->FetchedData = xData;
    this->FetchedLabels = yData;

    this->featureCount = featureCount;
    this->dataSize = dataSize;
}

template<class DType>
int *KNearestNeighbor<DType>::Predict(DType **predictFetchData, int predictedSize) const
{
    auto cmp = [](std::pair<int, double> a, std::pair<int, double> b) { return a.second > b.second; };

    int predicts[dataSize];

    for (int i = 0; i < predictedSize; i++)
    {
        std::set<std::pair<int, double>, decltype(cmp)> distancesIndexes;

        for (int j = 0; j < dataSize; j++)
        {
            std::pair<int, double> current;
            current.second = GetMinkowskiDistance<DType>(fetchedData[j], predictFetchData[j], featureCount);
            current.first = j;

            distancesIndexes.insert(current);
        }

        std::vector<int> nearestModels;

        for (int k = 0; k < kNearestCount; k++)
        {
            nearestModels.push_back(this->trainFetchLabel[distancesIndexes[k].first]);
        }

        predicts[i] = FindMostCommon(nearestModels);
    }

    return &predicts;
}

template<class DType>
int KNearestNeighbor<DType>::Predict(DType *predictVector) const
{
    auto cmp = [](std::pair<int, double> a, std::pair<int, double> b) { return a.second > b.second; };

    std::set<std::pair<int, double>, decltype(cmp)> distancesIndexes;

    for (int j = 0; j < dataSize; j++)
    {
        std::pair<int, double> current;
        current.second = GetMinkowskiDistance<DType>(fetchedData[j], predictVector, featureCount);
        current.first = j;

        distancesIndexes.insert(current);
    }

    std::vector<int> nearestModels;

    for (int k = 0; k < kNearestCount; k++)
    {
        nearestModels.push_back(this->trainFetchLabel[distancesIndexes[k].first]);
    }

    return this->FindMostCommon(nearestModels);
}

template<class DType>
int KNearestNeighbor<DType>::FindMostCommon(std::vector<int> value)
{

    int index = 0;
    int highest = 0;
    for (int a = 0; a < value.size(); a++)
    {
        int count = 1;
        int position = value.at(a);
        for (int n = a + 1; n < value.size(); n++)
        {
            if (value.at(n) == position)
            {
                count++;
            }
        }
        if (count >= index)
        {
            index = count;
            highest = position;
        }
    }
    return highest;
}



template<class DType>
void KNearestNeighbor<DType>::SaveModel(std::string path)
{

}

template<class DType>
void KNearestNeighbor<DType>::LoadModel(std::string path)
{

}