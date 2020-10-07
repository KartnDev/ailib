//
// Created by Dmitry on 12.09.2020.
//

#ifndef AILIB_NEURALNETWORK_H
#define AILIB_NEURALNETWORK_H
#include <vector>
#include <string>
#include <unordered_map>
#include "IClassifier.h"
#include "../../Math/LinAlg/Matrix.h"
#include "../../Math/LinAlg/Vector.h"

template<class DType>
class NeuralNetwork : IClassifier<DType>
{
public:
    explicit NeuralNetwork(const std::vector<int>& topology, int epochs=10, double learnRate=0.001);
    void Fit(DType** xData, int* yData, int dataSize, int featureCount) override;
    int* Predict(DType** predictFetchData, int predictSize) const override;
    int Predict(DType* predictVector) const override;
    void SaveModel(std::string path) override;
    void LoadModel(std::string path) override;

    void Initialization();
    std::unordered_map<std::string, Matrix<DType>*> FeedForward(Matrix<DType>* xTrain);

    std::unordered_map<std::string, Matrix<DType>*> BackPropagation(
            Matrix<DType>* yTrain,
            std::unordered_map<std::string, Matrix<DType> *>& params);

    void WeightsTraining();

    std::vector<int> topology;
    int epochs;
    double learnRate;
    std::unordered_map<std::string, Matrix<DType>*> parameters;
};



#endif //AILIB_NEURALNETWORK_H
