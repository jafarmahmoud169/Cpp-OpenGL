#include <GL/glut.h>
#include<cmath>
void Keyboard (unsigned char key , int x,int y);
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();  glutKeyboardFunc(Keyboard);
glTranslatef(0, 0, -100);
glRotatef(45,1,1,0);
	glBegin(GL_QUADS);
	   glColor3f(1,1,0.0);
	   glNormal3f(0,0,-1);
	   glVertex3f(-10,-10,-10);
	   glVertex3f(-10,10,-10);
	   glVertex3f(10,10,-10);
	   glVertex3f(10,-10,-10);

	   glColor3f(1,0,1);
	   glNormal3f(0,-1,0);
	   glVertex3f(-10,-10,-10);
	   glVertex3f(10,-10,-10);
	   glVertex3f(10,-10,10);
	   glVertex3f(-10,-10,10);


	   glColor3f(0,1,1);
	   glNormal3f(-1,0,0);
	   glVertex3f(-10,-10,-10);
	   glVertex3f(-10,10,10);
	   glVertex3f(-10,10,10);
	   glVertex3f(-10,-10,-10);


	   glColor3f(0,0,1);
	   glNormal3f(1,0,0);
	   glVertex3f(10,-10,-10);
	   glVertex3f(10,10,-10);
	   glVertex3f(10,10,10);
	   glVertex3f(10,-10,10);


	   glColor3f(0,1,0);
	   glNormal3f(0,1,0);
	   glVertex3f(-10,10,-10);
	   glVertex3f(-10,10,10);
	   glVertex3f(10,10,10);
	   glVertex3f(10,10,-10);


	   glColor3f(1,0,0);
	   glNormal3f(0,0,1);
	   glVertex3f(-10,-10,10);
	   glVertex3f(10,-10,10);
	   glVertex3f(10,10,10);
	   glVertex3f(-10,10,10);
     glEnd();
glutPostRedisplay();
glutSwapBuffers();
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(100, 50);
glutInitWindowSize(900, 700);
glutCreateWindow("Example");
glutDisplayFunc(display);
glMatrixMode(GL_PROJECTION);
gluPerspective(80, 1.0, 10.0, 500.0);
glMatrixMode(GL_MODELVIEW);
glutMainLoop();
return 0;
}
void Keyboard (unsigned char key , int x,int y){

	switch(key){
	case 'l': glEnable(GL_COLOR_MATERIAL);glEnable(GL_LIGHTING);glEnable(GL_LIGHT0);break;
	case 'f':glDisable(GL_LIGHTING); break;
	default: break;
	}
} 