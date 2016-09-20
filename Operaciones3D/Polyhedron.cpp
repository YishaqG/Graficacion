#include "Polyhedron.h"

Polyhedron::Polyhedron()
{
  numOfPoligons = 5;
  figura = new Poligono3D[numOfPoligons];
  Point3D *points0 =  new Point3D[3];
  Point3D *points1 =  new Point3D[3];
  Point3D *points2 =  new Point3D[3];
  Point3D *points3 =  new Point3D[3];

    points0[1].setPoint((GLdouble) 10.0,(GLdouble)0.0,(GLdouble)0.0);
    points0[2].setPoint((GLdouble) 5.0,(GLdouble)10.0,(GLdouble)5.0);
  figura[1].setPoligono(points0, 3);


    points1[0].setPoint((GLdouble) 10.0,(GLdouble)0.0,(GLdouble)0.0);
    points1[1].setPoint((GLdouble) 10.0,(GLdouble)0.0,(GLdouble)10.0);
    points1[2].setPoint((GLdouble) 5.0,(GLdouble)10.0,(GLdouble)5.0);
  figura[2].setPoligono(points1, 3);

    points2[0].setPoint((GLdouble) 10.0,(GLdouble)0.0,(GLdouble)10.0);
    points2[1].setPoint((GLdouble) 0.0,(GLdouble)0.0,(GLdouble)10.0);
    points2[2].setPoint((GLdouble) 5.0,(GLdouble)10.0,(GLdouble)5.0);
  figura[3].setPoligono(points2, 3);

    points3[0].setPoint((GLdouble) 0.0,(GLdouble)0.0,(GLdouble)10.0);
    points3[1].setPoint((GLdouble) 0.0,(GLdouble)0.0,(GLdouble)0.0);
    points3[2].setPoint((GLdouble) 5.0,(GLdouble)10.0,(GLdouble)5.0);
  figura[4].setPoligono(points3, 3);

}

Polyhedron::~Polyhedron()
{
  delete[] figura;
}

void Polyhedron::rotate(int flag, int delta)
{
  for(int i = 0; i < numOfPoligons; i++)
    figura[i].rotate(flag, delta);
}

void Polyhedron::draw(int thikness)
{
  for(int i = 0; i < numOfPoligons; i++)
    figura[i].draw(thikness);
}
