#include "neuron.h"

using namespace std;

// PUBLIC FUNCTIONS
// ctor
Neuron::Neuron(double weight, double bias) 
    : weight{weight}, bias{bias} {}

// dtor
Neuron::~Neuron() {}

// copy ctor
Neuron::Neuron(const Neuron &o) 
    : weight{o.weight}, bias{o.bias}{}

// move ctor
Neuron::Neuron(Neuron &&o) 
    : weight{o.weight}, bias{o.bias} {}

// copy assignment operator
Neuron &Neuron::operator=(const Neuron &o) {
    Neuron tmp{o};
    swap(tmp);
    return *this;
}

// move assignment operator
Neuron &Neuron::operator=(Neuron &&o) {
    swap(o);
    return *this;
}

double Neuron::getWeight() { return weight; }
void Neuron::setWeight(double w) { weight = w; }

double Neuron::getBias() { return bias; }
void Neuron::setBias(double b) { bias = b; }

// PRIVATE FUNCTIONS
void Neuron::swap(Neuron &o) {
    std::swap(weight, o.weight);
    std::swap(bias, o.bias);
}
