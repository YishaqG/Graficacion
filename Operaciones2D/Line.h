#ifndef MATH
  #include <math.h>
  #define MATH
#endif

#ifndef POINT
  #include "Point.h"
  #define POINT
#endif

class Line
{
  private:
    //1_Variables
    Point p1;
    Point p2;
    int thikness;
    //0_Variables

  public:
  //1_Builders
    Line();
    Line(Point, Point);
    Line(Point, Point, int);
  //0_Builders

  //1_Destroyers
    //~Line();
  //0_Destroyers

  //1_Funciones
    void setPoint1( Point );
    Point getPoint1();
    void setPoint2( Point );
    Point getPoint2();
    void setThikness(int);
    void drawLineDDA();
  //0_Funciones
};
