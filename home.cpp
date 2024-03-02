#include<Windows.h>
#include<gl/GLUT.h>
#include<cmath>

bool open,close,mill=false;
double rot_door,r_mill,r_flag,z_angle=0;
float zz=-100,xx=23;
void display();
void specialKeys(int key, int x, int y) {
    switch (key) {
        // Up arrow key
        case GLUT_KEY_UP: zz+=1.5 ;break;
        // Down arrow key
        case GLUT_KEY_DOWN:zz-=1.5;break;
		case GLUT_KEY_LEFT:xx+=1.5;break;
  case GLUT_KEY_RIGHT:xx-=1.5;break;
  default:
            break;
    }
}
void Keyboard (unsigned char key , int x,int y){

	switch(key){
	case '=': z_angle+=4;break;
	case '-': z_angle-=4;break;
	case 'd': open=!open;break;
	case 'c': close=!close;break;
	case 'r': mill=!mill;break;
	  
	default: break;
	}
} 


static void redraw(void)
{

	glLoadIdentity();
	glTranslatef(xx,0,zz);
	glRotatef(z_angle,0,1,0);
	display();
    glutPostRedisplay();
	glutSwapBuffers();
}

int main(int argc, char **argv)
{
	
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100,40);
	glutInitWindowSize(1300,800);
   	glutCreateWindow("Example");
	glutDisplayFunc(redraw);
	  glutKeyboardFunc(Keyboard);glutSpecialFunc(specialKeys);
	glMatrixMode(GL_PROJECTION);					
	gluPerspective(45,1.0,0.0,1000.0);
	glMatrixMode(GL_MODELVIEW);
	glutMainLoop();
	return 0; 
}


void ground(){
	
	glBegin(GL_QUADS);
	   glColor3f(0.3,0.6,0.3);
	   glVertex3f(-200,-10,-300);
	   glVertex3f(-200,-10,200);
	   glVertex3f(300,-10,200);
	   glVertex3f(300,-10,-300);
     glEnd();
}
void house(){
glBegin(GL_QUADS);
	   glColor3f(0.5,0.1,0.1);
	   glVertex3f(-10,-10,-190);
	   glVertex3f(-40,-10,-190);
	   glVertex3f(-40,14,-190);
	   glVertex3f(-10,14,-190);
     glEnd();
glBegin(GL_QUADS);
	   glColor3f(0.2,0.3,0.3);
	   glVertex3f(-10,-10,-190);
	   glVertex3f(-40,-10,-190);
	   glVertex3f(-40,-10,-160);
	   glVertex3f(-10,-10,-160);
     glEnd();

glBegin(GL_QUADS);
	   glColor3f(0.7,0.2,0);
	   glVertex3f(-10,-10,-160);
	   glVertex3f(-10,14,-160);
	   glVertex3f(-20,14,-160);
	   glVertex3f(-20,-10,-160);
     glEnd();

glBegin(GL_QUADS);
	   glVertex3f(-30,-10,-160);
	   glVertex3f(-30,14,-160);
	   glVertex3f(-40,14,-160);
	   glVertex3f(-40,-10,-160);
     glEnd();
glBegin(GL_QUADS);
	   glVertex3f(-20,9,-160);
	   glVertex3f(-20,14,-160);
	   glVertex3f(-30,14,-160);
	   glVertex3f(-30,9,-160);
     glEnd();
glBegin(GL_QUADS);
	   glVertex3f(-10,-10,-190);
	   glVertex3f(-10,-10,-160);
	   glVertex3f(-10,14,-160);
	   glVertex3f(-10,14,-190);
     glEnd();
glBegin(GL_QUADS);
	   glVertex3f(-40,-10,-190);
	   glVertex3f(-40,-10,-160);
	   glVertex3f(-40,14,-160);
	   glVertex3f(-40,14,-190);
     glEnd();

	glPushMatrix();
	 glColor3f(0.2,0.2,0.1);
	 glTranslated(-16.5,23.5,-170);
	 glScalef(1,3.9,1);
	 glutSolidCube(5);
	glPopMatrix();

	glBegin(GL_TRIANGLES);
	glColor3f(0.7,0.2,0);
	   glVertex3f(-25,29,-190);
	   glVertex3f(-40,14,-190);
	   glVertex3f(-40,14,-190);	
	   glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.7,0.2,0);
	   glVertex3f(-25,29,-160);
	   glVertex3f(-40,14,-160);
	   glVertex3f(-10,14,-160);	
	   glEnd();
	glPushMatrix();
	 glColor3f(0.5,0.1,0.1);
	 glTranslated(-25,14,-160);
	 glScalef(15,1,2);
	 glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	 glTranslated(-16.5,20.5,-175);
	 glRotatef(-45,0,0,1);
	 glScalef(17,1,25);
	 glutSolidCube(1.5);
	glPopMatrix();

	glPushMatrix();
	 glTranslated(-33.5,20.5,-175);
	 glRotatef(45,0,0,1);
	 glScalef(17,1,25);
	 glutSolidCube(1.5);
	glPopMatrix();
}
void door(){
	if(open){
		if(rot_door<=130)rot_door+=1;
		else open=!open;
	}
	if(close){
		if(rot_door>=0)rot_door-=1;
		else close=!close;
	}
	glPushMatrix();
	glColor3f(0.2,0.2,0.1);
	 glTranslated(-20,-0.5,-160);
	 glRotatef(rot_door,0,1,0);
	 glTranslated(-5,0,0);
	 glScalef(20,38,1);
	 glutSolidCube(0.5);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.5,0.5,0.5);
	 glTranslated(-20,-5.5,-160);
	 glRotatef(rot_door,0,1,0);
	 glTranslated(-5,0,0);
	 glScalef(1.2,1,1);
	 glRotatef(45,0,0,1);
	 glutSolidTorus(0.8,4,23,4);
	glPopMatrix();
	glPushMatrix();
	 glTranslated(-20,3,-160);
	 glRotatef(rot_door,0,1,0);
	 glTranslated(-7,0,0);
	 glScalef(1,2.5,1);
	 glRotatef(45,0,0,1);
	 glutSolidTorus(0.8,2,23,4);
	glPopMatrix();
	glPushMatrix();
	 glTranslated(-20,3,-160);
	 glRotatef(rot_door,0,1,0);
	 glTranslated(-3,0,0);
	 glScalef(1,2.5,1);
	 glRotatef(45,0,0,1);
	 glutSolidTorus(0.8,2,23,4);
	glPopMatrix();
}
void windmill(){
	if(mill){r_mill+=5;
	r_flag+=0.3;}
	glPushMatrix();
	glColor3f(0.6,0.7,0.7);
	 glTranslated(40,25,-150);
	 glRotatef(r_mill,0,0,1);
	 glutSolidTorus(0.8,9,3,4);
	glPopMatrix();
	glPushMatrix();
	 glTranslated(40,25,-150);
	 glRotatef(r_mill,0,0,1);
	 glScalef(1,13,1);
	 glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(40,25,-150);
	 glRotatef(r_mill,0,0,1);
	 glScalef(13,1,1);
	 glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	 glTranslated(40,25,-150);
	 glRotatef(r_mill,0,0,1);
	 glRotatef(45,0,0,1);
	 glutSolidTorus(0.8,9,3,4);
	glPopMatrix();

		glPushMatrix();
	glColor3f(0.6,0.7,0.7);
	 glTranslated(40,25,-160);
	 glRotatef(r_mill,0,0,1);
	 glutSolidTorus(0.8,9,3,4);
	glPopMatrix();
	glPushMatrix();
	 glTranslated(40,25,-160);
	 glRotatef(r_mill,0,0,1);
	 glScalef(1,13,1);
	 glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(40,25,-160);
	 glRotatef(r_mill,0,0,1);
	 glScalef(13,1,1);
	 glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	 glTranslated(40,25,-160);
	 glRotatef(r_mill,0,0,1);
	 glRotatef(45,0,0,1);
	 glutSolidTorus(0.8,9,3,4);
	glPopMatrix();
		glPushMatrix();
		glColor3f(0.2,0.2,0.2);
	 glTranslated(40,25,-155);
	 glScalef(1,1,8);
	 glutSolidCube(3);
	glPopMatrix();
			glPushMatrix();
	glColor3f(0.4,0.5,0.6);
	 glTranslated(40,-5,-155);
	 glRotatef(-30,0,0,1);
	 glutSolidTorus(3,30,3,3);
	glPopMatrix();
	glColor3f(0.2,0.3,0.4);
		glPushMatrix();
	 glTranslated(40,25,-145);
	 glRotatef(r_flag,0,0,1);
	 glScalef(5,65,1);
	 glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(40,25,-145);
	 glRotatef(r_flag,0,0,1);
	 glTranslated(30,0,0);
	 glScalef(5,15,1);
	 glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(40,25,-145);
	 glRotatef(r_flag,0,0,1);
	 glTranslated(-30,0,0);
	 glScalef(5,15,1);
	 glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(40,25,-145);
	 glRotatef(r_flag,0,0,1);
	 glScalef(65,5,1);
	 glutSolidCube(1);
	glPopMatrix();
			glPushMatrix();
	 glTranslated(40,25,-145);
	 glRotatef(r_flag,0,0,1);
	 glTranslated(0,30,0);
	 glScalef(15,5,1);
	 glutSolidCube(1);
	glPopMatrix();
			glPushMatrix();
	 glTranslated(40,25,-145);
	 glRotatef(r_flag,0,0,1);
	 glTranslated(0,-30,0);
	 glScalef(15,5,1);
	 glutSolidCube(1);
	glPopMatrix();



		glPushMatrix();
	 glTranslated(40,25,-165);
	 glRotatef(r_flag,0,0,1);
	 glScalef(5,65,1);
	 glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(40,25,-165);
	 glRotatef(r_flag,0,0,1);
	 glTranslated(30,0,0);
	 glScalef(5,15,1);
	 glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(40,25,-165);
	 glRotatef(r_flag,0,0,1);
	 glTranslated(-30,0,0);
	 glScalef(5,15,1);
	 glutSolidCube(1);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(40,25,-165);
	 glRotatef(r_flag,0,0,1);
	 glScalef(65,5,1);
	 glutSolidCube(1);
	glPopMatrix();
			glPushMatrix();
	 glTranslated(40,25,-165);
	 glRotatef(r_flag,0,0,1);
	 glTranslated(0,30,0);
	 glScalef(15,5,1);
	 glutSolidCube(1);
	glPopMatrix();
			glPushMatrix();
	 glTranslated(40,25,-165);
	 glRotatef(r_flag,0,0,1);
	 glTranslated(0,-30,0);
	 glScalef(15,5,1);
	 glutSolidCube(1);
	glPopMatrix();
}
void well(){
	glTranslated(20,0,0);
		glColor3f(0.3,0.1,0.1);
		glPushMatrix();
	 glTranslated(-120,-9,-160);
	 glRotatef(90,1,0,0);
	 glutSolidTorus(1,20,4,40);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(-120,-7,-160);
	 glRotatef(90,1,0,0);
	 glutSolidTorus(1,20,4,40);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(-120,-5,-160);
	 glRotatef(90,1,0,0);
	 glutSolidTorus(1,20,4,40);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(-120,-3,-160);
	 glRotatef(90,1,0,0);
	 glutSolidTorus(1,20,4,40);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(-120,-1,-160);
	 glRotatef(90,1,0,0);
	 glutSolidTorus(1,20,4,40);
	glPopMatrix();


			glPushMatrix();
	 glTranslated(-100,3,-160);
	 glScalef(1,13,1);
	 glutSolidCube(2.5);
	glPopMatrix();
				glPushMatrix();
	 glTranslated(-140,3,-160);
	 glScalef(1,13,1);
	 glutSolidCube(2.5);
	glPopMatrix();
				glPushMatrix();
	 glTranslated(-120,17,-160);
	 glScalef(20,1,1);
	 glutSolidCube(2.5);
	glPopMatrix();
glColor3f(0.8,0.7,0.7);
		glPushMatrix();
	 glTranslated(-120,17,-160);
	 glRotatef(90,0,1,0);
	 glutSolidTorus(0.8,3,4,10);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(-121.5,17,-160);
	 glRotatef(90,0,1,0);
	 glutSolidTorus(0.8,3,4,10);
	glPopMatrix();
		glPushMatrix();
	 glTranslated(-123,17,-160);
	 glRotatef(90,0,1,0);
	 glutSolidTorus(0.8,3,4,10);
	glPopMatrix();
			glPushMatrix();
	 glTranslated(-124.5,17,-160);
	 glRotatef(90,0,1,0);
	 glutSolidTorus(0.8,3,4,10);
	glPopMatrix();
			glPushMatrix();
	 glTranslated(-126,17,-160);
	 glRotatef(90,0,1,0);
	 glutSolidTorus(0.8,3,4,10);
	glPopMatrix();
					glPushMatrix();
	 glTranslated(-120,14,-160);
	 glScalef(1,5,1);
	 glutSolidCube(1.3);
	glPopMatrix();
	glColor3f(0.5,0.4,0.3);
					glPushMatrix();
	 glTranslated(-120,11,-160);
	 glScalef(8,1,1);
	 glutSolidCube(1);
	glPopMatrix();
					glPushMatrix();
	 glTranslated(-124,9,-160);
	 glScalef(1,5,1);
	 glutSolidCube(1);
	glPopMatrix();
						glPushMatrix();
	 glTranslated(-116,9,-160);
	 glScalef(1,5,1);
	 glutSolidCube(1);
	glPopMatrix();
	glColor3f(0.1,0.1,0.1);
						glPushMatrix();
	 glTranslated(-120,4,-160);
	 glutSolidCube(7);
	glPopMatrix();
}

void display(){
		glClearColor(0.52,0.80,0.92,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	ground();
	house();
	door();
	windmill();
	well();
}
