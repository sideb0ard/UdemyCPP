#include <iostream>
#include <vector>
using namespace std;

class Test {
public:
    Test() {
        cout << "contrsuctor" << endl;
    }
    Test(int i) {
        cout << "parameterized constructor" << endl;
    }
    Test(const Test &other) {
        cout << "Copy contructor" << endl;
    }
    Test &operator=(const Test &other) {
        cout << "Copy assignment operator" << endl;
        return *this;
    }
    ~Test() {
        cout << "destructor called" << endl;
    }
    friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test) {
    out << "Hullo from test";
    return out;
}

Test getTest() {
    return Test();
}

int main() {

    Test testes = getTest();
    cout << testes << "\n";

    return 0;
}
