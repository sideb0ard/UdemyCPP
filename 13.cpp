#include <iostream>
#include <map>


using namespace std;

int main() {

    map<string, int> ages;
    
    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    if ( ages.find("Vicky1") != ages.end()) {
        cout << "not found: vicky!\n";
    }

    pair<string, int> addToMap("Barney", 102);
    ages.insert(addToMap);

    ages.insert(make_pair("Jimmy", 47));

    //cout << ages["Mike"] << endl;
    for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++ ) {
        pair<string, int> age = *it;

        cout << age.first << " : " << age.second <<  endl;
    }

    return 0;
}
