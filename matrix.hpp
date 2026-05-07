#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <stdexcept>

struct Matrix{
    std::vector<float> data;
    int rows, cols;

    Matrix(int rows_, int cols_) : data(rows_ * cols_) ,rows(rows_), cols(cols_) {}
    
    Matrix multiply(const Matrix& other) const{
        if(cols != other.rows) 
            throw std::runtime_error("Invalid dimensions for matrix multiplication");

        Matrix res(rows, other.cols);

        for(int i = 0; i < rows; i++){
            for(int u = 0; u < cols; u++){
                float sum = 0.0f;
                for(int k = 0; k < cols; k++)
                    sum += data[i * cols + k] * other.data[k * other.cols + j];
                res.data[i * res.cols + u] = sum;
            }
        }
        return res;
    }

    Matrix transpose() const{
        Matrix res(cols, rows);

        for(int i = 0; i < rows; i++){
            for(int u = 0; u < cols; u++){
                res.data[u * res.cols + i] = data[i * cols + u];
            }
        }
        return res;
    }



    ~Matrix() { delete[] data; }
    
};








#endif
