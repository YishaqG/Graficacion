#ifndef MATRIX
  #include "Matrix.h"
  #define MATRIX
#endif

#ifndef STRING
  #include "string.h"
  #define STRING
#endif

  // Matrix::Matrix(double x, double y):Matrix(DEFAULT, x, y)
  // {
  //   this.Matrix(DEFAULT, x, y);
  // } Error cuando se llama a este constructor sin :Matrix(DEFAULT, x, y)

  /*1_This constructor initialize the matrix for translate, move origin, scale, reflection
   and the vector of the point to operate*/
  Matrix::Matrix(int flag, double x, double y)
  {
    rows = EXTENDED_2D_MATRIX;
    colums = EXTENDED_2D_MATRIX;
    switch(flag)
    {
      case DEFAULT:
          colums = 1;
          create();
          matrix[0][0] = x;
          matrix[1][0] = y;
        break;
      case MOVE_TO:
          create();
          matrix[0][2] = x;
          matrix[1][2] = y;
        break;
      case TO_ORIGIN:
          create();
          matrix[0][2] = (-1)*x;
          matrix[1][2] = (-1)*y;
        break;
      case SCALE:
          create();
          matrix[0][0] = x;
          matrix[1][1] = y;
        break;
      case REFLECTION:
        create();
        if( (x != 0.0) && (y == 0.0) ) //If we want reflex over Y
          matrix[0][0] *= -1;
        else
          if( (x == 0.0) && (y != 0.0) ) //If we want reflex over Y
            matrix[1][1] *= -1;
          else  //If we want reflex over X&Y
          {
            matrix[0][0] *= -1;
            matrix[1][1] *= -1;
          }
        break;
      default:
        break;
    }
  }
  /*0_*/

  /*1_This constructor initialize the matrix for rotate and deform*/
  Matrix::Matrix(int flag, double x, double y, double delta)
  {
    rows = EXTENDED_2D_MATRIX;
    colums = EXTENDED_2D_MATRIX;
    switch(flag)
    {
      case ROTATE:
          create();
          /*1_For X*/
          matrix[0][0] = cos((delta*PI)/180);
          matrix[0][1] = sin((delta*PI)/180);
          /*0_For X*/
          /*1_For Y*/
          matrix[1][0] = sin((delta*PI)/180);
          matrix[1][1] = cos((delta*PI)/180);
          /*0_For Y*/
        break;
      case DEFORM:
        create();
        if( (x != 0.0) && (y == 0.0) ) //If we want deform x
          matrix[0][1] = delta;
        else
          if( (x == 0.0) && (y != 0.0) ) //If we want deform y
            matrix[1][0] = delta;
          else  //If we want deform both
          {
            matrix[0][1] = delta;
            matrix[1][0] = delta;
          }
        break;
      default:
        break;
    }
  }
  /*0_*/

  /*This constructor initialize the matrix for rotate*/
  Matrix::Matrix(int flag, double x, double y, double z, double delta)
  {
    rows = EXTENDED_3D_MATRIX;
    colums = EXTENDED_3D_MATRIX;
    switch(flag)
    {
      case ROTATE_Z: //Rotation over Z axis
          create();
          /*1_For X*/
          matrix[0][0] = cos((delta*PI)/180);
          matrix[0][1] = -1*sin((delta*PI)/180);
          /*0_For X*/
          /*1_For Y*/
          matrix[1][0] = sin((delta*PI)/180);
          matrix[1][1] = cos((delta*PI)/180);
          /*0_For Y*/
        break;
      case ROTATE_Y: //Rotation over Y axis
          create();
          /*1_For X*/
          matrix[0][0] = cos((delta*PI)/180);
          matrix[0][2] = -1*sin((delta*PI)/180);
          /*0_For X*/
          /*1_For Y*/
          matrix[2][0] = sin((delta*PI)/180);
          matrix[2][2] = cos((delta*PI)/180);
          /*0_For Y*/
        break;
      case ROTATE_X: //Rotation over X axis
          create();
          /*1_For X*/
          matrix[1][1] = cos((delta*PI)/180);
          matrix[1][2] = -1*sin((delta*PI)/180);
          /*0_For X*/
          /*1_For Y*/
          matrix[2][1] = sin((delta*PI)/180);
          matrix[2][2] = cos((delta*PI)/180);
          /*0_For Y*/
        break;
      case DEFAULT:
          colums = 1;
          create();
          matrix[0][0] = x;
          matrix[1][0] = y;
          matrix[2][0] = z;
        break;
    }
  }

  /*1_Destructor to deallocate memory for the matrix*/
  Matrix::~Matrix()
  {
    for(int i = 0; i < rows; i++)
      delete[] matrix[i];
    delete[] matrix;
  }
  /*0_*/

  /*1_Function to allocate the memory and initialize the matrix*/
  void Matrix::create()
  {
    matrix = new double*[rows];
    for(int i = 0; i < rows; i++)
    {
      matrix[i] = new double[colums];

      if(colums > 1)
        for(int j = 0; j < colums; j++) //Cicle to initialize the matrix
        {
          if( j == i )
            matrix[i][j] = 1.0;
          else
            matrix[i][j] = 0.0;
        }
      else
          matrix[i][0] = 1.0;
    }
  }
  /*0_*/

  void Matrix::mult(Matrix &bMatrix)
  {
    double auxArray[rows]; //Auxiliar array to save the resulting vectors
    memset(auxArray, 0.0, sizeof(double)*rows );

    /*1_Cicle to multiply*/
    for(int i = 0; i < bMatrix.getColums(); i++)  //By number of colums for the second matrix
    {
      for(int j = 0; j < rows; j++) //Rows of the first matrix
        for(int k = 0; k < colums; k++) //Colums of the first matrix (both must have the same)
          auxArray[j] += matrix[j][k] * bMatrix.getElm(k, i); //Mult and saving in vector

      /*1_Cicle to pass the auxArray to a colum of the second matrix*/
      for(int j = 0; j < rows; j++)
      {
        bMatrix.setElm(j, i, auxArray[j]); //Passing elements
        auxArray[j] = 0;  //Reseting auxArray
      }
      /*0_Cicle to pass the auxArray to a colum of the second matrix*/
    }
    /*0_Cicle to multiply*/
  }

  int Matrix::getRows(){return rows;}
  int Matrix::getColums(){return colums;}

  double Matrix::getElm(int i, int j)
  {
    return matrix[i][j];
  }

  void Matrix::setElm(int i, int j, double x)
  {
    matrix[i][j] = x;
  }
