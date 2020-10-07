//
// Created by Dmitry on 12.09.2020.
//

#include "NeuralNetwork.h"
#include <cmath>
#include <any>
#include "../../Math/Utils/MatrixExtentions.h"
#include "../../Math/Utils/MatrixExtentions.cpp"
#include "../../Math/SpecFunctions/ActivationFunctions.h"
#include <ctime>
#include <chrono>

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
    auto t0 = std::chrono::high_resolution_clock::now();

    //WeightsTraining(xData, xData, dataSize, featureCount);

    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> fs = t1 - t0;
    std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(fs);
    std::cout << fs.count() << "s\n";
    std::cout << d.count() << "ms\n";
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
NeuralNetwork<DType>::BackPropagation(Matrix<DType>* yTrain,  std::unordered_map<std::string, Matrix<DType> *>& params)
{
    std::unordered_map<std::string, Matrix<DType> *> changeW;

    Matrix<DType>* error = params["A3"]->MatSubRet(yTrain);
    changeW["W3"] = error->MatMul(params["A3"]->TransposeRet());

    Matrix<DType>* z2Derivative = Sigmoid<DType>(params["Z2"], true);
    Matrix<DType>* w3Trans = parameters["W3"]->TransposeRet();

    error = w3Trans->MatMul(error);
    error = error->MatMul(z2Derivative);
    changeW["W2"] = error->MatMul(params["A2"]);


    Matrix<DType>* z1Derivative = Sigmoid<DType>(params["Z1"], true);
    Matrix<DType>* w2Trans = parameters["W2"]->TransposeRet();

    error = w2Trans->MatMul(error);
    error = error->MatMul(z1Derivative);
    changeW["W1"] = error->MatMul(params["A1"]);

    return changeW;
}

Matrix<double>* WrapAsVector(int index, int* labelValues)
{
    Matrix<double>* result = Matrix<double>::Create(10, 1);

    for(int i = 0; i < 10; i++)
    {
        result->At(i, 0) = 0;
    }

    result->At(labelValues[index], 0) = 1;

    return result;
}


template<class DType>
void NeuralNetwork<DType>::WeightsTraining(Matrix<DType>* xData, int *yData, int dataSize, int featureCount)
{
    auto t0 = std::chrono::high_resolution_clock::now();

    for (int epoch = 0; epoch < this->epochs; epoch++)
    {
        for (int i = 0; i < dataSize; i++)
        {
            auto output = FeedForward(xData->SliceRowAsCol(i));
            auto changesW = BackPropagation(WrapAsVector(i, yData), output);
            UpdateNetworkParameters(changesW);
        }
        auto accuracy = ComputeAccuracy(xData, yData, dataSize, featureCount);

        auto t1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> fs = t1 - t0;
        std::chrono::milliseconds d = std::chrono::duration_cast<std::chrono::milliseconds>(fs);

        std::cout << "Epoch " << epoch + 1 << " Time spent: " <<  d.count() << " Accuracy: " << accuracy << std::endl;
    }
}

template<class DType>
void NeuralNetwork<DType>::UpdateNetworkParameters(std::unordered_map<std::string, Matrix<DType>*>& changesW)
{
    for (std::pair<std::string, Matrix<DType>*> wCoef : changesW)
    {
        for (Matrix<DType>* arr : this->parameters[wCoef.first])
        {
            arr -= this->learnRate * wCoef.second;
        }
    }

}

template<class DType>
int ArgMax(Matrix<DType> * output)
{
    int maxIndex = 0;

    DType maxVal = output->At(0, 0);

    for (int i = 0; i < output->rows * output->cols; i++)
    {
        if(output->matrix[i] > maxVal)
        {
            maxVal = output->matrix[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}


template<class DType>
double NeuralNetwork<DType>::ComputeAccuracy(const Matrix<DType> *xData, const int *yData, int dataSize, int featureCount)
{
    int rightPredicts = 0;

    for (int i = 0; i < dataSize; i++)
    {
        auto output = FeedForward(xData->SliceRowAsCol(i));
        auto pred = ArgMax(output);
        if(pred == yData[i])
        {
            rightPredicts++;
        }
    }
    return (double)rightPredicts / dataSize;
}




