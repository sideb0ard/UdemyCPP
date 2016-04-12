#include <iostream>
using namespace std;

int main() {

    int one = 1;
    int two = 2;
    int three = 3;


    // capture by value
    [one, two](){ cout << "hullo" << one << two << endl;}();

    // capture all by value
    [=, &three](){ cout << "hullo" << one << two << endl; three++;}();

    cout << "Three is now " << three << endl;

    return 0;
}
