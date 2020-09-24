#include <random>
#include <ctime>
#include "src/Models/Classifiers/NeuralNetwork.h"
#include "src/Models/Classifiers/NeuralNetwork.cpp"
#include "src/Math/LinAlg/Matrix.h"
#include "src/Math/LinAlg/Matrix.cpp"
#include "src/FileSys/CSVReader.h"
#include "src/FileSys/CSVReader.cpp"

#define LINE std::cout << "===========================================" << std::endl;

int main()
{
    srand(time(NULL));

    CSVReader<int> reader;
    CSV<int> csv = reader.ReadCSVFromFile("C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\resources\\mnist_test.csv");

    Matrix<int> xData(csv.dataSize, csv.featureCount);
    xData.matrix = csv.dataMatrix;

    std::vector<int> topology = {784, 128, 64, 10};

    NeuralNetwork<int> network(topology, 10, 0.0001);

    //network.FeedForward(xData);

    return 0;
}
