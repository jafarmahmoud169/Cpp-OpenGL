#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
#include <iostream>
void light();
void wall (int xfirst,int xlast, int zfirst ,int zlast);
void specialKeys(int key, int x, int y);
void Keyboard (unsigned char key , int x,int y);
static void redraw(void);
float i=90.0;	

float xeye=25;
float yeye=4;
float zeye=5;

float xcenter=25;
float ycenter=4;
float zcenter=10;


int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(0, 0);
glutInitWindowSize(1520, 900);
glutCreateWindow("MAIZE");
glutDisplayFunc(redraw);
glMatrixMode(GL_PROJECTION);
gluPerspective(40, 1.0, 0.0, 500.0);
glMatrixMode(GL_MODELVIEW);
light();
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
  gluLookAt(xeye,yeye,zeye,   xcenter,ycenter,zcenter,   0,1,0);
///////////////////////////////////////
  //floor
  glPushMatrix();
  glBegin(GL_POLYGON);
  glColor3f(0.5,0.5,0.5);
  glVertex3d(-30,0,0);
  glVertex3d(-30,0,100);
  glVertex3d(30,0,100);
  glVertex3d(30,0,0);
  glEnd();
  //walls
  wall(30,30,0,100);
  wall(-30,-30,0,95);
  wall(30,-25,100,100);
  wall(30,-30,0,0);
  /////////////////
  wall(-10,-10,0,10);
  wall(20,0,10,10);
  wall(-20,-20,10,20);
  wall(20,-20,20,20);
  wall(0,0,20,40);
  wall(-10,-20,30,30);
  wall(-20,-20,30,50);
  wall(20,10,30,30);
  wall(10,10,30,50);
  wall(30,10,40,40);
  wall(0,-10,40,40);
  wall(-10,-10,40,60);
  wall(10,0,50,50);
  wall(20,-30,60,60);
  wall(20,20,50,60);
  wall(-20,-20,60,80);
  wall(10,10,60,80);
  wall(30,20,70,70);
  wall(20,0,80,80);
  wall(20,0,90,90);
  wall(-10,-10,70,90);
  wall(-10,-30,90,90);
/////////////////////////////////
  //helping spheres
  glPushMatrix();
  glTranslatef(25,15,5);
  glColor3f(1,0,0);
  glutWireSphere(2,15,15);
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-27,20,100);
  glColor3f(1,1,0);
  glutWireSphere(2,15,15);
  glPopMatrix();
  ///////////////
  glPopMatrix();
//////////////////////////////////////////////////////////
//Winning sign
  if (xeye<-20   &&   zeye>90){
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos3f(xcenter+40, ycenter,zcenter+20);
	char *string = "*****you.won!*****";
	while (*string) {
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
	}
  }
/////////////////////////////////////////////////////////
glutPostRedisplay();
glutSwapBuffers();

}

///////////////////////////////////////////////////////////////
void wall (int xfirst,int xlast, int zfirst ,int zlast){
		if(xfirst==xlast){glPushMatrix();glTranslatef(xlast,5,(zlast+zfirst)/2);
		float zlen=zlast-zfirst;
        glScalef(0,10,zlen);glColor3f(0,1,0);
		glutSolidCube(1);
		glPopMatrix();
	}
	else if(zfirst==zlast){glPushMatrix();glTranslatef((xlast+xfirst)/2,5,zlast);
	    float xlen=xlast-xfirst;glColor3f(0,1,0);
		glScalef(xlen,10,0);
		glutSolidCube(1);	
	glPopMatrix();
	}
 // glPushMatrix();
  //glBegin(GL_POLYGON);
  //glColor3f(0,1,0);
  //glVertex3d(xfirst,0,zfirst);
  //glVertex3d(xfirst,10,zfirst);
  //glVertex3d(xlast,10,zlast);
  //glVertex3d(xlast,0,zlast);
  //glEnd();glPopMatrix();
}
//////////////////////////////////////////////////////////////
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
GLfloat light_position_0[] = {50.0, 30.0, 50.0,0};
GLfloat ambient_color_0[] = {0.3,0.3,0.3, 1}; 
GLfloat diffuse_color_0[] = {0.7, 0.7, 0.7, 1}; 
GLfloat specular_color_0[] = {1,1,1, 1}; 

glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color_0);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color_0);
glLightfv(GL_LIGHT0, GL_SPECULAR, specular_color_0);
}