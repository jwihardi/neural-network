cmake_minimum_required(VERSION 3.16) # idk what version to put

project(neural_network LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(nn
    nn.cpp
)
