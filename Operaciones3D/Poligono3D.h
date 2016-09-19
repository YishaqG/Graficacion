#ifndef POINT3D
  #include "Point3D.h"
  #define POINT3D
#endif

#ifndef LINE3D
  #include "Line3D.h"
  #define LINE3D
#endif

#ifndef OPERATIONS3D
  #include "Operations3D.h"
  #define OPERATIONS3D
#endif

class Poligono3D
{
  private:
    Operations3D lab;
    Point3D *figure;
    int numOfVertices;

  public:
    Poligono3D();
    Poligono3D(Point3D&, int);
    ~Poligono3D();
    void move(Point3D);
    void scale(Point3D);
    void rotate(int, int);
    void deform(int, int);
    void reflect(Point3D);
    void draw(int);
};
