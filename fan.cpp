#include<Windows.h>
#include<gl/GLUT.h>
double x = 0.0, y = 0.0, z = 0.0, a = 0.0, b = 0.0;
bool run = false;

static void redraw(void);
void keyboard( unsigned char key, int x1, int y1 );

int main(int argc, char **argv)
{
	
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,50);
	glutInitWindowSize(900,700);
   	glutCreateWindow("Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(80,1.0,10.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}		


static void redraw(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-100.0f);

	//Fan
	glPushMatrix();
		glTranslatef(-60,20,0);
		glRotatef(60, 0, 1, 0);
		glPushMatrix();
			glRotatef(x, 0, 0, 1);
			glLineWidth(3);
			glBegin(GL_LINES);
				glVertex3f(-30,0,0);
				glVertex3f(30,0,0);
			glEnd();
			if (run) x += 1;
		glPopMatrix();
		glLineWidth(15);
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,-80,0);
		glEnd();
	glPopMatrix();

	//Table
	glPushMatrix();
		glTranslatef(0,-10,0);
		glPushMatrix();
			glRotatef(z, 0, 0, 1);
			glLineWidth(40);
			glBegin(GL_LINES);
				glVertex3f(-50,0,0);
				glVertex3f(50,0,0);
			glEnd();
		glPopMatrix();
		glLineWidth(15);
		glBegin(GL_LINES);
			glVertex3f(0,0,0);
			glVertex3f(0,-60,0);
		glEnd();
		if (run){
			z -= 0.02;
			if (z <= -20) z = -20.0;
		}
	glPopMatrix();


	//Ball
	glPushMatrix();
		glTranslatef(a,b,0);
		glRotatef(y, 0, 0, 1);
		glLineWidth(1);
		glutWireSphere(10, 15,15);
		if (run) {
		y -= 0.5; 
		a += 0.05;
		b -= 0.01;
		
		if (a > 20) b -= 0.01;
		if (a >= 55) { a = 55.0; b -= 0.1; }
		if (b <= -50) { b = -50; y = 0;}
		}
	glPopMatrix();

	//Box
	glPushMatrix();
	glTranslatef(55,-50,0);
	glutWireCube(20);
	glPopMatrix();

	glutKeyboardFunc( keyboard );
	glutPostRedisplay();
	glutSwapBuffers();
 }

void keyboard ( unsigned char key, int x1, int y1 ) {
 switch ( key ) {
 //Escape key 
 case 'e':  exit ( 0 ); break; 
 case 'f': 	run = true;  break;
 case 's': 	run = false;  break;
 default: break; 
}
 }