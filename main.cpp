#include <iostream>
#include <cstdint>
#include "bitmap.hpp"
#include "mandelbrot.hpp"

using namespace std;
using namespace b0ardside;

int main() {

  int const WIDTH  = 800;
  int const HEIGHT = 600;

  Bitmap bitmap(WIDTH, HEIGHT);

  double min =  999999;
  double max = -999999;

  //bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);
  for ( int y = 0; y < HEIGHT; y++ ) {
    for ( int x = 0; x < WIDTH; x++ ) {
      //double xFractal = ((2.0 / WIDTH) * x) - 1;
      //double yFractal = ((2.0 / HEIGHT) * y) - 1;
      double xFractal = (x - WIDTH/2 - 200) * 2.0/HEIGHT;
      double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;

      int iterations = Mandelbrot::getIterations(xFractal, yFractal);

      uint8_t color = (uint8_t) (256 * (double) iterations / Mandelbrot::MAX_ITERATIONS);

      color = color*color*color;

      bitmap.setPixel( x, y, color, color, 0);

      if ( color < min ) { min = color; };
      if ( color > max ) { max = color; };

    }
  }

  cout << min << ", " << max << endl;

  bitmap.write("test.bmp");

  cout << "yarly bitmpa!\n";
  return 0;
}
