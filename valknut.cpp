#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
static void redraw(void);
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(600,600);
   	glutCreateWindow("First Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,0.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}		

static void redraw(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(2,2,-20.0f);glRotatef(180,0,0,1);
	glLineWidth(6);
	glPushMatrix();
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,0);
		glVertex2f(5,0);

		glVertex2f(0,0);
		glVertex2f(2.5,4.8);

		glVertex2f(2.5,4.8);
		glVertex2f(5,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.8,1,0);
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,0);
		glVertex2f(5,0);

		glVertex2f(0,0);
		glVertex2f(2.5,4.8);

		glVertex2f(2.5,4.8);
		glVertex2f(5,0);
	glEnd();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-0.1,2,0);
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(0,0);
		glVertex2f(5,0);

		glVertex2f(0,0);
		glVertex2f(2.5,4.8);

		glVertex2f(2.5,4.8);
		glVertex2f(5,0);
	glEnd();
	glPopMatrix();

glutSwapBuffers();
glutPostRedisplay();
}

