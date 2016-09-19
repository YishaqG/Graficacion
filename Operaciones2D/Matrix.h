#ifndef MATH
  #include <math.h>
  #define MATH
#endif

#ifndef IO
  #include <stdio.h>
  #define IO
#endif

#define PI 3.141592

#define DEFAULT 0
#define MOVE_TO 1
#define TO_ORIGIN 2
#define SCALE 3
#define ROTATE 4
#define DEFORM 5
#define REFLECTION 6

#define EXTENDED_2D_MATRIX 3
#define EXTENDED_3D_MATRIX 4

class Matrix
{
  private:
    /*1_Variables*/
      double **matrix;
      int rows, colums;
    /*0_Variables*/

    /*1_Methods*/
      void create();
    /*0_Methods*/
  public:
    /*1_Builders & Destructors*/
      // Matrix(double, double);
      Matrix(int, double, double); //DEFAULT, MOVE_TO, TO_ORIGIN, SCALE
      Matrix(int, double, double, double); //ROTATE, DEFORM
      ~Matrix();
    /*0_Builders & Destructors*/

    /*1_Methods*/
      void mult(Matrix&);
      int getRows();
      int getColums();
      double getElm(int, int);
      void setElm(int, int, double);
    /*0_Methods*/
};
