#include "input.h"
#include <iostream>

using namespace std;

// PUBLIC DATA FIELD
// ctor
Input::Input(std::vector<double> data) : neurons{data} {}

// dtor
Input::~Input() {}

// copy ctor
Input::Input(const Input &o) : neurons{o.neurons} {}

// move ctor
Input::Input(Input &&o) : neurons{o.neurons} {}

// cao
Input &Input::operator=(const Input &o) {
    Input tmp{o};
    swap(tmp);
    return *this;
}

// mao
Input &Input::operator=(Input &&o) {
    swap(o);
    return *this;
}

// PRIVATE DATA FIELD
void Input::swap(Input &o) {
    if (neurons.size() != o.neurons.size()) {
        throw "input is not the same size";
    }
    for (int i = 0; i < neurons.size(); ++i) {
        std::swap(neurons[i], o.neurons[i]);
    }
}

std::vector<double> Input::layerCall() {
    // output
    cout << "node values: ";
    for (int i = 0; i < neurons.size(); ++i) {
        cout << neurons[i] << " ";
    }
    cout << endl;
    return neurons;
}
