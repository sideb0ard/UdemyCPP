#include <iostream>
#include <memory>

using namespace std;

class Test {
public:
  Test() {
    cout << "Created\n";
  }
  void greet() {
    cout << "hola\n";
  }
  ~Test() {
    cout << "destroyed\n";
  }
};

int main() {

  shared_ptr<Test> pTest2(nullptr);

  {
    shared_ptr<Test> pTest = make_shared<Test>();
    pTest2 = pTest;
  }
  //pTest->greet();

  cout << "Finished\n";

  return 0;
}
