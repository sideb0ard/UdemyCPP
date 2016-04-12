#include <iostream>
using namespace std;

class Test {
private:
    int one{1};
    int two{2};
public:
    void run() {
        int three{3};
        int four{4};

        auto pLambda = [this, three, four](){
            cout << "One " << one << endl;
            cout << "Two " << two << endl;
            cout << "Three " << three << endl;
            cout << "Four " << four << endl;
        };
        pLambda();
    }
};

int main() {

    Test test;
    test.run();

    return 0;
}
