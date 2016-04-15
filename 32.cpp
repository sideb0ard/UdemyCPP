#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool match(string test) {
    return test.size() == 3;
}

int countStrings(vector<string> &texts, bool (*match)(string test)) {
    int count = 0;
    for ( auto t : texts ) {
        //cout << "Looking at "<< t << endl;
        if ( match(t) ) { 
            count++;
            //cout << "Count is " << count << endl;
        }
    }
    return count;
}

int main() {
    vector<string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");

    //cout << match("two") << endl;
    //cout << count_if(texts.begin(), texts.end(), match) << endl;
    cout << "Num of text of size 3 is : " << countStrings(texts, match) << endl;

    return 0;
}
