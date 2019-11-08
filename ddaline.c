#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;


struct Point {
	GLint x;
	GLint y;
};

void drawBitmapText(char *string, float x, float y, float z) 
{  
	char *c;
	glRasterPos2f(x, y);
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

int counter = 1;
Point p1, p2;

int abs (int n) 
{ 
    return ( (n>0) ? n : ( n * (-1))); 
} 

void draw_dda(Point p1, Point p2) {
	GLfloat dx = p2.x - p1.x;
	GLfloat dy = p2.y - p1.y;
	char buffer[20];
	GLfloat x1 = p1.x;
	GLfloat y1 = p1.y;
	float m = dy/dx;
	GLfloat step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	GLfloat xInc = dx/step;
	GLfloat yInc = dy/step;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POINTS);
	for(float i = 1; i <= step; i++)
	{
		glVertex2i(x1, y1);
		x1 += xInc;
		y1 += yInc;
	}
	glEnd();
	//gcvt(m, 3, buffer); 
    //drawBitmapText(buffer, 600, 0, 0);
    drawBitmapText("Divyanshu Singh Chauhan", 0, 20, 0);
    drawBitmapText("500060640", 0, 5, 0);
	glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
			p1.x = x;
			p1.y = 480 - y;
	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		p2.x = x;
		p2.y = 480 - y;
		draw_dda(p1, p2);
	}
	glutPostRedisplay();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0f);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

void display()
{
	int j;
	glBegin(GL_LINES);
	glColor3f(0.00, 1.00, 1.00);
	
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Mouse Func");
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	init();
	glutMainLoop();

	return 0;
}