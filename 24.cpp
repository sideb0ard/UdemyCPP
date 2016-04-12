#include <iostream>
#include "complex.hpp"

using namespace std;
using namespace b0ardside;

int main() {

    cout << "yalry" << endl;
    Complex c1(3,4);
    Complex c2(4,7);

    Complex c3 = c1;

    cout << c1+c2+c3 << endl;
    Complex c5 = c3+7;
    cout << c3 << " // " << c5 << endl;

    cout << (c3 == c1) << " // " << (c2 == c1) << endl;

    return 0;
}
