#include <iostream>

using namespace std;

void testGreet(void (*greet)(string name) ) {

    greet("Bob");
}

void runDivide(double (*pdiv)(double a, double b)) {
    auto rval = pdiv(9,3);
    cout << rval << endl;
}

int main() {

    auto pGreet = [](string name){ cout << "hello " << name << endl; };
    pGreet("mike");
    testGreet(pGreet);

    auto pDivide = [](double a, double b) -> double {
        if ( b == 0.0 ) {
            return 0;
        }
        return a / b;
    };

    cout <<  pDivide(10.0, 0.0) << endl;
    cout <<  pDivide(10.0, 5.0) << endl;

    runDivide(pDivide);

    return 0;
}
