#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
static void redraw(void);
int main(int argc, char **argv)
{   
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1100,700);
   	glutCreateWindow("First Example");
	glutDisplayFunc(redraw);	
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,5.0,70.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}		
float x=1,y=0 ,z=0,b=0;
static void redraw(void)
{
	glClearColor(0.5,0.5,0.5,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();				
	glTranslatef(0.0f,0.0f,-40.0f);
	glColor3f(0.0,1.0,1.0);
if(z<8){
		if(x<=8){
			x+=0.01;
			y+=0.1;
		}
		z+=0.01;
	}
	else {
		if(-8<b){
			x-=0.01;
			y+=0.1;
		}
		b-=0.005;
	}

	glTranslatef(x,z,b);
	glRotatef(y,1.0,0,0);
	glutWireSphere(5,25,25);
	

glutPostRedisplay();
glutSwapBuffers();
}
