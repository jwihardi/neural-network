struct Matrix{
    float *data;
    int rows, cols;

    Matrix(int rows, int cols) : data(new float[rows * cols]) ,rows(rows), cols(cols) {};
    ~Matrix() { delete[] data };
};

struct Dataset{
    float *images;
    int *labels, num_samples, height, width, num_classes;

    Dataset(int height, int width, int num_classes, int num_samples) :
        images(new float[height * width * num_samples]),
        labels(new int[num_samples]),
        num_samples(num_samples), 
        height(height),
        width(width),
        num_classes(num_classes) 
    {}


    ~Dataset(){
        delete [] images;
        delete [] data;
    }
};


int main(){



}
