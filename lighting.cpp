#include <GL/glut.h>
#include<cmath>
float x,y,i=0;
void display() {glClearColor(0.52,0.80,0.92,0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0, 0, -100);
// Set up the first light position and properties (LIGHT0)
GLfloat light_position_0[] = {x, y, 100.0, 0.0};// Directional light from the top-right
GLfloat ambient_color_0[] = {0.4, 0.2, 0.2, 1.0}; // Ambient light color for LIGHT0
GLfloat diffuse_color_0[] = {1.0, 1.0, 1.0, 1.0}; // Diffuse light color for LIGHT0
GLfloat specular_color_0[] = {1.0, 1.0, 1.0, 1.0}; // Specular light color for LIGHT0



glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color_0);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color_0);
glLightfv(GL_LIGHT0, GL_SPECULAR, specular_color_0);

// Set material properties for the sphere
GLfloat sphere_ambient[] = {0.4, 0, 0, 1.0};
GLfloat sphere_diffuse[] = {1, 0, 0, 1.0};
GLfloat sphere_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat sphere_shininess = 30.0;


glMaterialfv(GL_FRONT, GL_AMBIENT, sphere_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, sphere_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, sphere_specular);
glMaterialf(GL_FRONT, GL_SHININESS, sphere_shininess);
// Draw a sphere
glPushMatrix();

glutSolidSphere(20.0, 30, 30);
glPopMatrix();




glEnable(GL_DEPTH_TEST);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);

    x =   100*cos(i * 3.14 / 180);
    y = 100* sin(i * 3.14 / 180);
	if (i<360)i+=0.5;else i=0;
glutPostRedisplay();

glutSwapBuffers();
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(100, 50);
glutInitWindowSize(900, 700);
glutCreateWindow("Example");
glutDisplayFunc(display);
glMatrixMode(GL_PROJECTION);
gluPerspective(80, 1.0, 10.0, 500.0);
glMatrixMode(GL_MODELVIEW);
glutMainLoop();
return 0;
}