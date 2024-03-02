#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
static void redraw(void);
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(1200,900);
   	glutCreateWindow("First Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,0.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}		
float j=0,d=0,rr=0;
static void redraw(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0,0.0f,-100.0f);

	glLineWidth(5);
	glPushMatrix();
	//glTranslatef(d,0.0f,0.0f);
	glRotatef(-rr,0,0,1);
//circle 
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0,0.0,0.0);
	float r=10, x=0, y=0;
	for (float i=0.0;i<50.0;i+=0.01){
		glVertex2f(x+r*sin(i),y+r*cos(i));
	}

	glEnd();
		glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
		glVertex2f(-10,0);
		glVertex2f(10,0);
		glVertex2f(0,-10);
		glVertex2f(0,10);
		glVertex2f(7.1,7.1);
		glVertex2f(-7.1,-7.1);
		glVertex2f(-7.1,7.1);
		glVertex2f(7.1,-7.1);
	glEnd();

	glPopMatrix();
	rr-=1;
	d+=0.2;


//////text///////////////////////////////////////////////////////////////////////////
	glRotatef(j,0,0,1);
	glColor3f(1.0, 0.0, 0.0); //set text color to red
	glRasterPos2f(-10.0, 0.0); //set text position to center of circle
	char *string = "Hello jafar!"; //define text string
	while (*string) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++); //draw each character
	}
	j+=1;
/////////////////////////////////////////////////////////////////////////////////////	

glutSwapBuffers();
glutPostRedisplay();
}

