cmake_minimum_required(VERSION 3.16) # idk what version to put

project(neural_network LANGUAGES CXX)


add_executable(nn
    nn.cpp
    matrix.cpp
)

target_compile_features(nn PRIVATE cxx_std_20)
target_compile_options(nn PRIVATE
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

