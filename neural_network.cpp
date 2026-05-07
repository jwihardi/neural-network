#include <iostream>
#include <string>
#include "data_loader.hpp"
#include "matrix.hpp"
#include "activations.hpp"
#include "losses.hpp"

void train(const Dataset&, Matrix&, Matrix&, int, float);

int main(int argc, char *argv[]){
    std::cout << "Neural Network\n"; 

    if(argc < 5){
        std::cerr << "Usage: " << argv[0] << " <images_file> <labels_file>\n";
        return 1;
    }

    std::string image_file_path = argv[1];
    std::string label_file_path = argv[2];
    int epochs = std::stoi(argv[3]);
    float learning_rate = std::stof(argv[4]);
    int num_labels = std::stoi(argv[5]);

    Dataset dataset = load_images(image_file_path, num_labels);
    load_labels(label_file_path, &dataset);

    int batch_size = 1;

    std::mt19937 rand(0);

    Matrix weights = Matrix::init_rand_mat(dataset.num_classes, dataset.height * dataset.width, rand, -0.1f, 0.1f);
    Matrix bias(dataset.num_classes, 1);

    train(dataset, weights, bias, epochs, learning_rate);


    return 0;
}

void train(const Dataset& dataset, Matrix& weights, Matrix& bias, int epochs, float learning_rate){
    for(int epoch = 0; epoch < epochs; epoch++){
        float tot_loss = 0.0f;
        int correct = 0;

        for(unsigned int sample = 0; sample < dataset.num_samples; sample++){
            Matrix x = Matrix::load_image_mat(dataset, sample, 1); // batch size 1 for now
            
            Matrix z = weights.multiply(x);
            z.add(bias);

            Matrix predictions = Activations::softmax(z);

            int actual = dataset.labels[sample];
            int prediction = predictions.argmax();

            if(prediction == actual)
                correct++;

            tot_loss += Losses::cross_entropy(predictions, actual);

            /*      Backpropagation     */
            /* dz = y_hat - hot(actual) i.e. [2, 3, 2.2] - [0, 0, 1] */ 
            predictions.subtract_one_hot(actual);

            /* dW = dz * transpose(x) = db */
            Matrix dW = predictions.multiply(x.transpose());
            
            weights.subtract_scaled(dW, learning_rate);
            bias.subtract_scaled(predictions, learning_rate);
        }
        float avg_loss = tot_loss / static_cast<float>(dataset.num_samples);
        float accuracy = static_cast<float>(correct) / static_cast<float>(dataset.num_samples);
        std::cout << "Epoch: " << epoch + 1 << " | loss: " << avg_loss << " | accuracy: " << accuracy << "\n";
    }
}

