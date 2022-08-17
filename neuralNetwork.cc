#include "neuralNetwork.h"

using namespace std;

// PUBLIC FUNCTIONS
NeuralNetwork::NeuralNetwork(
    int inSize,
    int outSize,
    std::vector<int> density
) : inputSize{inSize}, outputSize{outSize}, input{nullptr} {
    // the middle dense layers
    for (int i = 0; i < density.size(); ++i) {
        int d = density[i];
        Dense *l = i == 0 ? nullptr : layers[i-1];
        layers.emplace_back(
            new Dense{d, l}
        );
    }

    Dense *out = new Dense{outSize, layers[layers.size()-1]};
    layers.emplace_back(out);
}

// dtor
NeuralNetwork::~NeuralNetwork() {
    for (int i = layers.size()-1; i >= 0; --i) {
        delete layers[i];
    }
    delete input;
}

// copy/move ctor
NeuralNetwork::NeuralNetwork(const NeuralNetwork &o) 
    : inputSize{o.inputSize}, 
    outputSize{o.outputSize},
    layers{o.layers},
    input{o.input} {} 
NeuralNetwork::NeuralNetwork(NeuralNetwork &&o) 
    : inputSize{o.inputSize}, 
    outputSize{o.outputSize},
    layers{o.layers},
    input{o.input} {
    for (int i = 0; i < o.layers.size(); ++i) {
        o.layers[i] = nullptr;
    }
    o.input = nullptr;
} 

// cao/mao
NeuralNetwork &NeuralNetwork::operator=(const NeuralNetwork &o) {
    NeuralNetwork tmp{o};
    swap(tmp);
    return *this;
}
NeuralNetwork &NeuralNetwork::operator=(NeuralNetwork &&o) {
    swap(o);
    return *this;
}

// calling the nn
std::vector<double> NeuralNetwork::operator()(
    std::vector<double> data
) {
    layers[0]->setPrevLayer(nullptr);
    delete input;
    input = new Input(data);
    layers[0]->setPrevLayer(input);

    return layers[layers.size()-1]->call();
}

// PRIVATE HELPER FUNCTIONS
void NeuralNetwork::swap(NeuralNetwork &o) {
    std::swap(inputSize, o.inputSize);
    std::swap(outputSize, o.outputSize);
    std::swap(layers, o.layers);
    std::swap(input, o.input);
}
