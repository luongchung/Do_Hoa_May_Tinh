#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
static int day= 0;
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glPushMatrix();
glRotatef(45,0,0,1);
glScalef(15,0.6,5);	
glutSolidCube(1.0);///////////////////////////
glShadeModel (GL_SMOOTH);
GLfloat light_ambient[] = { 1.0, 1.0, 0.0, 0.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glPopMatrix();


glPushMatrix();
glTranslatef(5,7,0);					
glTranslatef( (GLfloat) day/40 , (GLfloat) day/40 , 0);
glRotatef (((GLfloat) day)*(-1), 0, 0, 1);
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
{	switch (key) {
		case '.':
			
	day = (day + 1)/1.1;					
	glutPostRedisplay();
		break;
		case 'a': 
		if(day==1)
			{
				day=-day;
			}
		day = (day - 1)*1.1;				
		glutPostRedisplay();
		break;
		default:
		break;	}
}

int main(int argc, char** argv)
{	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 800); 
	glutInitWindowPosition (0, 0);
	glutCreateWindow (argv[0]);
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;}

