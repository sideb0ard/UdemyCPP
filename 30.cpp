#include <iostream>
using namespace std;

void test(int value) {
    cout << "hullo" << value << endl;
}

int main() {

    test(5);
    
    void (*pTest)(int) = test;

    pTest(10);
    return 0;
}
