cmake_minimum_required(VERSION 3.16) # idk what version to put

project(neural_network LANGUAGES CXX)


add_executable(neural_network
    neural_network.cpp
    matrix.cpp
)

target_compile_features(neural_network PRIVATE cxx_std_20)
target_compile_options(neural_network PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Wconversion
    -Wshadow
    -Wnull-dereference
    -Wdouble-promotion
    -Wformat=2

    -O2
    -pipe
    -march=native
)

