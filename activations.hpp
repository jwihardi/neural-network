#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP

#include "matrix.hpp"

struct Activations{
    /* softmax = e^{current score} / sum of all e^{scores} */
    inline static Matrix softmax(const Matrix& mat){
        Matrix res(mat.rows, mat.cols);
        float max_val = mat.data[0];    
        
        for(int i = 0; i < mat.rows; i++){
            if(mat.data[i] > max_val)
                max_val = mat.data[i];
        }

        float sum = 0.0f;

        for(int i = 0; i < mat.rows; i++){
            res.data[i] = std::exp(mat.data[i] - max_val); // prevent e from exploding
            sum += res.data[i];
        }
        
        for(int i = 0; i < mat.rows; i++){
            res.data[i] /= sum;
        }
        return res;
    }


};




#endif
