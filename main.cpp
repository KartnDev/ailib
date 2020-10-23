#include <random>
#include <ctime>
#include "src/Models/Classifiers/NeuralNetwork.h"
#include "src/Models/Classifiers/NeuralNetwork.cpp"
#include "src/Math/LinAlg/Matrix.h"
#include "src/Math/LinAlg/Matrix.cpp"
#include "src/FileSys/CSVReader.h"
#include "src/FileSys/CSVReader.cpp"
#include <omp.h>

#define LINE std::cout << "===========================================" << std::endl;


Matrix<double>* wrapAsVector(int index, int* labelValues)
{
    Matrix<double>* result = Matrix<double>::Create(10, 1);

    for(int i = 0; i < 10; i++)
    {
        result->At(i, 0) = 0;
    }

    result->At(labelValues[index], 0) = 1;

    return result;
}


int main()
{
    int id;
#pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
        printf("%d: Hello World!\n", id);
    }

    srand(time(NULL));

    CSVReader<double> reader;
    CSV<double> csv = reader.ReadCSVFromFile("C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\resources\\mnist_test.csv");

    Matrix<double> *xData = Matrix<double>::Create(csv.dataSize, csv.featureCount);
    xData->matrix = csv.dataMatrix;


    std::vector<int> topology = {784, 128, 64, 10};
    NeuralNetwork<double> network(topology, 10, 0.0001);

    auto res = network.FeedForward(xData->SliceRowAsCol(123));

    network.WeightsTraining(xData, csv.labelValues, csv.dataSize, csv.featureCount);

    return 0;
}
