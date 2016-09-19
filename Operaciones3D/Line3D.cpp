#include "Line3D.h"

Line3D::Line3D()
{
  p1 = Point3D((GLdouble)0.0, (GLdouble)0.0, (GLdouble)0.0);
  p2 = Point3D((GLdouble)0.0, (GLdouble)0.0, (GLdouble)0.0);
  thikness = 1;
}

Line3D::Line3D(Point3D p1, Point3D p2)
{
  this->p1 = p1;
  this->p2 = p2;
  thikness = 1;
}

Line3D::Line3D(Point3D p1, Point3D p2, int thikness)
{
  this->p1 = p1;
  this->p2 = p2;
  this->thikness = thikness;
}

void Line3D::setPoint1( Point3D x)
{
  p1 = x;
}

Point3D Line3D::getPoint1()
{
  return p1;
}

void Line3D::setPoint2( Point3D x)
{
  p2 = x;
}

Point3D Line3D::getPoint2()
{
  return p2;
}

void Line3D::setThikness( int x)
{
  thikness = x;
}

void Line3D::draw() //Digital differential analyzer
{
  glLineWidth(thikness);
  glBegin(GL_LINES);
    glVertex3d(p1.getX(), p1.getY(), p1.getZ());
    glVertex3d(p2.getX(), p2.getY(), p2.getZ());
  glEnd();
}
