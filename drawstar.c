#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265

static GLfloat spin = 0.0;
static double val = PI / 180;
static char huongquay ='a';
static double bankinh=2;
void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void spinDisplay(void)
{
	spin = spin + 2.0;
	if (spin > 360.0)
	spin = spin - 360.0;
 	glutPostRedisplay();
}
void drawStar(double r)
{
double b=sin(72*val)*r; 
double a=cos(72*val)*r ;	
int i=1;
while(i<6)
{
	glRotatef(72*i, 0, 0.0, 1);
	glTranslatef (0,a,0);
	glBegin (GL_LINES);
	glVertex2f(b,0);
	glVertex2f(-b,0);
	glEnd();
	glTranslatef (0,-a,0);
	glRotatef(-72*i, 0, 0.0, 1);
	i++;
}
}
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 1.0);
glLoadIdentity ();
gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
switch(huongquay)
{
case 'Z':
	glRotatef(spin, 0, 0.0, 1);
	break;
case '1':
	glRotatef(spin, 0, 0.0, 1);
	break;
}
 
drawStar(bankinh);
glFlush ();
}
void onKeyBoard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'z':
		huongquay='Z';
		glutIdleFunc(spinDisplay);
		break;
	case '1':
		huongquay='1';
		glutIdleFunc(spinDisplay);
		break;
	}
}

void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);
init ();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutKeyboardFunc(onKeyBoard);
glutMainLoop();
return 0;
}
