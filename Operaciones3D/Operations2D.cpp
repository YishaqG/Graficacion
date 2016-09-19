#include "Operations2D.h"

Operations2D::Operations2D(){};

Operations2D::~Operations2D(){};

void Operations2D::translation(Point &toOperate, Point pTo)
{
  //Matrix to translate
  Matrix traslador( MOVE_TO, (double)pTo.getX(), (double)pTo.getY());

  //Matrix to multiply and store the resulting transferred point
  Matrix resulting( DEFAULT, (double)toOperate.getX(), (double)toOperate.getY() );

  //Matrix multiplication
  traslador.mult(resulting);

  //Update point
  toOperate.setPoint( (GLdouble)resulting.getElm(0, 0), (GLdouble)resulting.getElm(1, 0) );

};

void Operations2D::scale(Point &toOperate, Point toGrow)
{
  //Matrix to move the point to operate to the origin
  Matrix moveToOrigin(TO_ORIGIN, (double)toOperate.getX(), (double)toOperate.getY());

  //Matrix to scale the point into the wish scale
  Matrix toScale(SCALE, (double)toGrow.getX(), (double)toGrow.getY());

    //Multiplication of the matrix
    moveToOrigin.mult(toScale);

  //Matrix to return the point to its origianl position
  Matrix moveToOriginalPos(MOVE_TO, (double)toOperate.getX(), (double)toOperate.getY());

    //Multiplication of the matrix
    toScale.mult(moveToOriginalPos);

  //Matrix to multiply and store the resulting scale point
  Matrix resulting( DEFAULT, (double)toOperate.getX(), (double)toOperate.getY() );

    //Finaly operate over the point
    moveToOriginalPos.mult(resulting);

    //Update point
    toOperate.setPoint( (GLdouble)resulting.getElm(0, 0), (GLdouble)resulting.getElm(1, 0));
}

void Operations2D::rotate(Point &toOperate, int toRotate)
{

  //Matrix to move the point to operate to the origin
  Matrix moveToOrigin(TO_ORIGIN, (double)toOperate.getX(), (double)toOperate.getY());

  //Matrix to rotate
  Matrix rotator( ROTATE, 0.0, 0.0, toRotate);

  //Multiplication of the matrix
  moveToOrigin.mult(rotator);

  //Matrix to return the point to its origianl position
  Matrix moveToOriginalPos(MOVE_TO, (double)toOperate.getX(), (double)toOperate.getY());

  //Multiplication of the matrix
  rotator.mult(moveToOriginalPos);

  //Matrix to multiply and store the resulting transferred point
  Matrix resulting( DEFAULT, (double)toOperate.getX(), (double)toOperate.getY() );

  //Matrix multiplication
  moveToOriginalPos.mult(resulting);

  //Update point
  toOperate.setPoint( (GLdouble)resulting.getElm(0, 0), (GLdouble)resulting.getElm(1, 0));
}

void Operations2D::deform(Point &toOperate, int toDeform, int what)
{
  //Matrix to multiply and store the resulting transferred point
  Matrix resulting( DEFAULT, (double)toOperate.getX(), (double)toOperate.getY() );

  // /*1_To create the deforming matrix*/
  // if(what == DEFORM_X)
  // {
  //   Matrix deformingX(DEFORM, 1.0, 0.0, toDeform); //To deformate X
  //   //Matrix to move the point to operate to the origin
  //   Matrix moveToOrigin(TO_ORIGIN, (double)toOperate.getX(), (double)toOperate.getY());
  //   moveToOrigin.mult(deformingX);
  //   //Matrix to return the point to its origianl position
  //   Matrix moveToOriginalPos(MOVE_TO, (double)toOperate.getX(), (double)toOperate.getY());
  //   deformingX.mult(moveToOriginalPos);
  //   moveToOriginalPos.mult(resulting);
  // }
  // else
  //   if(what == DEFORM_Y)  //To deformate y
  //   {
  //     Matrix deformingY(DEFORM, 0.0, 1.0, toDeform);
  //     //Matrix to move the point to operate to the origin
  //     Matrix moveToOrigin(TO_ORIGIN, (double)toOperate.getX(), (double)toOperate.getY());
  //     moveToOrigin.mult(deformingY);
  //     //Matrix to return the point to its origianl position
  //     Matrix moveToOriginalPos(MOVE_TO, (double)toOperate.getX(), (double)toOperate.getY());
  //     deformingY.mult(moveToOriginalPos);
  //     moveToOriginalPos.mult(resulting);
  //   }
  //   else  //To deformate xy
  //   {
  //     Matrix deformingXY(DEFORM, 1.0, 1.0, toDeform);
  //     //Matrix to move the point to operate to the origin
  //     Matrix moveToOrigin(TO_ORIGIN, (double)toOperate.getX(), (double)toOperate.getY());
  //     moveToOrigin.mult(deformingXY);
  //     //Matrix to return the point to its origianl position
  //     Matrix moveToOriginalPos(MOVE_TO, (double)toOperate.getX(), (double)toOperate.getY());
  //     deformingXY.mult(moveToOriginalPos);
  //     moveToOriginalPos.mult(resulting);
  //   }
  // /*0_To create the deforming matrix*/

  /*1_To create the deforming matrix*/
  if(what == DEFORM_X)
  {
    Matrix deformingX(DEFORM, 1.0, 0.0, toDeform); //To deformate X
    deformingX.mult(resulting);
  }
  else
    if(what == DEFORM_Y)  //To deformate y
    {
      Matrix deformingY(DEFORM, 0.0, 1.0, toDeform);
      deformingY.mult(resulting);
    }
    else  //To deformate xy
    {
      Matrix deformingXY(DEFORM, 1.0, 1.0, toDeform);
      deformingXY.mult(resulting);
    }
  /*0_To create the deforming matrix*/

  //Update point
  toOperate.setPoint( (GLdouble)resulting.getElm(0, 0), (GLdouble)resulting.getElm(1, 0));
}

void Operations2D::reflection(Point &toOperate, Point axis)
{
  /*To create the traslador matrix*/
  Matrix traslador(MOVE_TO, (double)axis.getX(), (double)axis.getY());

  /*To set reflexion matrix*/
  Matrix reflecting(REFLECTION, (double)axis.getX(), (double)axis.getY());

    traslador.mult(reflecting);

  Matrix moveToOriginalPos(TO_ORIGIN, (double)axis.getX(), (double)axis.getY());

    reflecting.mult(moveToOriginalPos);


  //Matrix to multiply and store the resulting transferred point
  Matrix resulting( DEFAULT, (double)toOperate.getX(), (double)toOperate.getY() );

    //Matrix multiplication
    moveToOriginalPos.mult(resulting);

    //Update point
    toOperate.setPoint( (GLdouble)resulting.getElm(0, 0), (GLdouble)resulting.getElm(1, 0));
}
