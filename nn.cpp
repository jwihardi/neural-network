#include <iostream>
#include <string>
#include "data_loader.hpp"

struct Matrix{
    float *data;
    int rows, cols;

    Matrix(int rows_, int cols_) : data(new float[rows_ * cols_]) ,rows(rows_), cols(cols_) {};
    ~Matrix() { delete[] data; };
};

int main(int argc, char *argv[]){
    std::cout << "Neural Network\n"; 

    if(argc < 3){
        std::cerr << "Usage: " << argv[0] << " <images_file> <labels_file>\n";
        return 1;
    }

    std::string image_file_path = argv[1];
    std::string label_file_path = argv[2];
    int num_labels = std::stoi(argv[3]);
   
    Dataset dataset = load_images(image_file_path, num_labels);
    load_labels(label_file_path, &dataset);



    

    return 0;
}

