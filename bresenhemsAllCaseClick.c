#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
void init()
{

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640, 0.0, 480);
	glPointSize(3);
}

void draw_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

float a1, b1, a2, b2, p0, p;
char ch[10];

// to display text on screen
void BitmapText(char *string, float x, float y)
{
	char c;
	int i = 0;
	glRasterPos2f(x, y);

	for (i = 0; string[i] != '\0'; i++)
	{
		c = string[i];
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}

void render()
{

	glColor3f(1, 0, 0);
	BitmapText("Ishtpreet Singh", 470, 40);
	BitmapText("500061526", 470, 20);
	glutSwapBuffers();
}

void Bhem(int x1, int y1, int x2, int y2)
{
	float dx, dy;
	dx = x2 - x1;
	dy = y2 - y1;

	float slope = dy / dx; // slope of the line

	gcvt(slope, 2, ch);

	float xin = x1;
	float yin = y1;

	glColor3f(1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	render();
	BitmapText(ch, 450, 400);
	BitmapText("m=", 415, 400);

	int i, p;
	int incx, incy, inc1, inc2;
	int x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0)
		dx = -dx;

	if (dy < 0)
		dy = -dy;

	incx = 1;
	if (x2 < x1)
		incx = -1;

	incy = 1;
	if (y2 < y1)
		incy = -1;
	x = x1;
	y = y1;
	if (dx > dy)
	{
		draw_pixel(x, y);
		p = 2 * dy - dx;
		inc1 = 2 * (dy - dx); // when p0>0
		inc2 = 2 * dy;		  // whern p0<0
		for (i = 0; i < dx; i++)
		{
			if (p >= 0)
			{
				y += incy;
				p += inc1;
			}
			else
				p += inc2;
			x += incx;
			draw_pixel(x, y);
		}
	}
	else
	{
		draw_pixel(x, y);
		p = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
			if (p >= 0)
			{
				x += incx;
				p += inc1;
			}
			else
				p += inc2;
			y += incy;
			draw_pixel(x, y);
		}
	}

	render();
	glEnd();

	glFlush();
}

void Click(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		a1 = x;
		b1 = 480 - y;
		printf("%d,%d\n", a1, b1);
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		a2 = x;
		b2 = 480 - y;
		printf("%d,%d\n", a2, b2);
		Bhem(a1, b1, a2, b2);
	}
}

void display() // display func call abck
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1, 0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	render();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Bresenhems Line Drawing Algorithm || Ishtpreet Singh");
	glutDisplayFunc(display);
	glutMouseFunc(Click);
	init();
	glutMainLoop();
	return 0;
}
