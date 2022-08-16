#include "dense.h"

// PUBLIC DATA FIELD
// ctor
Dense::Dense(int n) : neuronCount{n} {
    for (int i = 0; i < neuronCount; ++i) {
        neurons.emplace_back(
            new Neuron{rand() % 2, rand() % 2}
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
Dense::Dense(const Dense &o) : neuronCount{o.neuronCount} {
    for (int i = 0; i < neuronCount; ++i) {
        neurons.emplace_back(
            new Neuron{*o.neurons[i]}
        );
    }
}

// move ctor
Dense::Dense(Dense &&o) : neuronCount{o.neuronCount} {
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

// PRIVATE DATA FIELD
void Dense::swap(Dense &o) {
    if (neuronCount != o.neuronCount) {
        throw "both dense layers have different sizes";
    }
    for (int i = 0; i < neuronCount; ++i) {
        std::swap(neurons[i], o.neurons[i]);
    }
}

