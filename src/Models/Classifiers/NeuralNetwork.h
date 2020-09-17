//
// Created by Dmitry on 12.09.2020.
//

#ifndef AILIB_NEURALNETWORK_H
#define AILIB_NEURALNETWORK_H
#include <vector>

#include "IClassifier.h"

template<class DType>
class NeuralNetwork : IClassifier<DType>
{
public:
    NeuralNetwork(std::vector<int> layersNeuronCount);
    void Fit(DType** xData, int* yData, int dataSize, int featureCount) override;
    int* Predict(DType** predictFetchData, int predictSize) const override;
    int Predict(DType* predictVector) const override;
    void SaveModel(std::string path) override;
    void LoadModel(std::string path) override;
private:
    void Initialization();
    void FeedForward();
    void BackPropagation();
    void WeightsTraining();
};


#endif //AILIB_NEURALNETWORK_H
