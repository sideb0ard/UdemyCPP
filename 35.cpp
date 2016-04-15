#include <iostream>
using namespace std;

struct Test {
    virtual bool operator()(string &text)=0;
    virtual ~Test(){}

};

struct MatchTest : public Test {
    bool operator()(string &text) {
        return text == "lion";
    }
};

void check(string text, Test &test) {
    if (test(text)) {
        cout << text << " matches! " << endl;
    } else {
        cout << text << " doesn't match!" << endl;
    }
    
}

int main() {

    string value = "lion";
    string value2 = "wolf";

    MatchTest m;
    check(value, m);
    check(value2, m);



    return 0;
}
