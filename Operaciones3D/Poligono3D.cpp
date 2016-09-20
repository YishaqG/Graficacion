#include "Poligono3D.h"

Poligono3D::Poligono3D()
{
  figure = new Point3D[4];
  figure[0].setPoint((GLdouble)0.0, (GLdouble)0.0, (GLdouble)0.0);
  figure[1].setPoint((GLdouble)10.0, (GLdouble)0.0, (GLdouble)0.0);
  figure[2].setPoint((GLdouble)10.0, (GLdouble)0.0, (GLdouble)10.0);
  figure[3].setPoint((GLdouble)0.0, (GLdouble)0.0, (GLdouble)10.0);
  numOfVertices = 4;
}

Poligono3D::Poligono3D(Point3D &elm, int size)
{
  figure = &elm;
  numOfVertices = size;
}

Poligono3D::~Poligono3D()
{
  delete[] figure;
}

void Poligono3D::setPoligono(Point3D *x, int elm)
{
  delete[] figure;
  figure = x;
  numOfVertices = elm;
}

// void Poligono3D::move(Point3D delta)
// {
//   for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
//   {
//     lab.translation(figure[i], delta);
//   }
// }
//
// void Poligono3D::scale(Point3D delta)
// {
//   for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
//   {
//     lab.scale(figure[i], delta);
//   }
// }

void Poligono3D::rotate(int typeOfRotation, int delta)
{
  for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
  {
    lab.rotate(typeOfRotation, figure[i], delta);
  }
}

// void Poligono3D::deform(int delta , int what)
// {
//   for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
//   {
//     lab.deform(figure[i], delta, what);
//   }
// }
//
// void Poligono3D::reflect(Point3D axis)
// {
//   for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
//   {
//     lab.reflection(figure[i], axis);
//   }
// }

void Poligono3D::draw(int thikness)
{
  int i;
  Line3D tempL;
  tempL.setThikness(thikness); //Define the thinknes of the line

  for(i = 0; i < numOfVertices-1; i++) //Cicle to operate over all the points
  {
    tempL.setPoint1(figure[i]);
    tempL.setPoint2(figure[i+1]);
    tempL.draw();
  }

  tempL.setPoint1(figure[i]);
  tempL.setPoint2(figure[0]);
  tempL.draw();
};
