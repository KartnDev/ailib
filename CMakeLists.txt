cmake_minimum_required(VERSION 3.16)
project(ailib)

include_directories("${PROJECT_SOURCE_DIR}/src/Models/Classifiers")
add_subdirectory(src)

set(CMAKE_CXX_STANDARD 20)

add_executable(ailib main.cpp)