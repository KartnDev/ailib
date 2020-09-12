cmake_minimum_required(VERSION 3.16)
project(ailib)

include_directories("src/Models/Classifiers/KNearestNeighbor.h")
include_directories("src/Models/Classifiers/KNearestNeighbor.cpp")

set(CMAKE_CXX_STANDARD 20)

add_executable(ailib
        main.cpp
        src/Models/Classifiers/KNearestNeighbor.h
        src/Models/Classifiers/KNearestNeighbor.cpp
        src/Models/Classifiers/IClassifier.h
        src/Models/Classifiers/IMetrix.h
        src/Models/Classifiers/DistanceMethods.cpp
        src/Models/Classifiers/DistanceMethods.h)

