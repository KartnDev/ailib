//
// Created by Dmitry on 12.09.2020.
//

#include "NeuralNetwork.h"
#include <cmath>
#include <any>
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



    parameters["W1"] = RandMatrix<DType>(hiddenLayer1, inputLayer);
    parameters["W1"]->ScalarMultiply(sqrt(1.0 / hiddenLayer1));

    parameters["W2"] = RandMatrix<DType>(hiddenLayer2, hiddenLayer1);
    parameters["W2"]->ScalarMultiply(sqrt(1.0 / hiddenLayer2));

    parameters["W3"] = RandMatrix<DType>(outputLayer, hiddenLayer2);
    parameters["W3"]->ScalarMultiply(sqrt(1.0 / outputLayer));



}

template<class DType>
std::unordered_map<std::string, Matrix<DType>*> NeuralNetwork<DType>::FeedForward(Matrix<DType> *xTrain)
{
    if(xTrain->cols != 1)
    {
        //throw std::invalid_argument("Bad vector size");
    }

    std::unordered_map<std::string, Matrix<DType> *> params;

    params["A0"] = xTrain;

    params["Z1"] = parameters["W1"]->MatMul(params["A0"]);
    params["A1"] = Sigmoid<DType>(params["Z1"]);

    params["Z2"] = parameters["W2"]->MatMul(params["A1"]);
    params["A2"] = Sigmoid<DType>(params["Z2"]);

    params["Z3"] = parameters["W3"]->MatMul(params["A2"]);
    params["A3"] = SoftMax<DType>(params["Z3"]);

    return params;
}

template<class DType>
std::unordered_map<std::string, Matrix<DType> *>
NeuralNetwork<DType>::BackPropagation(Matrix<DType>* yTrain,  std::unordered_map<std::string, Matrix<DType> *> params)
{
    std::unordered_map<std::string, Matrix<DType> *> changeW;

    Matrix<DType>* error = params["A3"]->MatSubRet(yTrain);
    changeW["W3"] = error->MatMul(params["A3"]->TransposeRet());

    //Matrix<DType>* Z2Derivided = Sigmoid<DType>(params["Z2"], true);
//    Matrix<DType>* w3trans = parameters["W3"]->TransposeRet();


    //error = w3trans->MatMul(error);
    //error = error->MatMul(Z2Derivided);
    //changeW["W2"] = error->MatMul(params["A2"]);

//    for (int i = 0; i < Z2Derivided->cols; i++)
//    {
//        for(int j = 0; j < Z2Derivided->rows; j++)
//        {
//            std::cout << w3trans->At(i, j) << std::endl;
//        }
//    }


//    error =  params["W2"].TransposeRet()->MatMul(error)->MatMul(Sigmoid<DType>(params["Z1"], true));
//    changeW["W1"] = error->MatMul(params["A1"]);

    return changeW;
}


