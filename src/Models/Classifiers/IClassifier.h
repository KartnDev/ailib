//
// Created by Dmitry on 11.09.2020.
//

#ifndef AILIB_ICLASSIFIER_H
#define AILIB_ICLASSIFIER_H

#include <map>
#include <string>

template<class DType>
class IClassifier
{
public:
   virtual void Fit(DType** xData, DType* yData, int dataSize, int featureCount) = 0;
   virtual DType* Predict(DType** predictFetchData, int dataSize, int featureCount) const = 0;
   virtual DType Predict(DType* predictVector, int dataSize, int featureCount) const = 0;
   virtual void SaveModel(std::string path) = 0;
   virtual void LoadModel(std::string path) = 0;
};


#endif //AILIB_ICLASSIFIER_H
