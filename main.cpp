#include <iostream>
#include <cstdint>
#include <memory>

#include <math.h>

#include "bitmap.hpp"
#include "mandelbrot.hpp"
#include "zoomlist.hpp"
#include "fractalcreator.hpp"

using namespace std;
using namespace b0ardside;

int main() {

  int height { 600 };
  FractalCreator fc{800, 600};

  fc.addZoom(Zoom(295, height - 202, 0.1));
  fc.addZoom(Zoom(312, height - 304, 0.1));

  fc.calculateIteration();
  fc.calculateTotalIterations();

  fc.drawFractal();

  fc.writeBitmap("test.bmp");

  cout << "yarly bitmpa!\n";
  return 0;
}
