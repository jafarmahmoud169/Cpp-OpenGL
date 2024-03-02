#include <GL/glut.h>
void init() {
glEnable(GL_DEPTH_TEST);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);

}
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0, 0, -100);
// Set up the first light position and properties (LIGHT0)
GLfloat light_position_0[] = {100.0, -30.0, 100.0, 0.0};// Directional light from the top-right
GLfloat ambient_color_0[] = {0.2, 0.2, 0.2, 1.0}; // Ambient light color for LIGHT0
GLfloat diffuse_color_0[] = {1.0, 1.0, 1.0, 1.0}; // Diffuse light color for LIGHT0
GLfloat specular_color_0[] = {1.0, 1.0, 1.0, 1.0}; // Specular light color for LIGHT0



glLightfv(GL_LIGHT0, GL_POSITION, light_position_0);
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_color_0);
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_color_0);
glLightfv(GL_LIGHT0, GL_SPECULAR, specular_color_0);




// Set material properties for the teapot
GLfloat teapot_ambient[] = {0, 0, 0, 1.0};
GLfloat teapot_diffuse[] = {0, 1, 0, 1.0};
GLfloat teapot_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat teapot_shininess = 30.0;


glMaterialfv(GL_FRONT, GL_AMBIENT,teapot_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, teapot_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, teapot_specular);
glMaterialf(GL_FRONT, GL_SHININESS, teapot_shininess);
// Draw a teapot
glPushMatrix();
glColor3f(1,0,0);
glutSolidTeapot(20.0);
glPopMatrix();
// Set material properties for the sphere
GLfloat sphere_ambient[] = {0, 0, 0, 1.0};
GLfloat sphere_diffuse[] = {1, 0, 0, 1.0};
GLfloat sphere_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat sphere_shininess = 30.0;


glMaterialfv(GL_FRONT, GL_AMBIENT, sphere_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, sphere_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, sphere_specular);
glMaterialf(GL_FRONT, GL_SHININESS, sphere_shininess);
// Draw a sphere
glPushMatrix();
glTranslatef(-40, 0, 0);
glutSolidSphere(20.0, 20, 16);
glPopMatrix();


// Set material properties for the sphere
GLfloat sphere1_ambient[] = {0, 0, 0, 1.0};
GLfloat sphere1_diffuse[] = {0, 0, 1, 1.0};
GLfloat sphere1_specular[] = {1.0, 1.0, 1.0, 1.0};
GLfloat sphere1_shininess = 10.0;


glMaterialfv(GL_FRONT, GL_AMBIENT, sphere1_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, sphere1_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, sphere1_specular);
glMaterialf(GL_FRONT, GL_SHININESS, sphere1_shininess);
// Draw another sphere
glPushMatrix();
glTranslatef(40, 0, -30);
glutSolidSphere(20.0, 20, 16);
glPopMatrix();
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
init();
glutMainLoop();
return 0;
}