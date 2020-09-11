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
   virtual void Fit(DType** xData, DType* yData, int dataSize, int featureCount);
   virtual void Predict(DType** predictFetchData, int dataSize, int featureCount);
   virtual void Predict(DType* predictVector, int dataSize, int featureCount);
   virtual void SetMetrixOutputSettings(std::map<std::string, std::string> params);

};


#endif //AILIB_ICLASSIFIER_H
