#ifndef INPUT_H
#define INPUT_H

#include <utility>
#include "../neuron.h"
#include "layer.h"

class Input : public Layer {
    std::vector<double> neurons;

    // private helper
    void swap(Input &o);
    std::vector<double> layerCall() override;

    public:
        // ctor
        Input(std::vector<double> data={});

        // dtor
        virtual ~Input();

        // copy ctor
        Input(const Input &o);

        // move ctor
        Input(Input &&o);

        // cao
        Input &operator=(const Input &o);

        // mao
        Input &operator=(Input &&o);
};

#endif 
