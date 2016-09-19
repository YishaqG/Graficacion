#include "Point3D.h"

Point3D::Point3D()
{
  x = y = 0.0;
}

Point3D::Point3D(GLdouble x, GLdouble y, GLdouble z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

void Point3D::setPoint(GLdouble x, GLdouble y, GLdouble z)
{
  this->x = x;
  this->y = y;
  this->z = z;
};

void Point3D::setX(GLdouble x)
{
  this->x = x;
};

void Point3D::setY(GLdouble y)
{
  this->y = y;
};

void Point3D::setZ(GLdouble z)
{
  this->z = z;
};

GLdouble Point3D::getX()
{
  return x;
};

GLdouble Point3D::getY()
{
  return y;
};

GLdouble Point3D::getZ()
{
  return z;
};


void Point3D::draw(int size)
{
  glPointSize(size);
  glBegin(GL_POINTS);
    glVertex3d(x,y,z);
  glEnd();
}
