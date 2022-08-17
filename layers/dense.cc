#include "dense.h"
#include <iostream>

using namespace std;

// PUBLIC DATA FIELD
// ctor
Dense::Dense(int n, Layer *l) : neuronCount{n}, prevLayer{l} {
    for (int i = 0; i < neuronCount; ++i) {
        double weight = ((double)rand() / RAND_MAX);
        double bias = ((double)rand() / RAND_MAX);

        weight = rand() % 2 == 0 ? weight : -weight;
        bias = rand() % 2 == 0 ? bias : -bias;
        neurons.emplace_back(
            new Neuron{weight, bias}
        );
    }
}

// dtor
Dense::~Dense() {
    for (int i = 0; i < neuronCount; ++i) {
        delete neurons[i];
    }
}

// copy ctor
Dense::Dense(const Dense &o) 
    : neuronCount{o.neuronCount}, prevLayer{o.prevLayer} {
    for (int i = 0; i < neuronCount; ++i) {
        neurons.emplace_back(
            new Neuron{*o.neurons[i]}
        );
    }
}

// move ctor
Dense::Dense(Dense &&o) 
    : neuronCount{o.neuronCount}, prevLayer{o.prevLayer} {
    for (int i = 0; i < neuronCount; ++i) {
        neurons.emplace_back(
            o.neurons[i]
        );
        o.neurons[i] = nullptr;
    }
}

// cao
Dense &Dense::operator=(const Dense &o) {
    Dense tmp{o};
    swap(tmp);
    return *this;
}

// mao
Dense &Dense::operator=(Dense &&o) {
    swap(o);
    return *this;
}

void Dense::setPrevLayer(Layer *l) {
    prevLayer = l;
}

// PRIVATE DATA FIELD
void Dense::swap(Dense &o) {
    if (neuronCount != o.neuronCount) {
        throw "both dense layers have different sizes";
    }
    for (int i = 0; i < neuronCount; ++i) {
        std::swap(neurons[i], o.neurons[i]);
    }
    std::swap(prevLayer, o.prevLayer);
}

std::vector<double> Dense::layerCall() {
    std::vector<double> prev = prevLayer->call();

    std::vector<double> ret;
    double sum = 0;
    for (int i = 0; i < prev.size(); ++i) {
        sum += prev[i];
    }

    for (int i = 0; i < neurons.size(); ++i) {
        double weight = neurons[i]->getWeight();
        double bias = neurons[i]->getBias();
        ret.emplace_back(bias + weight * sum);
    }

    // output
    cout << endl << "node weights: ";
    for (int i = 0; i < neurons.size(); ++i) {
        cout << "(" 
            << neurons[i]->getWeight() << "," 
            << neurons[i]->getBias()
            << ") ";
    }
    cout << endl;
    cout << "node values: ";
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << " ";
    }
    cout << endl;

    return ret;
}
