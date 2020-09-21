#include <iostream>
#include <random>
#include <ctime>
#include "src/Models/Classifiers/KNearestNeighbor.h"
#include "src/Math/LinAlg/Matrix.h"
#include "src/Math/LinAlg/Matrix.cpp"
#include "src/FileSys/CSVReader.h"
#include "src/FileSys/CSVReader.cpp"

#define LINE std::cout << "===========================================" << std::endl;

int main()
{
    srand(time(NULL));

//    CSVReader<long> reader;
//    CSV<long> csv = reader.ReadCSVFromFile("C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\resources\\mnist_train.csv");

    Matrix<int> matrix1(2, 3);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix1.At(i, j) = rand() % 10;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix1.At(i, j) << " ";
        }
        std::cout << std::endl;
    }
    try
    {
        matrix1.Transpose();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    LINE
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cout << matrix1.At(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
