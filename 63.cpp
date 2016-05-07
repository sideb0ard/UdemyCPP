#include <iostream>
using namespace std;

class Test {

};

template<typename T>
void call(T &&arg) {
  check(arg);
}

void check(Test &test) {
  cout << "lvalue\n";
}

void check(Test &&test) {
  cout << "rvalue\n";
}

int main() {

  Test test;
  auto &&T = test;

  call(T);
  call(Test());

  return 0;
}
