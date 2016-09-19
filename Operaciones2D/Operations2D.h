#ifndef POINT
  #include "Point.h"
  #define POINT
#endif

#ifndef MATRIX
  #include "Matrix.h"
  #define MATRIX
#endif

#ifndef IO
  #include <stdio.h>
  #define IO
#endif

#define DEFORM_X 0
#define DEFORM_Y 1
#define DEFORM_XY 2

class Operations2D
{
  public:
    Operations2D();
    ~Operations2D();
    void translation(Point& , Point);
    void scale(Point&, Point);
    void rotate(Point&, int);
    void deform(Point&, int, int);
    void reflection(Point&, Point);
};
