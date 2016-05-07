#include <iostream>
using namespace std;

class Parent {
    int dogs;
    string text;
public:
    Parent() : Parent("yarly") {
        dogs = 5;
        cout << "NO params parent constr" << endl;
    }
    Parent(string text) {
        dogs = 6;
        this->text = text;
        cout << "string parent cnstr" << endl;
    }
};

class Child : public Parent {
public:
    Child() {}
};

int main() {

    Parent parent("hillo");
    Child child;
    return 0;
}
