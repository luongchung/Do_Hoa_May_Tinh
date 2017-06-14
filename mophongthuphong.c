#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
static GLfloat scale = 0.0;
static char huongscale ='a';
void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void spinDisplay(void)
{

 scale +=0.003;
 if(scale>3)
 {
 	scale=-scale;
 }
 glutPostRedisplay();
}
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 1.0);
glLoadIdentity ();
gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//glScalef (1.0, 2.0, 1.0); 
switch(huongscale)
{
case 'X':
	glScalef (1.0+scale, 2.0, 1.0) ; ///quay theo truc X
	break;
case 'Y':
	glScalef (1.0, 2.0+scale, 1.0) ; ///Quay theo truc Y
	break;
case 'Z':
	glScalef (1, 1, 1+scale) ;//Quay theo truc Z
	break;
}
 
	
glutSolidCube(1.0);
glFlush ();
}
void onKeyBoard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'x':
		huongscale='X';
		glutIdleFunc(spinDisplay);
		break;
	case 'y':
		huongscale='Y';
		glutIdleFunc(spinDisplay);
		break;
	case 'z':
		huongscale='Z';
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
