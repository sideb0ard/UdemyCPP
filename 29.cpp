#include <iostream>
using namespace std;

template<class T>
void print(T n) {
    cout << n << endl;
}

int main() {

    print<string>("boop");
    print<int>(55);
    return 0;
}
