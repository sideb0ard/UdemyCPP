#include <iostream>
#include "ring.hpp"

using namespace std;

int main() {

    //Ring<string> textring(3);

    //textring.add("one");
    //textring.add("two");
    //textring.add("three");
    //textring.add("four");
    //
    Ring<string> textring({"jeeby", "jobby", "lobby"});


    for ( int i = 0; i < textring.size(); i++ ) {
        cout << textring.get(i) << endl;
    }
    cout << "\n";

    for ( Ring<string>::iterator it = textring.begin(); it != textring.end(); it++ ) {
        cout << *it << endl;
    }
    cout << "\n";

    for ( auto value : textring ) {
        cout << value << endl;
    }
    cout << "\n";

    return 0;
}
