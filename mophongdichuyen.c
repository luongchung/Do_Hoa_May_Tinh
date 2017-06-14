#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
static GLfloat D = 0.0;
static char huongdichuyen ='a';
void init(void)
{
 GLfloat light_ambient[] = { 1.0, 0.2, 0.0, 1.0 };
 GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
 GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
 GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_SMOOTH);
 glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
 glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
 glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
 glLightfv(GL_LIGHT0, GL_POSITION, light_position);
 glEnable(GL_LIGHTING);
 glEnable(GL_LIGHT0);
 glEnable(GL_DEPTH_TEST);

}
void spinDisplay(void)
{

 D +=0.0000003;
 if(D>1)
 {
 	D=-D;
 }
 glutPostRedisplay();
}
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
switch(huongdichuyen)
{
case 'X':
	glTranslatef (D,0, 0) ; ///quay theo truc X
	break;
case 'Y':
	glTranslatef (0,D, 0) ; ///Quay theo truc Y
	break;
case 'Z':
	glTranslatef (0, 0,D) ;//Quay theo truc Z
	break;
}
glPushMatrix();
glTranslatef(5, 2, 10);
glutSolidCube(1.0);
glPopMatrix();
    
glPushMatrix();
glTranslatef(0, 0, 0);
glutSolidCube(1.0);
glPopMatrix();   

glFlush ();
}
void onKeyBoard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'x':
		huongdichuyen='X';
		glutIdleFunc(spinDisplay);
		break;
	case 'y':
		huongdichuyen='Y';
		glutIdleFunc(spinDisplay);
		break;
	case 'z':
		huongdichuyen='Z';
		glutIdleFunc(spinDisplay);
		break;
	}
}

void reshape (int w, int h)
{
 glViewport (0, 0, (GLsizei) w, (GLsizei) h);
 glMatrixMode (GL_PROJECTION);
 glLoadIdentity();
 if (w <= h)
 glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
 1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
 else
 glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
 1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
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







switch(huongquay)
{
case '0':
	glRotatef(0, 0.0, 0.0, 0.0); ///quay theo truc X
	break;
case 'X':
	glRotatef(spin, 1.0, 0.0, 0.0); ///quay theo truc X
	break;
case 'Y':
	glRotatef(spin, 0.0, 1.0, 0.0); ///Quay theo truc Y
	break;
case 'Z':
	glRotatef(spin, 0.0, 0.0, 1.0);//Quay theo truc Z
	break;
}
