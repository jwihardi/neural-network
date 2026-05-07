#include <stdexcept>
#include <random>
#include "matrix.hpp"

Matrix::Matrix(int rows_, int cols_) : data(rows_ * cols_) ,rows(rows_), cols(cols_) {}
    
Matrix Matrix::multiply(const Matrix& other) const{
    if(cols != other.rows) 
        throw std::runtime_error("Invalid dimensions for matrix multiplication");

    Matrix res(rows, other.cols);

    for(int i = 0; i < rows; i++){
        for(int u = 0; u < other.cols; u++){
            float sum = 0.0f;
            for(int k = 0; k < cols; k++)
                sum += data[i * cols + k] * other.data[k * other.cols + u];
            res.data[i * res.cols + u] = sum;
        }
    }
    return res;
}

Matrix Matrix::transpose() const{
    Matrix res(cols, rows);

    for(int i = 0; i < rows; i++){
        for(int u = 0; u < cols; u++){
            res.data[u * res.cols + i] = data[i * cols + u];
        }
    }
    return res;
}

void Matrix::add(const Matrix& other){
    if(rows != other.rows || cols != other.cols)
        throw std::runtime_error("Invalid dimensions for matrix addition");

    for(int i = 0; i < rows; i++){
        for(int u = 0; u < cols; u++)
            data[i * cols + u] += other.data[i * cols + u];
    }
}

Matrix Matrix::init_weights(int rows_, int cols_, int seed=0){
    Matrix w(rows_, cols_);

    std::mt19937 rng(seed); // what a function name TT
    std::uniform_real_distribution<float> dist(-0.01f, 0.01f);

    for(int i = 0; i < rows; i++){
        for(int u = 0; u < cols; u++){
            w.data[i*cols + u] = dist(rng);
        }
    }
    return w;
}
