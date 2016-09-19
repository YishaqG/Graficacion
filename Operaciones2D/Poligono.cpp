#include "Poligono.h"

Poligono::Poligono()
{
  figure = new Point[3];
  figure[0].setPoint((GLdouble)100.0, (GLdouble)0.0);
  figure[1].setPoint((GLdouble)0.0, (GLdouble)100.0);
  figure[2].setPoint((GLdouble)-100.0, (GLdouble)0.0);
  numOfVertices = 3;
}

Poligono::Poligono(Point &elm, int size)
{
  figure = &elm;
  numOfVertices = size;
  lab = Operations2D();
}

Poligono::~Poligono()
{
  delete[] figure;
}

void Poligono::move(Point delta)
{
  for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
  {
    lab.translation(figure[i], delta);
  }
}

void Poligono::scale(Point delta)
{
  for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
  {
    lab.scale(figure[i], delta);
  }
}

void Poligono::rotate(int delta)
{
  for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
  {
    lab.rotate(figure[i], delta);
  }
}

void Poligono::deform(int delta , int what)
{
  for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
  {
    lab.deform(figure[i], delta, what);
  }
}

void Poligono::reflect(Point axis)
{
  for(int i = 0; i < numOfVertices; i++) //Cicle to operate over all the points
  {
    lab.reflection(figure[i], axis);
  }
}

void Poligono::draw(int thikness)
{
  int i;
  Line tempL = Line();
  tempL.setThikness(thikness); //Define the thinknes of the line

  for(i = 0; i < numOfVertices-1; i++) //Cicle to operate over all the points
  {
    tempL.setPoint1(figure[i]);
    tempL.setPoint2(figure[i+1]);
    tempL.drawLineDDA();
  }

  tempL.setPoint1(figure[i]);
  tempL.setPoint2(figure[0]);
  tempL.drawLineDDA();
};
