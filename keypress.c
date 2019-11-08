#include<GL/glut.h>
void display()
{	
	glClearColor(5.2,1.0,1.2,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	  glBegin(GL_TRIANGLES);
    glColor3f( 1, 0, 0 ); // red
    glVertex2f( -0.8, -0.8 );
    glColor3f( 0, 1, 0 ); // green
    glVertex2f( 0.8, -0.8 );
    glColor3f( 0, 0, 1 ); // blue
    glVertex2f( 0, 0.9 );
    glEnd(); 

	glutSwapBuffers();
}

void keyPressed (unsigned char key, int x, int y)
{  
	if (key == 32) { 
	glutDestroyWindow (1);
	
} 
if(key == 27){
 glLoadIdentity();                           // start with identity matrix
 glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0); 

glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glClear( GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 1.0, 0.0);
 glBegin(GL_POLYGON);

  glVertex3f(2.0, 4.0, 0.0);
 glColor3f( 1, 0, 0 ); // red

  glVertex3f(8.0, 4.0, 0.0);
glColor3f( 0, 0, 1 ); // blue
  glVertex3f(8.0, 6.0, 0.0);
glColor3f( 0.5, 0.5, 0.5 );
  glVertex3f(2.0, 6.0, 0.0);
 glEnd();
 glutSwapBuffers(); 
}


} 

int main(int argc,char **argv)
{
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(625,512);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPressed);
	glutMainLoop();
	return 0;
}