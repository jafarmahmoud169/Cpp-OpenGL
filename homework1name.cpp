#include <windows.h>  // for MS Windows
#include <glut.h>  // GLUT, include glu.h and gl.h
static void redraw(void);
int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(1100,700);
     glutCreateWindow("First Example");
  glutDisplayFunc(redraw);  
  glMatrixMode(GL_PROJECTION);          
  gluPerspective(45,1.0,5.0,100.0);
  glMatrixMode(GL_MODELVIEW);
  glutMainLoop();
  return 0; 
}    

static void redraw(void)
{
  glClearColor(0.5,0.5,0.5,0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();        
  glTranslatef(-1.5f,0.0f,-40.0f);
  glColor3f(0.0,1.0,1.0);
  glLineWidth(5);
  glBegin(GL_LINES);
  //JAFAR
    //J
    glVertex2f(-10,2);
    glVertex2f(-10,1);
    glVertex2f(-10,1);
    glVertex2f(-8,1);
    glVertex2f(-8,1);
    glVertex2f(-8,5);
    glVertex2f(-10,5);
    glVertex2f(-6,5);
    //A
    glVertex2f(-6,1);
    glVertex2f(-4,5);
    glVertex2f(-4,5);
    glVertex2f(-2,1);
    glVertex2f(-5,3);
    glVertex2f(-3,3);
    //F
    glVertex2f(-1,1);
    glVertex2f(-1,5);
    glVertex2f(-1,5);
    glVertex2f(1,5);
    glVertex2f(-1,3);
    glVertex2f(1,3);
    //A
    glVertex2f(1,1);
    glVertex2f(3,5);
    glVertex2f(3,5);
    glVertex2f(5,1);
    glVertex2f(2,3);
    glVertex2f(4,3);
    //R
    glVertex2f(6,1);
    glVertex2f(6,5);
    glVertex2f(6,5);
    glVertex2f(8,5);
    glVertex2f(8,5);
    glVertex2f(8,3);
    glVertex2f(8,3);
    glVertex2f(6,3);
    glVertex2f(6,3);
    glVertex2f(8,1);
    
  //mahmoud
    //M
    glVertex2f(-15,-5);
    glVertex2f(-14,-1);
    glVertex2f(-14,-1);
    glVertex2f(-13,-5);
    glVertex2f(-13,-5);
    glVertex2f(-12,-1);
    glVertex2f(-12,-1);
    glVertex2f(-11,-5);

    //A
    glVertex2f(-10,-5);
    glVertex2f(-8,-1);
    glVertex2f(-8,-1);
    glVertex2f(-6,-5);
    glVertex2f(-9,-3);
    glVertex2f(-7,-3);

    //H
    glVertex2f(-5,-5);
    glVertex2f(-5,-1);
    glVertex2f(-3,-1);
    glVertex2f(-3,-5);
    glVertex2f(-5,-3);
    glVertex2f(-3,-3);

    //M
    glVertex2f(-2,-5);
    glVertex2f(-1,-1);
    glVertex2f(-1,-1);
    glVertex2f(0,-5);
    glVertex2f(0,-5);
    glVertex2f(1,-1);
    glVertex2f(1,-1);
    glVertex2f(2,-5);

    //O
    glVertex2f(3,-2);
    glVertex2f(3,-4);
    glVertex2f(3,-4);
    glVertex2f(4,-5);
    glVertex2f(4,-5);
    glVertex2f(5,-5);
    glVertex2f(5,-5);
    glVertex2f(6,-4);
    glVertex2f(6,-4);
    glVertex2f(6,-2);
    glVertex2f(6,-2);
    glVertex2f(5,-1);
    glVertex2f(5,-1);
    glVertex2f(4,-1);
    glVertex2f(4,-1);
    glVertex2f(3,-2);

    //U
    glVertex2f(7,-1);
    glVertex2f(7,-4);
    glVertex2f(7,-4);
    glVertex2f(8,-5);
    glVertex2f(8,-5);
    glVertex2f(9,-5);
    glVertex2f(9,-5);
    glVertex2f(10,-4);
    glVertex2f(10,-4);
    glVertex2f(10,-1);

    //D
    glVertex2f(11,-1);
    glVertex2f(11,-5);
    glVertex2f(11,-5);
    glVertex2f(13,-5);
    glVertex2f(13,-5);
    glVertex2f(14,-4);
    glVertex2f(14,-4);
    glVertex2f(14,-2);
    glVertex2f(14,-2);
    glVertex2f(13,-1);
    glVertex2f(13,-1);
    glVertex2f(11,-1);

  glEnd();
  
    

glutSwapBuffers();
}