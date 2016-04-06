#include <iostream>
#include <list>


using namespace std;

int main() {

    list<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(0);

    list<int>::iterator it = numbers.begin();
    while (it != numbers.end()) {
        //cout << "ITEM<" << *it << ">" << endl;
        if ( *it == 2 ) {
            numbers.insert(it, 1234);
        }
        if ( *it == 1 ) {
            it = numbers.erase(it);
        } else {
            it++;
        }
    }

    for ( auto i : numbers )
        cout << " * " << i << endl;


    return 0;
}
