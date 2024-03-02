#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
static void redraw(void);
float qq=0.0;
float random (float min,float max){
return ((float(rand())/float(RAND_MAX))*(max-min))+min;
}
bool flage = true;int size=5;
struct Star{
float x;
float y;
float z;
};
struct Star s [10000];
void init(){if (flage){
	for(int i =0;i<10000;i++){
	  s[i].x=random(-200,200);
      s[i].y=random(-2000,2000);
	  s[i].z=random(-100,100);}
	flage= false;
	}
}
void movez(){
for(int i =0;i<10000;i++){
	  if(s[i].y<1000)s[i].y-=0.3;
	  //else{s[i].z-=1;}
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1000,1000);
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
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0,0.0f,-40.0f);
    
	//stars
	 /*glScalef(0,0,0);*/
  init();
  movez();
  glPointSize(size);
  glEnable(GL_POINT_SMOOTH);
  glBegin(GL_POINTS);
    
  glColor3f(1,1,1);
	
  glPushMatrix();
  for(int i =0;i<10000;i++){
  glVertex3f(s[i].x,s[i].y,s[i].z);
  }
  glPopMatrix();
  glEnd();
  //ÇáÓÌÑÉ
  glRotatef(qq,0.0,1.0,0.0);

	glPushMatrix();

  glRotatef(90,-1.0,0.0,0.0);
  glColor3f(0.0,0.5,0.0);
  glLineWidth(7);
  glutWireCone(5.0,15.0,10.0,10.0);
  
    glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0,-2.0,0.0);
	glLineWidth(40);
	glColor3f(0.5,0.2,0.0);
	glBegin(GL_LINES) ;
		glVertex2f(0.0,0.0);
	    glVertex2f(0.0,2.0);
    glEnd();

    glPopMatrix();

	glPushMatrix();

	glTranslatef(0.0,15.0,0.0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1.0,1.0,0.0);
	glutWireSphere(0.5,5,5);

	glPopMatrix();
///////////////////////////////////////////////////////////
	glPushMatrix();

	glTranslatef(4,1,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(3,2,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(4,1,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(3,2,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(-4,1,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-3,2,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(-4,1,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(-3,2,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
//////////////
		glPushMatrix();

	glTranslatef(2,1,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(3,2,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(2,4,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(3,3,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(-4,3,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-3,2,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(-4,3,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(-3,4,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
/////////////////////////////////
	glPushMatrix();
	glTranslatef(0,6,0);
		glPushMatrix();

	glTranslatef(2,1,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(1,2,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(2,1,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(1,2,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(-2,1,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-1,2,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(-2,1,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,1.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(-1,2,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
//////////////
		glPushMatrix();

	glTranslatef(0,1,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(1,2,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(0,4,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(1,3,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(-2,3,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,1.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();

	glPushMatrix();

	glTranslatef(-1,2,0);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,1);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(-2,3,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(0,0.0,1.0);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
		glPushMatrix();

	glTranslatef(-1,4,3);
	glRotatef(90,-1.0,0.0,0.0);
	glLineWidth(3);
	glColor3f(1,0.0,1);
	glutWireSphere(0.3,5,5);

	glPopMatrix();
	glPopMatrix();
	qq+=0.1;
glutSwapBuffers();
glutPostRedisplay();
}