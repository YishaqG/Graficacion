#ifndef POLIGONO3D
  #include "Poligono3D.h"
  #define POLIGONO3D
#endif

class Polyhedron
{
  private:
    Poligono3D *figura;
    int numOfPoligons;
  public:
    /*1_Builders*/
    Polyhedron();
    Polyhedron(Poligono3D *poligonos);
    /*0_Builders*/
    /*1_Destroyers*/
    ~Polyhedron();
    /*0_Destroyers*/
    //Functions
    // void move(Point3D);
    // void scale(Point3D);
    void rotate(int, int);
    // void deform(int, int);
    // void reflect(Point3D);
    void draw(int);
};
