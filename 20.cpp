#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {

    map<string, vector<int>> scores;
    scores["Mike"].push_back(10);
    scores["Mike"].push_back(25);
    scores["Susey"].push_back(75);
    scores["Susey"].push_back(104);
    scores["James"].push_back(99);

    for ( map<string, vector<int>>::iterator it = scores.begin(); it != scores.end(); it++ ) {
        string name = it->first;
        vector<int> p_scores = it->second;

        cout << "Name: " << name << flush;
        for ( vector<int>::iterator tit = p_scores.begin() ; tit != p_scores.end(); tit++ ) {
            cout << " " << *tit;
        }
        cout << endl;
    }

    return 0;
}
