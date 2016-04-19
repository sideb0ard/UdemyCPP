#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

namespace b0ardside {

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex &other);

    const Complex & operator=(const Complex &other);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; };
    bool operator==(const Complex &other) const;

};

ostream &operator<<(ostream &out, const Complex &c);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, const double d);

} // namespace b0ardside
#endif
