#include <iostream>
#include "neuralNetwork.h"

using namespace std;

int main() {
    NeuralNetwork nn{5,5, {5,5,5}};
    vector<double> data{1,2,3,4,5};

    // process
    cout << "PROCESS:" << endl;
    vector<double> out = nn(data);

    cout << endl << "RESULTS" << endl;
    cout << "data: ";
    for (const auto &d : data) { cout << d << " "; }
    cout << endl;

    cout << "output: ";
    for (const auto &o : out) { cout << o << " "; }
    cout << endl;

    // for (const auto &i : out) {
    //     cout << i << " ";
    // }
    // cout << endl;
    return 0;
}