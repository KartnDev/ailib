#include <iostream>
#include "src/Models/Classifiers/KNearestNeighbor.h"
#include "src/Math/LinAlg/Matrix.h"
#include "src/Math/LinAlg/Matrix.cpp"
#include "src/FileSys/CSVReader.h"
#include "src/FileSys/CSVReader.cpp"
int main()
{

    CSVReader<int> reader;
    CSV<int> csv = reader.ReadCSVFromFile("C:\\Users\\Dmitry\\Documents\\GitHub\\ailib\\resources\\mnist_test.csv");




    std::cout << "Hello, World!" << std::endl;
    return 0;
}
