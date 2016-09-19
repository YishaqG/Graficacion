#ifndef POINT3D
  #include "Point3D.h"
  #define POINT3D
#endif

#ifndef MATRIX
  #include "Matrix.h"
  #define MATRIX
#endif

#ifndef IO
  #include <stdio.h>
  #define IO
#endif

class Operations3D
{
  public:
    Operations3D();
    ~Operations3D();
    // void translation(Point& , Point);
    // void scale(Point&, Point);
    void rotate(int, Point3D&, int);
    // void deform(Point&, int, int);
    // void reflection(Point&, Point);
};
