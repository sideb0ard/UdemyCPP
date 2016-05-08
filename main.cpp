#include <iostream>
#include <cstdint>
#include <memory>

#include <math.h>

#include "fractalcreator.hpp"

using namespace std;
using namespace b0ardside;

int main() {

  FractalCreator fc{800, 600};

  fc.addRange(0.0, RGB(0, 0, 0));
  fc.addRange(0.3, RGB(10, 0, 255));
  fc.addRange(0.5, RGB(255, 255, 0));
  fc.addRange(1.0, RGB(55, 255, 255));

  fc.addZoom(Zoom(295, 202, 0.1));
  fc.addZoom(Zoom(312, 304, 0.1));

  fc.run("test.bmp");

  cout << "yarly bitmpa!\n";
  return 0;
}
