#ifndef DENSE_H
#define DENSE_H

#include <stdlib.h>
#include <utility>
#include "../neuron.h"
#include "layer.h"

class Dense : public Layer {
    std::vector<Neuron*> neurons;
    const int neuronCount;
    Layer *prevLayer;

    // private helper
    void swap(Dense &o);
    std::vector<double> layerCall() override;

    public:
        // ctor
        Dense(int n, Layer *l=nullptr);

        // dtor
        ~Dense();

        // copy ctor
        Dense(const Dense &o);

        // move ctor
        Dense(Dense &&o);

        // cao
        Dense &operator=(const Dense &o);

        // mao
        Dense &operator=(Dense &&o);
};

#endif 
