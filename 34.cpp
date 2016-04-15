#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() = 0;
};

class Dog : public Animal {
public:
    virtual void speak() {
        cout << "Woof!" << endl;
    }
};


int main() {

    Dog dog;
    dog.speak();

    return 0;
}
