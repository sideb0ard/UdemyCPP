#include <iostream>

using namespace std;

void test(void (*pFunc)()) {
    pFunc();

}

int main() {

    auto func = [](){ cout << "hullo " << endl; };
    func();
    test(func);

    test( [](){ cout << "hullo again" << endl; });
    return 0;
}
