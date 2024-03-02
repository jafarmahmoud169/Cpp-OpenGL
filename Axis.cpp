#include<Windows.h>
#include<gl/GLUT.h>
#include<cmath>
double x,z,i = 0.0;

static void redraw(void);

int main(int argc, char **argv)
{
	
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,50);
	glutInitWindowSize(1200,700);
   	glutCreateWindow("Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,0.0,1000.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}		


static void redraw(void)
{
	glClearColor(0.0,0.0,0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(x,40,z,0,0,0,   0,1,0);
	glLineWidth(2);
            glBegin(GL_LINES);
			glColor3f(1,0,0);
				glVertex3f(-3000,0,0);
				glVertex3f(3000,0,0);
			glColor3f(0,0,1);
				glVertex3f(0,-3000,0);
				glVertex3f(0,3000,0);
			glColor3f(0,1,0);
				glVertex3f(0,0,-3000);
				glVertex3f(0,0,3000);
			glEnd();
			glColor3f(1,1,0);
			glutWireTorus(3,4,23,50);


    x = 40 * cos(i * 3.14 / 180);
    z = 40 * sin(i * 3.14 / 180);
	if (i<360)i+=0.5;else i=0;
	glutPostRedisplay();
	glutSwapBuffers();
 }
