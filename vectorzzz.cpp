#include <iostream>
#include <vector>

using namespace std;


int main() {

    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    strings[1] = "dog";

    cout << strings[1] << endl;
    cout << strings.size() << endl;

    for (int i = 0; i < strings.size(); i++ ) {
        cout << "BLAH " << strings[i] << endl;
    }

    for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++ ) {
        cout << "YARLY " << *it << endl;
    }

    return 0;
}
