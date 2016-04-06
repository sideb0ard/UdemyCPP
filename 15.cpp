#include <iostream>
#include <map>
using namespace std;


class Person {
private:
    string m_name;
    int m_age;
public:
    Person(): m_name(""), m_age(0) {}

    Person(const Person &other) {
        cout << "Copy constructor running!" << endl;
        m_name = other.m_name;
        m_age  = other.m_age;
    }

    Person(string name, int age) :
        m_name(name), m_age(age) {}

    void print() const {
        cout << m_name << " : " << m_age << flush;
    }

    bool operator<(const Person &other) const {
        if (m_name == other.m_name) {
            return m_age < other.m_age;
        } else {
            return m_name < other.m_name;
        }
    }
};


int main() {

    //map<int, Person> people;
    map<Person, int> people;
    
    people[Person("Vicky", 30)] = 30;
    people[Person("Raj", 20)] = 20;
    people[Person("Mike", 40)] = 50;
    people[Person("Mike", 454)] = 60;

    //people.insert(make_pair(55, Person("Bob", 45)));
    //people.insert(make_pair(56, Person("Boab", 47)));

    for ( map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
        it->first.print();
        cout << endl;
    }

    return 0;
}
