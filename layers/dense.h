#ifndef DENSE_H
#define DENSE_H

#include <vector>
#include <stdlib.h>
#include <utility>
#include "../neuron.h"

class Dense {
    std::vector<Neuron*> neurons;
    const int neuronCount;

    // private helper
    void swap(Dense &o);

    public:
        // ctor
        Dense(int n);

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
