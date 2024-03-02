#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
static void redraw(void);
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600,600);
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
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0,0.0f,-40.0f);

	 //circle 
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0,0.0,0.0);
		float r=10, x=0, y=0;
		for (float i=0.0;i<50.0;i+=0.01){
			glVertex2f(x+r*sin(i),y+r*cos(i)); 
		}
	
		glEnd();
	 /////////////
		glBegin(GL_LINE_STRIP);
		glColor3f(0,0.0,0.0);
		float radius = 3.7;
			for (float theta = 0.0; theta < 2.0 * 3.14; theta +=0.01) {
				float x1 = radius * cos(theta);
				float y1 = radius * sin(theta);
				glVertex2f(x1, y1);
			}
		glEnd();

glutSwapBuffers();
glutPostRedisplay();
}

