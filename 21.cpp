#include <iostream>
#include <vector>

using namespace std;

class Test {
    int id;
    string name;
public:
    Test(): id(0), name("") {}

    Test(int id, string name): id(id), name(name) {}
    void print() {
        cout << id << "	: " << name << endl;
    }

    Test(const Test &other) {
        cout << "Copy constructor running" << endl;
        *this = other;
        //id = other.id;
        //name = other.name;
    }

    const Test& operator=(const Test &other) {
        cout << "Assignment running" << endl;
        id = other.id;
        name = other.name;
        return *this;
    }

    //bool operator<(const Test& other) const {
    //    if ( name == other.name ) {
    //        return id < other.id;
    //    } else {
    //        return name < other.name;
    //    }
    //}
    friend bool comp(Test& a, Test& b);
};

bool comp(Test& a, Test&b) {
    return a.name < b.name;
}

int main() {

    Test test1(5, "Mike");
    cout << "print test1 " << flush;
    test1.print();
    
    Test test2(20, "Bob");
    cout << "print test2 " << flush;
    test2 = test1;
    test2.print();

    Test test3;
    cout << "print test3 " << flush;
    test3.operator=(test2);
    test3.print();

    cout << endl;
    Test test4 = test1;
    test4.print();

    return 0;
}
