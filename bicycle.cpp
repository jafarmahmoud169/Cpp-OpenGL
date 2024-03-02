#include <windows.h>  // for MS Windows
#include <glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
static void redraw(void);
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1520,900);
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
glClearColor(0.52,0.80,0.92,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-80,0.0f,-250.0f);
	glRotatef(-15,0,0,1);

	glPushMatrix();
	glLineWidth(5);
	glTranslatef(d+30,0.0f,0.0f);
	glRotatef(rr,0,0,1);
	glBegin(GL_LINE_STRIP);
	glColor3f(0,0.0,0.0);
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


	glPushMatrix();
	glLineWidth(5);
	glTranslatef(d,0.0f,0.0f);
	glRotatef(rr,0,0,1);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0,0.0,0.0);
	float r1=10, x1=0, y1=0;
	for (float i=0.0;i<50.0;i+=0.01){
		glVertex2f(x1+r1*sin(i),y1+r1*cos(i));
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
	glPushMatrix();
	glTranslatef(d,0.0f,0.0f);
	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);
		glVertex2f(0,0);
		glVertex2f(7,15);

		glVertex2f(7,15);
		glVertex2f(22,15);

		glVertex2f(22,15);
		glVertex2f(30,0);

		glVertex2f(7,15);
		glVertex2f(15,1);

		glVertex2f(0,0);
		glVertex2f(15,1);

		glVertex2f(15,1);
		glVertex2f(22,15);

		glVertex2f(7,15);
		glVertex2f(7,17);

		glVertex2f(22,15);
		glVertex2f(22,19);

		glVertex2f(27,22);
		glVertex2f(15,16);
			glEnd();

		    glPushMatrix();
			glLineWidth(1);
			glTranslatef(7,19,0);
			glScalef(1.2,0.4,1);
			glutSolidSphere(4,25,25);
			glPopMatrix();
	glPopMatrix();
		    glPushMatrix();
			glTranslatef(d+15,0,0);
			glLineWidth(5);
			glBegin(GL_LINE_STRIP);
			glColor3f(0.0,0.0,0.0);
			float r2=3, x2=0, y2=0;
			for (float i=0.0;i<50.0;i+=0.01){
				glVertex2f(x2+r2*sin(i),y2+r2*cos(i));
			}

			glEnd();
			glPopMatrix();

	rr-=1;
	d+=0.2;
	glBegin(GL_POLYGON);
	   glColor3f(0.3,0.6,0.3);
		glVertex2f(-100,-10);
		glVertex2f(200,-10);
		glVertex2f(250,-150);
		glVertex2f(-100,-150);
	glEnd();

glutSwapBuffers();
glutPostRedisplay();
}

