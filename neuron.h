#ifndef Neuron_H
#define Neuron_H

#include <utility>

class Neuron {
    double weight, bias;

    // private helper function
    void swap(Neuron &o);

    // activation functions
    void relu();

    public:
        // ctor
        Neuron(double weight, double bias);

        // dtor
        ~Neuron();

        // copy ctor
        Neuron(const Neuron &o);

        // move ctor
        Neuron(Neuron &&o);

        // copy assignment operator
        Neuron &operator=(const Neuron &o);

        // move assignment operator
        Neuron &operator=(Neuron &&o);

        // getters/setters
        double getWeight();
        void setWeight(double w);

        double getBias();
        void setBias(double b);
};

#endif
