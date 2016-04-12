#include <iostream>
#include <set>

using namespace std;

class Test {
    int id;
    string name;
public:
    Test(int id, string name): id(id), name(name) {}
    void print() const { cout << id << " : " << name << endl;}

    bool operator<(const Test& other) const {
        return name < other.name;
    }
};

int main() {

    set<int> numbers;

    numbers.insert(50);
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(55);
    numbers.insert(50);

    for (set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        cout << *it << endl;
    }
    set<int>::iterator itFind = numbers.find(30);
    if (itFind != numbers.end()) {
        cout << "Found: " << *itFind << endl;
    }

    if (numbers.count(30)) {
        cout << "Found!" << endl;
    }
    set<Test> tests;
    tests.insert(Test(10, "blah"));
    tests.insert(Test(13, "blah13"));
    tests.insert(Test(23, "blah23"));
    tests.insert(Test(43, "blah23"));
    for (auto it : tests ) 
        it.print();

    return 0;
}
