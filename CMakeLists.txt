cmake_minimum_required(VERSION 3.16)
project(ailib CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(ailib main.cu)

set_target_properties(
        ailib
        PROPERTIES
        CUDA_SEPARABLE_COMPILATION ON)