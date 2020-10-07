cmake_minimum_required(VERSION 3.16)
project(ailib)

include_directories("src/Models/Classifiers/KNearestNeighbor.h")
include_directories("src/Models/Classifiers/KNearestNeighbor.cpp")

set(CMAKE_CXX_STANDARD 20)

set(GCC_COVERAGE_COMPILE_FLAGS "-fpermissive -fexceptions")


add_executable(ailib
        main.cpp
        src/Models/Classifiers/KNearestNeighbor.h
        src/Models/Classifiers/KNearestNeighbor.cpp
        src/Models/Classifiers/IClassifier.h
        src/Models/Classifiers/IMetrix.h
        src/Math/Utils/DistanceMethods.cpp
        src/Math/Utils/DistanceMethods.h)

