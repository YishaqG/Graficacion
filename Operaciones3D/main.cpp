// #include "Poligono.h"
#include "Poligono3D.h"
#ifndef IO
  #include <stdio.h>
  #define IO
#endif

void init();
void draw();

int main(int argc, char** argv)
{
     //Se inicializa la pantalla grafica
     glutInit(&argc, argv);
     //Establece el modo de visualizacion
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
     //Establece la posicion de la esquina superior izquierda del grafico en la pantalla
     glutInitWindowPosition(100, 100);
     //Se establece el ancho y la altura de la ventana de visualizacion
     glutInitWindowSize(400, 400);
     //Se crea la ventana de visualización
     glutCreateWindow("Poligones");
     //Se ejecuta la funcion de inicializacion de parametros
     init();

     //Callback a la funcion que dibujara objetos de la pantalla
     glutDisplayFunc(draw);

     //Loop to avoid the execution end
     glutMainLoop();
     return 0;
}

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1000, 1000, -1000, 1000, -1000, 1000);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluPerspective(60,0,200,200);
  // gluLookAt(5, 0, 5, 3, 0, -3, 0, 1, 0);
  //EYE=(0,0,0) at the origin
  //AT=(0,0,-100) pointing at negative-z axis (into the screen)
  //UP=(0,1,0) corresponds to y-axis.
}

void draw()
{
  glClear(GL_COLOR_BUFFER_BIT); //Borra el buffer
  glColor3f(1.0, 00, 0.0);

  Poligono3D p = Poligono3D();

  //p.move( Point( (GLdouble)200.0,  (GLdouble)200.0) );
  //p.scale( Point( (GLdouble)2.0,  (GLdouble)2.0) );
  // p.rotate(ROTATE_X,30);
  //p.deform(2, DEFORM_Y);
  //p.reflect( Point( (GLdouble)0.0,  (GLdouble)200.0) );

  p.draw(3);

  glFlush();
};
