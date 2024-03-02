#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
static void redraw(void);
int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(1100,1100);
     glutCreateWindow("First Example");
  glutDisplayFunc(redraw);  
  glMatrixMode(GL_PROJECTION);          
  gluPerspective(45,1.0,5.0,40.0);
  glMatrixMode(GL_MODELVIEW);
  glutMainLoop();
  return 0; 
}    
float l=0,r=0;
bool flagd=false,flagu=true;
bool flagr=false,flagl=true;
static void redraw(void)
{
  glClearColor(1,1,1,0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();        
  glTranslatef(0.0f,0.0f,-20.0f);
  
  glLineWidth(3);
  glBegin(GL_LINE_LOOP);
  glColor3f(0.0,0,0);
  glVertex2f(-2.3,0);
  glVertex2f(2.3,0);
  glVertex2f(2.3,6);
  glVertex2f(-2.3,6);
  glEnd();
  glBegin(GL_POLYGON);
  glColor3f(0.5,0.3,0);
  glVertex2f(-3,0);
  glVertex2f(3,0);
  glVertex2f(3,-0.7);
  glVertex2f(-3,-0.7);
  glEnd();
  glBegin(GL_LINES);
  glColor3f(0,0,0);
  glVertex2f(0,1);
  glVertex2f(0,6);
  glVertex2f(0.7,1);
  glVertex2f(0.7,6);
  glVertex2f(-0.7,1);
  glVertex2f(-0.7,6);
  glEnd();
	 glPushMatrix();
	 glColor3f(0.5,0.5,0.5);
	 glTranslatef(0,1,0);
	 glutSolidSphere(0.35,100,100);
	 glPopMatrix();
	 	 glPushMatrix();
	 glColor3f(0.5,0.5,0.5);
	 glTranslatef(0.7,1,0);
	 glutSolidSphere(0.35,100,100);
	 glPopMatrix();
	 	 glPushMatrix();
	 glColor3f(0.5,0.5,0.5);
	 glTranslatef(-0.7,1,0);
	 glutSolidSphere(0.35,100,100);
	 glPopMatrix();


  if (flagl){
    if (flagu){
    if(l>-20)l--;
    else {flagu=false;flagd=true;}
    }
    else if(flagd){
    if(l<0)l++;
    else{flagd=false;flagu=true;flagl=false;flagr=true;}
    }
  }




  else if (flagr){
    if (flagu){
    if(r<20)r++;
    else {flagu=false;flagd=true;}
    }
    else if(flagd){
    if(r>0)r--;
    else{flagd=false;flagu=true;flagr=false;flagl=true;}
    }
  }



  glPushMatrix();
  glTranslatef(-1.4,6,0);
  glRotatef(l,0,0,1);
  glBegin(GL_LINES);
  glColor3f(0,0,0);
  glVertex2f(0,0);
  glVertex2f(0,-5);
  glEnd();

  glColor3f(0.5,0.5,0.5);
  glTranslatef(0,-5,0);
  glRotatef(l,0,0,1);
  glutSolidSphere(0.35,100,100);
  glPopMatrix();


  glPushMatrix();
  glTranslatef(1.4,6,0);
  glRotatef(r,0,0,1);
  glBegin(GL_LINES);
  glColor3f(0,0,0);
  glVertex2f(0,0);
  glVertex2f(0,-5);
  glEnd();

  glColor3f(0.5,0.5,0.5);
  glTranslatef(0,-5,0);
  glRotatef(r,0,0,1);
  glutSolidSphere(0.35,100,100);
  glPopMatrix();






glutPostRedisplay();
glutSwapBuffers();
}