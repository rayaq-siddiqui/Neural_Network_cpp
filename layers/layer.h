#ifndef LAYER_H
#define LAYER_H

#include <vector>

class Layer {
    virtual std::vector<double> layerCall() = 0;

    public:
        std::vector<double> call();
};

#endif
