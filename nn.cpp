#include <iostream>
#include <string>
#include "data_loader.hpp"
#include "matrix.hpp"
#include "activations.hpp"
#include "losses.hpp"

int main(int argc, char *argv[]){
    std::cout << "Neural Network\n"; 

    if(argc < 4){
        std::cerr << "Usage: " << argv[0] << " <images_file> <labels_file>\n";
        return 1;
    }

    std::string image_file_path = argv[1];
    std::string label_file_path = argv[2];
    int num_labels = std::stoi(argv[3]);

    Dataset dataset = load_images(image_file_path, num_labels);
    load_labels(label_file_path, &dataset);

    int batch_size = 1;

    std::mt19937 rand(0);

    Matrix weights = Matrix::init_rand_mat(dataset.num_classes, dataset.height * dataset.width, rand, -0.1f, 0.1f);
    Matrix bias(dataset.num_classes, 1);

    Matrix x = Matrix::load_image_mat(dataset, 0, batch_size);

    Matrix logits = weights.multiply(x);
    logits.add(bias);

    Matrix a = Activations::softmax(logits); // a = activation(z) where z = logits



    return 0;
}

