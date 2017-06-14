#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static double jum= 10;
static double k=-1;
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glPushMatrix();
glTranslatef(0,jum,0);				
glutSolidSphere(1, 20, 15);////////////////////////////
glShadeModel (GL_FLAT);	
glShadeModel (GL_SMOOTH);
GLfloat light_ambient1[] = { 0.0, 1.0, 0.0, 0.0 };
GLfloat light_diffuse1[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat light_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_position1[] = { 1.0, 1.0, 1.0, 0.0 };
glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular1);
glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);					
glPopMatrix();	
glutSwapBuffers();
glutPostRedisplay();
}
void reshape (int w, int h)
{	glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0, 0, 20, 0.0, 0.0, 0.0, 0, 1, 0);  
}
void keyboard (unsigned char key, int x, int y)
{
	if(key=='a')
	{
		
		if(jum<=-5)
		{
			k=1;
		}
		if(jum>10)
		{
			k=-1;
		}
		jum+=k;
	}
}

int main(int argc, char** argv)
{	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (600, 600); 
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;}

