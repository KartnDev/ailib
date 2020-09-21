//
// Created by Dmitry on 12.09.2020.
//

#include "NeuralNetwork.h"
#include <cmath>
#include "../../Math/Utils/MatrixExtentions.h"

template<class DType>
NeuralNetwork<DType>::NeuralNetwork(const std::vector<int>& topology, int epochs, double learnRate)
{
    this->topology = topology;
    this->epochs = epochs;
    this->learnRate = learnRate;

    Initialization();
}

template<class DType>
void NeuralNetwork<DType>::Initialization()
{
    int inputLayer = this->topology[0];
    int hiddenLayer1 = this->topology[1];
    int hiddenLayer2 = this->topology[2];
    int outputLayer = this->topology[3];

    std::unordered_map<std::string, Matrix<DType>> parameters;

    parameters["W1"] = RandMatrix<DType>(hiddenLayer1, inputLayer);
    parameters["W1"] *= sqrt(1 / hiddenLayer1);

    parameters["W2"] = RandMatrix<DType>(hiddenLayer2, hiddenLayer1);
    parameters["W2"] *= sqrt(1 / hiddenLayer2);

    parameters["W3"] = RandMatrix<DType>(outputLayer, hiddenLayer2);
    parameters["W3"] *= sqrt(1 / outputLayer);

}

template<class DType>
void NeuralNetwork<DType>::FeedForward(Matrix<DType>& xTrain)
{
    params["A0"] = xTrain;

    params["Z1"] = params["W1"] * params["A0"];
    params["A1"] = this->sigmoid(params["Z1"]);

    params["Z2"] = params["W2"] * params["A1"];
    params["A2"] = sigmoid(params["Z2"]);

    params["Z3"] = params["W3"] * params["A2"];
    params["A3"] = softmax(params["Z3"]);
}

template<class DType>
void NeuralNetwork<DType>::BackPropagation()
{

}

template<class DType>
void NeuralNetwork<DType>::WeightsTraining()
{

}
