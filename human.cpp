#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
#include <iostream>
float l=0,ll=0,mo=20;
bool fleft=true; bool fright=false;
bool fleft1=true; bool fright1=false;

void specialKeys(int key, int x, int y);
void Keyboard (unsigned char key , int x,int y);
static void redraw(void);
float i=90.0;	

float xeye=0;
float yeye=0;
float zeye=-100;

float xcenter=0;
float ycenter=0;
float zcenter=0;
void light();

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(0, 0);
glutInitWindowSize(900, 900);
glutCreateWindow("MAIZE");
glutDisplayFunc(redraw);
glMatrixMode(GL_PROJECTION);
gluPerspective(40, 1.0, 0.0, 500.0);
glMatrixMode(GL_MODELVIEW);//light();
glutMainLoop();
return 0;
}    

static void redraw(void)
{
glClearColor(0.52,0.80,0.92,0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
///////////////////////////////////////
  glutKeyboardFunc(Keyboard);glutSpecialFunc(specialKeys);
  gluLookAt(xeye,yeye,zeye,   xcenter,ycenter,zcenter,   0,1,0);glColor3f(0.5,0.5,0.5);
  glTranslatef(mo,0,0);
  glRotatef(60,0,1,0);
  //body
  glPushMatrix();
  glScalef(1,2,0.5);
  glutSolidCube(10);
  glPopMatrix();
  //hands
  //left
  glPushMatrix();
    glTranslatef(2.5,8,0);
  glRotatef(20,0,0,1); 
  glRotatef(l,1,0,0);
  	glBegin(GL_QUADS);
	   glColor3d(0.6,0.3,0.0);
	   glVertex2f(0,0);
	   glVertex2f(3,0);
	   glVertex2f(3,-13);
	   glVertex2f(0,-13);
     glEnd();
  glPopMatrix();
  //right
  glPushMatrix();
  glTranslatef(-2.5,8,0);
  glRotatef(-20,0,0,1); 
  glRotatef(-l,1,0,0);
  	glBegin(GL_QUADS);
	   glColor3d(0.6,0.3,0.0);
	   glVertex2f(0,0);
	   glVertex2f(-3,0);
	   glVertex2f(-3,-13);
	   glVertex2f(0,-13);
     glEnd();
  glPopMatrix();
  //legs
  glPushMatrix();
  glTranslatef(-1,-9,0); 
  glRotatef(-ll,1,0,0);  //glRotatef(30,0,1,0);
  	glBegin(GL_QUADS);
	   glColor3d(0.6,0.3,0.0);
	   glVertex2f(0,0);
	   glVertex2f(-3,0);
	   glVertex2f(-3,-10);
	   glVertex2f(0,-10);
     glEnd();
  glPopMatrix();
  //
  glPushMatrix();
    glTranslatef(1,-9,0);
  glRotatef(ll,1,0,0);//glRotatef(30,0,1,0);
  	glBegin(GL_QUADS);
	   glColor3d(0.6,0.3,0.0);
	   glVertex2f(0,0);
	   glVertex2f(3,0);
	   glVertex2f(3,-10);
	   glVertex2f(0,-10);
     glEnd();
  glPopMatrix();
  //head
  glPushMatrix();
  glTranslatef(0,16,0);
  glScalef(8,12,5);glColor3f(0.5,0.5,0.5);
  glutSolidSphere(0.5,30,30);
  glPopMatrix();
  /////////////////////////////////////////////////movement
    if (fleft){
		if(l>-40)l-=0.25;
    else {fleft=false;fright=true;}
    }
    else if(fright){
    if(l<40)l+=0.25;
    else{fright=false;fleft=true;}
    }
	////////////
	    if (fleft1){
		if(ll>-25)ll-=0.40;
    else {fleft1=false;fright1=true;}
    }
    else if(fright1){
    if(ll<25)ll+=0.40;
    else{fright1=false;fleft1=true;}
    }
	//////////////////////////////////////////////////////////
	mo-=0.1;
glutPostRedisplay();
glutSwapBuffers();

}

void Keyboard (unsigned char key , int x,int y){

	switch(key){
	case 'd': xeye-=1;xcenter-=1;break;
	case 'a': xeye+=1;xcenter+=1;break;
	case 'w': yeye+=1;ycenter+=1;break;
	case 's': yeye-=1;ycenter-=1;break;
	case 'q': ycenter+=3;break;
	case 'z': ycenter-=3;break;  
	default: break;
	}
} 
/////////////////////////////////////////////////////////////

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
			i += 2;
    default:break;
    }
}
///////////////////////////////////////////////////////////////
void light() {
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH);
glEnable(GL_COLOR_MATERIAL);
GLfloat light_position_0[] = {0.0, 0.0, 100.0, 0};
GLfloat ambient_color_0[] = {0.5, 0.5, 0.5, 1}; 
GLfloat diffuse_color_0[] = {0.7, 0.7, 0.7, 1}; 
GLfloat specular_color_0[] = {1, 1, 1, 1}; 

glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color_0);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color_0);
glLightfv(GL_LIGHT0, GL_SPECULAR, specular_color_0);
//
GLfloat maize_ambient[] = {0.3 ,0.3, 0.3, 1.0};
GLfloat maize_diffuse[] = {0.7, 0.7, 0.7, 1.0};
GLfloat maize_specular[] = {1, 1, 1, 1.0};
GLfloat maize_shininess = 10.0;

glMaterialfv(GL_FRONT_LEFT, GL_AMBIENT,maize_ambient);
glMaterialfv(GL_FRONT_LEFT, GL_DIFFUSE, maize_diffuse);
glMaterialfv(GL_FRONT_LEFT, GL_SPECULAR, maize_specular);
glMaterialf(GL_FRONT_LEFT, GL_SHININESS, maize_shininess);
}