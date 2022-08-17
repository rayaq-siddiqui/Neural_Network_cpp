#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "layers/dense.h"
#include "layers/input.h"
#include <vector>
#include <utility>

class NeuralNetwork {
    int inputSize;
    int outputSize;

    Input *input;
    std::vector<Dense*> layers;

    // private helper functions
    void swap(NeuralNetwork &o);

    public:
        // ctor
        NeuralNetwork(
            int inSize, 
            int outSize, 
            std::vector<int> density={10,10,10}
        );

        // dtor
        ~NeuralNetwork();

        // copy/move ctor
        NeuralNetwork(const NeuralNetwork &o);
        NeuralNetwork(NeuralNetwork &&o);

        // cao/mao
        NeuralNetwork &operator=(const NeuralNetwork &o);
        NeuralNetwork &operator=(NeuralNetwork &&o);

        // calling the nn
        std::vector<double> operator()(std::vector<double> data);
};

#endif
