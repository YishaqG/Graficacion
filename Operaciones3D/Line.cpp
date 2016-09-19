#include "Line.h"

Line::Line()
{
  p1 = Point((GLdouble)0.0, (GLdouble)0.0);
  p2 = Point((GLdouble)0.0, (GLdouble)0.0);
  thikness = 1;
}

Line::Line(Point p1, Point p2)
{
  this->p1 = p1;
  this->p2 = p2;
  thikness = 1;
}

Line::Line(Point p1, Point p2, int thikness)
{
  this->p1 = p1;
  this->p2 = p2;
  this->thikness = thikness;
}

void Line::setPoint1( Point x)
{
  p1 = x;
}

Point Line::getPoint1()
{
  return p1;
}

void Line::setPoint2( Point x)
{
  p2 = x;
}

Point Line::getPoint2()
{
  return p2;
}

void Line::setThikness( int x)
{
  thikness = x;
}

void Line::drawLineDDA() //Digital differential analyzer
{
  double dx, dy, xInc, yInc, steps, x, y; //dx = diferencial de x //dy = diferencial de y

  dx = (double)(p2.getX() - p1.getX());
  dy = (double)(p2.getY() - p1.getY());

  if( abs(dx) > abs(dy) )
    steps = abs(dx);
  else
    steps = abs(dy);

  xInc = dx / steps;
  yInc = dy / steps;

  Point tempP = Point();
  x = (double)p1.getX();
  y = (double)p1.getY();

  tempP.draw((GLdouble)round(x), (GLdouble)round(y), thikness);

  for(int i = 1; i <= steps; i++)
  {
    x += xInc;
    y += yInc;
    tempP.draw((GLdouble)round(x), (GLdouble)round(y), thikness);
  }
}
