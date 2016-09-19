#include "Point.h"

Point::Point()
{
  x = y = 0.0;
}

Point::Point(GLdouble x, GLdouble y)
{
  this->x = x;
  this->y = y;
}

void Point::setPoint(GLdouble x, GLdouble y)
{
  this->x = x;
  this->y = y;
};

void Point::setX(GLdouble x)
{
  this->x = x;
};

void Point::setY(GLdouble y)
{
  this->y = y;
};

GLdouble Point::getX()
{
  return x;
};

GLdouble Point::getY()
{
  return y;
};


void Point::draw(int size)
{
  glPointSize(size);
  glBegin(GL_POINTS);
    glVertex2d(x,y);
  glEnd();
}

void Point::draw(GLdouble x, GLdouble y, int size)
{
  glPointSize(size);
  glBegin(GL_POINTS);
    glVertex2d(x,y);
  glEnd();
}
