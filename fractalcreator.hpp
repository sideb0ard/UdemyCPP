#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include "zoom.hpp"
#include "bitmap.hpp"
#include "zoomlist.hpp"
#include "mandelbrot.hpp"
#include "rgb.hpp"

#include <string>
#include <vector>

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

  vector<int> m_ranges;
  vector<RGB> m_colors;
  vector<int> m_rangeTotals;

  bool m_bGotFirstRange{false};


private:
  void calculateIteration();
  void calculateTotalIterations();
  void calculateRangeTotals();
  void drawFractal();
  void writeBitmap(string name);
  int getRange(int iterations) const;


public:
  FractalCreator(int width, int height);
  virtual ~FractalCreator();

  void addRange(double rangeEnd, const RGB& rgb);
  void addZoom(const Zoom& zoom);
  void run(string name);

};

} // end namespace

#endif  //FRACTALCREATOR_H_
