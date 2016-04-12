#include "complex.hpp"

using namespace b0ardside;

int main() {

    Complex c1(2, 3);
    Complex c2 = c1;
    c2 = c1;

    cout << c2 << endl;

    return 0;
}
