#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
int r=0;
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,100);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(5);
	glBegin(GL_TRIANGLES);
	    glColor3f(1,0,0);
		glVertex3f(-2,-2,-5.0);
		glVertex3f(2,0.0,-5.0);
		glVertex3f(0.0,2,-5.0);
		glColor3f(0,1,0);
		glVertex3f(-2,-2,-5.0);
		glVertex3f(0.0,2,-5.0);
		glVertex3f(-2,1,-5.0);
	glEnd();
	glPushMatrix();
	//glLoadIdentity();
	glTranslatef(0,0,-5);
	glRotatef(10*r,0,1,0);
	//glLoadIdentity();
	//glTranslatef(0,0,-5);
	glColor3f(0,0,1);
	glutWireCone(1,2,10,3);
	glPopMatrix();
	//glTranslatef(0,0,-5);
	glutSwapBuffers();
}
void keyboard(unsigned char key,int x, int y)
{
	if(key=='j')
		{r++;
	glutPostRedisplay();
	}
}
int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(800,100);
	glutInitWindowSize(520,320);
    glutCreateWindow("example");
	

	// register callbacks
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	// enter GLUT event processing loop
	glutMainLoop();

	return 1;
}