#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "zoom.hpp"
#include "zoomlist.hpp"
#include "mandelbrot.hpp"

#include <string>

using namespace std;

namespace b0ardside {

class FractalCreator {
private:
  int m_width{0};
  int m_height{0};
  int m_totalIterations{0};
  ZoomList m_zoomList;
  Bitmap m_bitmap;
  unique_ptr<int[]> m_histogram;// (new int[Mandelbrot::MAX_ITERATIONS] { 0 });
  unique_ptr<int[]> m_fractal; // (new int[WIDTH*HEIGHT] { 0 } );

public:
  FractalCreator(int width, int height);
  virtual ~FractalCreator();

  void calculateIteration();
  void calculateTotalIterations();
  void drawFractal();
  void addZoom(const Zoom& zoom);
  void writeBitmap(string name);


};

} // end namespace

#endif  //FRACTALCREATOR_H_
