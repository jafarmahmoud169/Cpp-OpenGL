#include <windows.h>  // for MS Windows
#include <GL/glut.h>// GLUT, include glu.h and gl.h
#include <stdlib.h>
static void redraw(void);

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
      s[i].y=random(-200,200);
	  s[i].z=random(-1000,1000);}
	flage= false;
	}
}
void movez(){
for(int i =0;i<10000;i++){
	  if(s[i].z<1000)s[i].z+=1;
	  //else{s[i].z-=1;}
	}
}

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(1100,1100);
     glutCreateWindow("First Example");
  glutDisplayFunc(redraw);  
  glMatrixMode(GL_PROJECTION);          
  gluPerspective(45,1.0,50,400.0);
  glMatrixMode(GL_MODELVIEW);
  glutMainLoop();
  return 0; 
}    

static void redraw(void)
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity(); 
  glTranslatef(0,0,-1000);
  
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
  glutPostRedisplay();

glutSwapBuffers();
}



