#include <iostream>
#include <vector>
#include "layers/input.h"
#include "layers/dense.h"

using namespace std;

int main() {
    vector<double> data {1,2,3,4,5,6,0,1,2,3};
    for (auto &r : data) {
        cout << r << " ";
    }
    cout << endl;

    // creating a test nn
    Input *in = new Input{data};
    Dense *d1 = new Dense{10, in};
    Dense *d2 = new Dense{10, d1};

    vector<double> ret = d2->call();

    for (auto &r : ret) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
