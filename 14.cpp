#include <iostream>
#include <map>
using namespace std;


class Person {
private:
    string m_name;
    int m_age;
public:
    Person(): m_name(""), m_age(0) {}
    Person(string name, int age) :
        m_name(name), m_age(age) {}

    void print() {
        cout << m_name << " : " << m_age << endl;
    }
};


int main() {

    map<int, Person> people;
    
    people[0] = Person("Mike", 40);
    people[1] = Person("Raj", 20);
    people[2] = Person("Vicky", 30);

    for ( map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
        it->second.print();
    }

    return 0;
}
