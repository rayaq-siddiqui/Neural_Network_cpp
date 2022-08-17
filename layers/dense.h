#ifndef DENSE_H
#define DENSE_H

#include <stdlib.h>
#include <utility>
#include <string>
#include "../neuron.h"
#include "layer.h"

class Dense : public Layer {
    std::vector<Neuron*> neurons;
    const int neuronCount;
    Layer *prevLayer;
    std::string act_fn;

    // private helper
    void swap(Dense &o);
    std::vector<double> layerCall() override;

    // activation functions
    double relu(double x);
    double softmax(double x, double sum);

    public:
        // ctor
        Dense(int n, Layer *l=nullptr, std::string act_fn="relu");

        // dtor
        virtual ~Dense();

        // copy ctor
        Dense(const Dense &o);

        // move ctor
        Dense(Dense &&o);

        // cao
        Dense &operator=(const Dense &o);

        // mao
        Dense &operator=(Dense &&o);

        // getters/setters
        void setPrevLayer(Layer *l);
};

#endif 
