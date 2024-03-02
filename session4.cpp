#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
void Keyboard (unsigned char key , int x,int y);
float zeye=-20;
float zt=-30;
static void redraw(void);
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(700,700);
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
	glutKeyboardFunc(Keyboard);
	gluLookAt(0,0,zeye,    0,0,zt,   0,1,0);
	glColor3f(1.0,1.0,1.0);
	
	glutWireTeapot(5);
glutPostRedisplay();
glutSwapBuffers();
}
void Keyboard (unsigned char key , int x,int y){
	switch(key){
	case 'e' : exit(0); break;
	case 'w': zeye-=1;zt-=0.1;break;
	case 's': zeye+=1;zt-=0.1;break;
	default: break;
	}
}
