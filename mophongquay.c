#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
static GLfloat s = 0.0;
static float tt = 0.0;
static float cd = 0.0;
static char kieu ='a';
void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}
void spinDisplay(void)
{
	
s = s + 0.2;
if (s > 360.0)
s = s - 360.0;
tt=tt+0.001;
cd=cd+0.001;
glutPostRedisplay();	

}
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (0.0, 0.0, 1.0);
glLoadIdentity ();
gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

 switch(kieu)
{
case '0':
	{
	
	glPushMatrix();
	glTranslatef(-2,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,2,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(0,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	break;
	}	
	
	
case 'q':
	{
	
	glPushMatrix();
	glRotatef(s, 1.0, 0.0, 0.0); ///quay theo truc X
	glTranslatef(-2,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(s, 0.0, 1.0, 0.0); ///Quay theo truc Y
	glTranslatef(0,2,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	glPushMatrix();
	glRotatef(s, 0.0, 0.0, 1.0);//Quay theo truc Z
	glTranslatef(0,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	break;
	}
	
	
case 't':
	{
	glPushMatrix();
	glTranslatef(-2+tt,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,2+tt,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	glPushMatrix();

	glTranslatef(0,0,1+tt);
	glutSolidCube(1.0);
	glPopMatrix();
	
	break;
	}	
case 'c':
	{
	
	glPushMatrix();
	glScalef (1.0+cd, 1.0, 1.0) ;
	glTranslatef(-2,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
	glScalef (1.0, 1.0+cd, 1.0) ;
	glTranslatef(0,2,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	glPushMatrix();
	glScalef (1.0, 1.0, 1.0+cd) ;
	glTranslatef(0,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	break;
	}

default:
	{	
	glPushMatrix();
	glTranslatef(-2,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,2,0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(0,0,0);
	glutSolidCube(1.0);
	glPopMatrix();
	break;
	}
	
}
	




glutSwapBuffers();
glFlush ();
}
void onKeyBoard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case '0':
		kieu='0';
		glutIdleFunc(spinDisplay);
		break;
	case 'q':
		kieu='q';
		glutIdleFunc(spinDisplay);
		break;
	case 't':
		kieu='t';
		glutIdleFunc(spinDisplay);
		break;
	case 'c':
		kieu='c';
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
