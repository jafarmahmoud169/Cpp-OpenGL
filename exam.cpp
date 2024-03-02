#include<iostream>
#include<Windows.h>
#include<GLUT.h>
#include<cmath>
using namespace std;
float sunrot=0,ghx=-20;

float i=270.0;	

float xeye=0;
float yeye=0;
float zeye=100;

float xcenter=0;
float ycenter=0;
float zcenter=0;


void specialKeys(int key, int x, int y);
static void redraw(void);
int main(int argc, char **argv)
{
	
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(200,00);
	glutInitWindowSize(1000,1000);
   	glutCreateWindow("First Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,0.0,400.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}		


static void redraw(void)
{
		glClearColor(0.52,0.80,0.92,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);glutSpecialFunc(specialKeys);
	glLoadIdentity();	  gluLookAt(xeye,yeye,zeye,   xcenter,ycenter,zcenter,   0,1,0);			

/////////////////////////////////////////////////////////
	//ground
	glBegin(GL_POLYGON);
	   glColor3f(0.3,0.6,0.3);
		glVertex3f(-100,-10,10);
		glVertex3f(200,-10,10);
		glVertex3f(250,-150,10);
		glVertex3f(-100,-150,10);
	glEnd();
	 //sun
		 glPushMatrix();
	 	 glRotatef(sunrot,0,0,1);
	 glTranslatef(30,25,0);

	 glColor3f(1,1,0);
	 	glLineWidth(5);
  glutSolidSphere(3.7,30,30);
  
		glBegin(GL_LINES);
	   glVertex3f(3.7,0,0);
	   glVertex3f(6,0,0);
	   glVertex3f(0,3.7,0);
	   glVertex3f(0,6,0);

	   glVertex3f(-3.7,0,0);
	   glVertex3f(-6,0,0);
	   glVertex3f(0,-3.7,0);
	   glVertex3f(0,-6,0);
     glEnd();
	 //////////////////
	 glPushMatrix();
	 glRotatef(45,0,0,1);
	   glBegin(GL_LINES);
	   glVertex3f(3.7,0,0);
	   glVertex3f(6,0,0);
	   glVertex3f(0,3.7,0);
	   glVertex3f(0,6,0);

	   glVertex3f(-3.7,0,0);
	   glVertex3f(-6,0,0);
	   glVertex3f(0,-3.7,0);
	   glVertex3f(0,-6,0);
     glEnd();
	 glPopMatrix();
	 //////////
glPopMatrix();
/////////////////////€Ì„
  glPushMatrix();
  	 glTranslatef(ghx+20,30,0);
  		glColor3f(1,1.0,1.0);
   glScalef(14,6,0);
 glutSolidSphere(0.5,30,30);
  glPopMatrix();
    glPushMatrix();
		 glTranslatef(ghx-10,30,0);
			glColor3f(1,1.0,1.0);
   glScalef(14,6,0);
 glutSolidSphere(0.5,30,30);
  glPopMatrix();
  //////
    glPushMatrix();
  	 glTranslatef(ghx+20,32,0);
  		glColor3f(1,1.0,1.0);
   glScalef(8,6,0);
 glutSolidSphere(0.5,30,30);
  glPopMatrix();
    glPushMatrix();
		 glTranslatef(ghx-10,32,0);
			glColor3f(1,1.0,1.0);
   glScalef(8,6,0);
 glutSolidSphere(0.5,30,30);
  glPopMatrix();
//flours

  	 glPushMatrix();
		glColor3f(0,1.0,0);
	   glBegin(GL_LINES);
	   glVertex3f(0,-16,0);
	   glVertex3f(0,0,0);

	   glVertex3f(14,-16,0);
	   glVertex3f(14,0,0);

	   glVertex3f(-14,-16,0);
	   glVertex3f(-14,0,0);
     glEnd();
	 glPopMatrix();
///////////////////////////flouer1
glPushMatrix();

glRotatef(sunrot-55,0,0,1);glRotatef(80,1,0,0);
glPushMatrix();
  glPushMatrix();
  glScalef(2,2,2);
  glColor3f(1,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,-3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0,3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
  ///
    glPushMatrix();  glRotatef(45,0,0,1);
  glTranslatef(0,-3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(-3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(0,3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

glPopMatrix();
glPopMatrix();
/////////////////////////////////////////////////////
///////////////////////////flouer2
glPushMatrix();
glTranslatef(14,0,0);glRotatef(sunrot-55,0,0,1);glRotatef(80,1,0,0);
glPushMatrix();
  glPushMatrix();
  glScalef(2,2,2);
  glColor3f(1,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,-3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0,3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
  ///
    glPushMatrix();  glRotatef(45,0,0,1);
  glTranslatef(0,-3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(-3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(0,3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

glPopMatrix();
glPopMatrix();
///////////////////////
///////////////////////////flouer3
glPushMatrix();
glTranslatef(-14,0,0);glRotatef(sunrot-55,0,0,1);glRotatef(80,1,0,0);
glPushMatrix();
  glPushMatrix();
  glScalef(2,2,2);
  glColor3f(1,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0,-3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0,3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
  ///
    glPushMatrix();  glRotatef(45,0,0,1);
  glTranslatef(0,-3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(-3,0,0);
  glScalef(4,1,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

  glPushMatrix();glRotatef(45,0,0,1);
    glTranslatef(0,3,0);
  glScalef(1,4,1);  glColor3f(1,1,1);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();

glPopMatrix();
glPopMatrix();
///////////////////«·Ê—ﬁ
  glPushMatrix();
    glTranslatef(-1,-6,0);
  glRotatef(-45,0,0,1);
  glScalef(3,1,1);  glColor3f(0,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
//
    glPushMatrix();
    glTranslatef(1,-8,0);
  glRotatef(45,0,0,1);
  glScalef(3,1,1);  glColor3f(0,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
  ///2
    glPushMatrix();
    glTranslatef(-15,-6,0);
  glRotatef(-45,0,0,1);
  glScalef(3,1,1);  glColor3f(0,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
//
    glPushMatrix();
    glTranslatef(-13,-8,0);
  glRotatef(45,0,0,1);
  glScalef(3,1,1);  glColor3f(0,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
  ////3
    glPushMatrix();
    glTranslatef(13,-6,0);
  glRotatef(-45,0,0,1);
  glScalef(3,1,1);  glColor3f(0,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
//
    glPushMatrix();
    glTranslatef(15,-8,0);
  glRotatef(45,0,0,1);
  glScalef(3,1,1);  glColor3f(0,1,0);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
/////////////////////////////////////////////////movement
  if(sunrot<140){
  sunrot+=0.1;
  }else sunrot=140;
ghx+=0.08;


//////////////////////////////////////////////////////////
	glutPostRedisplay();
	glutSwapBuffers();
}
//////////////////////////////////////////////////////////////////
void specialKeys(int key, int x, int y) {
    switch (key) {
	case GLUT_KEY_UP:
            xeye = xeye +0.001 * (xcenter - xeye);
			zeye = zeye +0.001 * (zcenter - zeye);
    break;
    case GLUT_KEY_DOWN:        
			xeye = xeye -0.001 * (xcenter - xeye);
			zeye = zeye -0.001 * (zcenter - zeye);
    break;
	case GLUT_KEY_LEFT: 
			xcenter = 1000 * cos(i * 3.14 / 180) - xeye;
			zcenter = 1000 * sin(i * 3.14 / 180) - zeye;
			i -= 2;
    break;
    case GLUT_KEY_RIGHT: 
			xcenter = 1000 * cos(i * 3.14  / 180) - xeye;
			zcenter = 1000 * sin(i * 3.14 / 180) - zeye;
			i += 2;break;
    default:break;
    }
}