#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
static void redraw(void);
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
   	glutCreateWindow("First Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,10.0,200.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}		

static void redraw(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();				
	glTranslatef(-1.5f,0.0f,-100.0f);
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2f(-30,-30);
		glVertex2f(-30,30);
		glVertex2f(30,30);
		glVertex2f(30,-30);
	glEnd();
		

glutSwapBuffers();
}
