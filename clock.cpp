#include<iostream>
#include<Windows.h>
#include<GLUT.h>
#include<cmath>
using namespace std;
/////////////////////////////////////////////////////////////////////////
////////////you can change the speed to 10 or to 100 ////////////////////
int speed=1;///////////////////////////////////////////////////////////
///////////you can change the starting time//////////////////////////////
int hh=2,mm=44;//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
float s=0,m=mm*-6,l=0, h=(hh*-30)-(mm*0.5);
float i=270.0;	

float xeye=0;
float yeye=0;
float zeye=5;

float xcenter=0;
float ycenter=0;
float zcenter=0;

bool fleft=true; bool fright=false;
void specialKeys(int key, int x, int y);void light();
static void redraw(void);
int main(int argc, char **argv)
{
	
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(500,100);
	glutInitWindowSize(700,700);
   	glutCreateWindow("First Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,0.0,400.0);light();
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}		


static void redraw(void)
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);glutSpecialFunc(specialKeys);
	glLoadIdentity();	  gluLookAt(xeye,yeye,zeye,   xcenter,ycenter,zcenter,   0,1,0);			
    glTranslatef(0,0.0f,-65.0f);
///////////////////////////////////////////////
	//body
	glPushMatrix();
	///////////coloring
		glBegin(GL_QUADS);
	   glColor3f(0.6,0.3,0.0);
	   	glVertex2f(-8,6);
		glVertex2f(0,12);
		glVertex2f(8,6);
		glVertex2f(-8,6);
		glEnd();
	 	glBegin(GL_QUADS);
	    glColor3f(0.6,0.3,0.0);
	 	glVertex2f(-8,-19);
		glVertex2f(8,-19);
		glVertex2f(8,-21);
		glVertex2f(-8,-21);
		glEnd();
		glBegin(GL_QUADS);
	    glColor3f(0.6,0.3,0.0);
	 	glVertex2f(-6,-6);
		glVertex2f(6,-6);
		glVertex2f(6,-7);
		glVertex2f(-6,-7);
		glEnd();
		glBegin(GL_QUADS);
	    glColor3f(0.4,0.25,0.0);
	 	glVertex2f(-5,-8);
		glVertex2f(5,-8);
		glVertex2f(5,-18);
		glVertex2f(-5,-18);
		glEnd();
////////////////////////////////////////////////////
		glLineWidth(5);
		glBegin(GL_LINES);

		glColor3f(0.0,0.0,0.0);
		glVertex2f(-8,6);
		glVertex2f(0,12);

		glVertex2f(0,12);
		glVertex2f(8,6);

		glVertex2f(-8,6);
		glVertex2f(8,6);

		glVertex2f(6,6);
		glVertex2f(6,-19);

		glVertex2f(-6,6);
		glVertex2f(-6,-19);

		glVertex2f(-6,-6);
		glVertex2f(6,-6);
		/////////////////
		glVertex2f(-6,-7);
		glVertex2f(6,-7);

		glVertex2f(-8,-19);
		glVertex2f(8,-19);

		glVertex2f(-8,-21);
		glVertex2f(8,-21);

		glVertex2f(8,-19);
		glVertex2f(8,-21);

		glVertex2f(-8,-19);
		glVertex2f(-8,-21);
		//////////////////
		glVertex2f(-5,-8);
		glVertex2f(5,-8);

		glVertex2f(5,-8);
		glVertex2f(5,-18);

		glVertex2f(5,-18);
		glVertex2f(-5,-18);

		glVertex2f(-5,-18);
		glVertex2f(-5,-8);
		glEnd();
		////////////////points
		glPointSize(6);
	    glEnable(GL_POINT_SMOOTH);
		glBegin(GL_POINTS);
		glColor3f(0,0.0,0.0);
		float radius = 3.7;
			for (float theta = 0.0; theta < 2.0 * 3.14; theta += 3.14/6) {
				float x = radius * cos(theta);
				float y = radius * sin(theta);
				glVertex2f(x, y);
			}
		glEnd();
		/////////////
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0,0.0,0.0);
		float r1=4.4, x1=0, y1=0;
		for (float i=0.0;i<50.0;i+=0.01){
			glVertex2f(x1+r1*sin(i),y1+r1*cos(i));
		}
		glEnd();
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0,0.0,0.0);
		float r=5, x=0, y=0;
		for (float i=0.0;i<50.0;i+=0.01){
			glVertex2f(x+r*sin(i),y+r*cos(i));
		}
		glEnd();
	glPopMatrix();
//////////////////////////////////hands
	glPushMatrix();
		glRotatef(h,0,0,1);
		glLineWidth(4);
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,0);
		glVertex2f(0,1.7);
			glEnd();
	glPopMatrix();
	///////////
	glPushMatrix();
		glRotatef(m,0,0,1);
		glLineWidth(4);
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,0);
		glVertex2f(0,2.8);
			glEnd();
	glPopMatrix();
		///////////
	glPushMatrix();
		glRotatef(s,0,0,1);
		glLineWidth(2);
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,0);
		glVertex2f(0,2.8);
			glEnd();
	glPopMatrix();
/////////////////////////////////Pendulum
	glPushMatrix();
	    glTranslatef(0,-8,0);
		glRotatef(l,0,0,1);
		glLineWidth(6);
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,0);
		glVertex2f(0,-6);
		glEnd();
		//////////
		glBegin(GL_LINE_STRIP);
		glColor3f (0.83, 0.69, 0.22);
		float r2=1.2, x2=0, y2=-7;
		for (float i=0.0;i<50.0;i+=0.01){
			glVertex2f(x2+r2*sin(i),y2+r2*cos(i));
		}
		glEnd();
	glPopMatrix();
/////////////////////////////////////////////////movement
    if (fleft){
    if(l>-10)l-=0.15*speed;
    else {fleft=false;fright=true;	s-=6;m-=0.1;h-=0.01;}
    }
    else if(fright){
    if(l<10)l+=0.15*speed;
    else{fright=false;fleft=true;	s-=6;m-=0.1;h-=0.01;}
    }
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
void light() {
	glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_COLOR_MATERIAL);	
GLfloat light_position_0[] = {5, 30.0, 60.0, 0};
GLfloat ambient_color_0[] = {0.3, 0.3, 0.3, 1.0}; 
GLfloat diffuse_color_0[] = {0.7, 0.7, 0.7, 1.0}; 
GLfloat specular_color_0[] = {1.0, 1.0, 1.0, 1}; 

glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color_0);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color_0);
glLightfv(GL_LIGHT0, GL_SPECULAR, specular_color_0);
GLfloat maize_ambient[] = {0.4, 0.4, 0.4, 1.0};
GLfloat maize_diffuse[] = {0.6, 0.6, 0.6, 1.0};
GLfloat maize_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat maize_shininess = 50.0;

glMaterialfv(GL_FRONT, GL_AMBIENT,maize_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, maize_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, maize_specular);
glMaterialf(GL_FRONT, GL_SHININESS, maize_shininess);
}