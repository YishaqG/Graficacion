#ifndef MATH
  #include <math.h>
  #define MATH
#endif

#ifndef POINT3D
  #include "Point3D.h"
  #define POINT3D
#endif

class Line3D
{
  private:
    //1_Variables
    Point3D p1;
    Point3D p2;
    int thikness;
    //0_Variables

  public:
  //1_Builders
    Line3D();
    Line3D(Point3D, Point3D);
    Line3D(Point3D, Point3D, int);
  //0_Builders

  //1_Destroyers
    //~Line();
  //0_Destroyers

  //1_Funciones
    void setPoint1( Point3D );
    Point3D getPoint1();
    void setPoint2( Point3D );
    Point3D getPoint2();
    void setThikness(int);
    void draw();
  //0_Funciones
};
