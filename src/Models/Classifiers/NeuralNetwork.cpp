//
// Created by Dmitry on 12.09.2020.
//

#include "NeuralNetwork.h"
#include <cmath>
#include <any>
#include <bits/stl_pair.h>
#include "../../Math/Utils/MatrixExtentions.h"
#include "../../Math/Utils/MatrixExtentions.cpp"
#include "../../Math/SpecFunctions/ActivationFunctions.h"

template<class DType>
NeuralNetwork<DType>::NeuralNetwork(const std::vector<int>& topology, int epochs, double learnRate)
{
    this->topology = topology;
    this->epochs = epochs;
    this->learnRate = learnRate;

    Initialization();
}

template<class DType>
void NeuralNetwork<DType>::Fit(DType **xData, int *yData, int dataSize, int featureCount)
{

}

template<class DType>
int *NeuralNetwork<DType>::Predict(DType **predictFetchData, int predictSize) const
{
    return nullptr;
}

template<class DType>
int NeuralNetwork<DType>::Predict(DType *predictVector) const
{
    return 0;
}

template<class DType>
void NeuralNetwork<DType>::SaveModel(std::string path)
{

}

template<class DType>
void NeuralNetwork<DType>::LoadModel(std::string path)
{

}

template<class DType>
void NeuralNetwork<DType>::Initialization()
{
    int inputLayer = this->topology[0];
    int hiddenLayer1 = this->topology[1];
    int hiddenLayer2 = this->topology[2];
    int outputLayer = this->topology[3];

    std::unordered_map<std::string, Matrix<DType>*> parameters;
    Matrix<DType>* w = RandMatrix<DType>(hiddenLayer1, inputLayer);


    parameters["W1"] = w;

    w.Mat
    //parameters["W1"] *= sqrt(1 / hiddenLayer1);

    //parameters["W2"] = RandMatrix<DType>(hiddenLayer2, hiddenLayer1);
    //parameters["W2"] *= sqrt(1 / hiddenLayer2);

    //parameters["W3"] = RandMatrix<DType>(outputLayer, hiddenLayer2);
    //parameters["W3"] *= sqrt(1 / outputLayer);

}

//template<class DType>
//std::unordered_map<std::string, Matrix<DType>> &NeuralNetwork<DType>::FeedForward(Matrix<DType> &xTrain)
//{
//    std::unordered_map<std::string, Matrix<DType>> params;
//
//    params["A0"] = xTrain;
//
//    params["Z1"] = params["W1"] * params["A0"];
//    params["A1"] = Sigmoid<DType>(params["Z1"]);
//
//    params["Z2"] = params["W2"] * params["A1"];
//    params["A2"] = Sigmoid<DType>(params["Z2"]);
//
//    params["Z3"] = params["W3"] * params["A2"];
//    params["A3"] = SoftMax<DType>(params["Z3"]);
//
//    return params;
//}
//
//template<class DType>
//std::unordered_map<std::string, Matrix<DType>>
//NeuralNetwork<DType>::BackPropagation(Vector<DType> yTrain, Vector<DType> output)
//{
//    std::unordered_map<std::string, Matrix<DType>> params;
//
//    std::unordered_map<std::string, Matrix<DType>> changeW;
//
//    Matrix<DType> error = output - yTrain;
//    changeW['W3'] = error * params['A3'];
//
//    //error = np.multiply( np.dot(params['W3'].T, error), self.sigmoid(params['Z2'], derivative=True) );
//    //changeW['W2'] = np.dot(error, params['A2']);
//
//    // error = np.multiply( np.dot(params['W2'].T, error), self.sigmoid(params['Z1'], derivative=True) );
//    // changeW['W1'] = np.dot(error, params['A1']);
//}
//
//template<class DType>
//void NeuralNetwork<DType>::WeightsTraining()
//{
//
//}
