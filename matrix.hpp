#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <random>
#include "data_loader.hpp"

struct Matrix{
    std::vector<float> data;
    int rows, cols;

    Matrix(int, int);

    Matrix multiply(const Matrix&) const;

    Matrix transpose() const;

    void add(const Matrix&);

    static Matrix init_rand_mat(int, int, std::mt19937&, float, float);

    static Matrix load_image_mat(const Dataset&, int, int);

    int argmax() const;
    
    void subtract_one_hot(int);

    void scale(float);

    void subtract_scaled(const Matrix&, float);
};

#endif
