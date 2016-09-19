#include "Operations3D.h"

Operations3D::Operations3D(){};

Operations3D::~Operations3D(){};

// void Operations3D::translation(Point3D &toOperate, Point3D pTo)
// {
//   //
// };
//
// void Operations3D::scale(Point3D &toOperate, Point3D toGrow)
// {
//   //
// }

void Operations3D::rotate(int flag, Point3D &toOperate, int toRotate)
{

  //Matrix to move the Point3D to operate to the origin
  // Matrix moveToOrigin(TO_ORIGIN, (double)toOperate.getX(), (double)toOperate.getY());

  //Matrix to rotate
  Matrix rotator(flag, 0.0, 0.0, 0.0, toRotate);

  //Multiplication of the matrix
  // moveToOrigin.mult(rotator);

  //Matrix to return the Point3D to its origianl position
  // Matrix moveToOriginalPos(MOVE_TO, (double)toOperate.getX(), (double)toOperate.getY());

  //Multiplication of the matrix
  // rotator.mult(moveToOriginalPos);

  //Matrix to multiply and store the resulting transferred Point3D
  Matrix resulting( DEFAULT, (double)toOperate.getX(), (double)toOperate.getY(), (double)toOperate.getZ(), 0.0);

  //Matrix multiplication
  rotator.mult(resulting);

  //Update Point3D
  toOperate.setPoint( (GLdouble)resulting.getElm(0, 0), (GLdouble)resulting.getElm(1, 0), (GLdouble)resulting.getElm(2, 0));
}

// void Operations3D::deform(Point3D &toOperate, int toDeform, int what)
// {
//   //
// }
//
// void Operations3D::reflection(Point3D &toOperate, Point3D axis)
// {
//   //
// }
