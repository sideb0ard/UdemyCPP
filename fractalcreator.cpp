#include <string>
#include <memory>
#include <iostream>
#include "math.h"

#include "bitmap.hpp"
#include "fractalcreator.hpp"
#include "mandelbrot.hpp"
#include "zoomlist.hpp"

using namespace std;

namespace b0ardside {

FractalCreator::FractalCreator(int width, int height) : m_height{height},
                                                        m_width{width},
                                                        m_histogram {new int[Mandelbrot::MAX_ITERATIONS] { 0 }},
                                                        m_fractal {new int[width*height] { 0 }},
                                                        m_bitmap{width, height},
                                                        m_zoomList{width, height}
{
  m_zoomList.add(Zoom(width/2, height/2, 4.0/width));
}

FractalCreator::~FractalCreator() {}

void FractalCreator::calculateIteration() {
  for ( int y = 0; y < m_height; y++ ) {
    for ( int x = 0; x < m_width; x++ ) {

      double xFractal, yFractal;
      tie(xFractal, yFractal) = m_zoomList.doZoom(x, y);

      int iterations = Mandelbrot::getIterations(xFractal, yFractal);

      m_fractal[y*m_width + x] = iterations;

      if ( iterations != Mandelbrot::MAX_ITERATIONS ) {
        m_histogram[iterations]++;
      }
    }
  }
  for ( int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++ ) {
    cout << m_histogram[i] << " " << flush;
  }
}

void FractalCreator::calculateTotalIterations() {
  for ( int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
    m_totalIterations += m_histogram[i];
  }
}


void FractalCreator::drawFractal() {
  for ( int y = 0; y < m_height; y++ ) {
    for ( int x = 0; x < m_width; x++ ) {
      uint8_t red   {0};
      uint8_t green {0};
      uint8_t blue  {0};

      int iterations =  m_fractal[y*m_width + x];

      if ( iterations != Mandelbrot::MAX_ITERATIONS) {
        double hue {0.0};
        for ( int i = 0; i <= iterations; i++) {
          hue += ((double)m_histogram[i]) / m_totalIterations;
        }

        green = pow(255, hue);
      }

      m_bitmap.setPixel( x, y, red, green, blue);
    }
  }
}
void FractalCreator::addZoom(const Zoom& zoom) {
  m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string name) {
  m_bitmap.write(name);
}

} // end namespace

