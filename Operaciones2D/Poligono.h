#ifndef POINT
  #include "Point.h"
  #define POINT
#endif

#ifndef LINE
  #include "Line.h"
  #define LINE
#endif

#ifndef OPERATIONS2D
  #include "Operations2D.h"
  #define OPERATIONS2D
#endif

class Poligono
{
  private:
    Operations2D lab;
    Point *figure;
    int numOfVertices;

  public:
    Poligono();
    Poligono(Point&, int);
    ~Poligono();
    void move(Point);
    void scale(Point);
    void rotate(int);
    void deform(int, int);
    void reflect(Point);
    void draw(int);
};
