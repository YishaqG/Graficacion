#ifndef GLUT
  #include <GL/glut.h>
  #define GLUT
#endif

class Point
{
  private:
    GLdouble x, y;

  public:
  //Builders
    Point();
    Point(GLdouble, GLdouble);
  //Destroyers
  //Methods
    void setPoint(GLdouble, GLdouble);
    void setX(GLdouble);
    void setY(GLdouble);
    GLdouble getX();
    GLdouble getY();
    void draw(int);
    void draw(GLdouble, GLdouble, int);
};
