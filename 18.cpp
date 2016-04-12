#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Test {
private:
    string name;
public:
    Test(string name) :
        name(name) {}
    ~Test() {}
    void print() {
        cout << name << endl;
    }
};

int main() {

    // LIFO
    queue<Test> testQueue;

    testQueue.push(Test("jim"));
    testQueue.push(Test("john"));
    testQueue.push(Test("sue"));

    //cout << testQueue.size() << endl;
    //Test &test1 = testQueue.top();
    //test1.print();
    //cout << testQueue.size() << endl;

    //testQueue.pop();
    //Test &test2 = testQueue.top();
    //test2.print();
    //cout << testQueue.size() << endl;
    while ( testQueue.size() > 0 ) {
        Test &test = testQueue.front();
        test.print();
        testQueue.pop();
    }


    return 0;
}
