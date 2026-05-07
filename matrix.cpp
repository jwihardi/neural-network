#include <stdexcept>
#include <random>
#include "matrix.hpp"

Matrix::Matrix(int rows_, int cols_) : data(rows_ * cols_), rows(rows_), cols(cols_) {}

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

Matrix Matrix::init_rand_mat(int rows_, int cols_, float lower=-0.01f, float upper=0.01f, int seed=0){
    Matrix matrix(rows_, cols_);

    std::mt19937 rng(seed); // what a function name TT
    std::uniform_real_distribution<float> dist(lower, upper);

    for(int i = 0; i < rows; i++){
        for(int u = 0; u < cols; u++){ // for biases not sure performance of an iteration of 1
            matrix.data[i*cols + u] = dist(rng);
        }
    }
    return matrix;
}





