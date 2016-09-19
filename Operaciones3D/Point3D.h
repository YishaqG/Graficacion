#ifndef GLUT
  #include <GL/glut.h>
  #define GLUT
#endif

class Point3D
{
  private:
    GLdouble x, y, z;

  public:
  //Builders
    Point3D();
    Point3D(GLdouble, GLdouble, GLdouble);
  //Destroyers
  //Methods
    void setPoint(GLdouble, GLdouble, GLdouble);
    void setX(GLdouble);
    void setY(GLdouble);
    void setZ(GLdouble);
    GLdouble getX();
    GLdouble getY();
    GLdouble getZ();
    void draw(int);
};
