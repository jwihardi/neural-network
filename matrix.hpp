#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

struct Matrix{
    std::vector<float> data;
    int rows, cols;

    Matrix(int, int);

    Matrix multiply(const Matrix&) const;

    Matrix transpose() const;

    void add(const Matrix&);

    Matrix init_rand_mat(int, int, float, float, int);
    
};

#endif
