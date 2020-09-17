#include <iostream>
#include "src/Models/Classifiers/KNearestNeighbor.h"
#include "src/Math/LinAlg/Matrix.h"
#include "src/Math/LinAlg/Matrix.cpp"
#include "src/FileSys/CSVReader.h"
#include "src/FileSys/CSVReader.cpp"
int main()
{

//    CSVReader<long> reader;
//    CSV<long> csv = reader.ReadCSVFromFile("C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\resources\\mnist_train.csv");

    Matrix<int> matrix1(3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix1.At(i, j) = i + j + 1;
        }
    }
    Matrix<int> matrix2(3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix2.At(i, j) = 10 - i - j;
        }
    }

    auto matrix = matrix1.MatMul(matrix2);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix.At(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
