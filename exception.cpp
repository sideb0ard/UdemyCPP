#include <iostream>
#include <exception>

using namespace std;

void goesWrong() {
    bool error1Detected = true;
    bool error2Detected = false;

    if ( error1Detected) {
        throw bad_alloc();
    }
    if ( error2Detected) {
        throw bad_alloc();
    }
}


int main() {

    return 0;
}
