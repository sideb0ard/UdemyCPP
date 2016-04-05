#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)
struct Person {
    char name[50];
    int age;
    double height;
};
#pragma pack(pop)

int main() {

    Person sumbody = { "James Bond", 77, 1.5};

    string fileName = "test.bin";

    // write binary file

    ofstream outputFile;
    outputFile.open(fileName, ios::binary);

    if ( outputFile.is_open()) {
        outputFile.write(reinterpret_cast<char*>(&sumbody), sizeof(Person));
        outputFile.close();
    } else {
        cout << "Couldnt create " << fileName << endl;
    }

    // read binary file
    
    Person sumbodyElse = {};

    ifstream inputFile;
    inputFile.open(fileName, ios::binary);

    if ( inputFile.is_open()) {
        inputFile.read(reinterpret_cast<char*>(&sumbodyElse), sizeof(Person));
        inputFile.close();
    } else {
        cout << "Couldnt read " << fileName << endl;
    }

    cout << sumbodyElse.name << ", " << sumbodyElse.age << ", " << sumbodyElse.height << endl;
    return 0;



}
