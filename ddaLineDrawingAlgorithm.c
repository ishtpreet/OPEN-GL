#include <GL/glut.h>
#include <math.h>

int first = 0, i;
int p, q, p1, q1;
float slope = 0.0f;
char ch[10], ax1[5], x2[5], ay1[5], y2[5];

int abs(int n)
{
     if (n > 0)
          return n;

     else
          return (n * (-1));
}

void BitmapText(char *string, float x, float y)
{
     char c;
     int i = 0;
     glRasterPos2f(x, y);

     for (i = 0; string[i] != '\0'; i++)
     {
          c = string[i];
          glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, c);
     }
}

void render()
{

     glColor3f(0, 1, 0);
     BitmapText("Ishtpreet Singh", 500, 40);
     BitmapText("500061526", 500, 30);
     glutSwapBuffers();
}

void DDA(int x1, int y1, int x2, int y2)
{
     float dx = x2 - x1;
     float dy = y2 - y1;

     slope = dy / dx; // slope of the line
     gcvt(slope, 2, ch);
     BitmapText(ch, 550, 380);
     BitmapText("m=", 535, 400);

     float xin = x1;
     float yin = y1;

     float step = 0;

     if (abs(dx) > abs(dy))
     {
          step = abs(dx);
     }
     else
     {
          step = abs(dy);
     }

     float xInc = dx / step;
     float yInc = dy / step;

     glColor3f(1.0, 0.0, 0.0);
     glClear(GL_COLOR_BUFFER_BIT);
     render();
     BitmapText(ch, 450, 400);
     BitmapText("m=", 415, 400);

     glBegin(GL_POINTS);
     float i;
     for (i = 1; i <= step; i++)
     {
          glVertex2i(xin, yin);
          xin += xInc;
          yin += yInc;
     }

     render();
     glEnd();

     glFlush();
}

void display()
{
     glClearColor(0.0, 0.0, 0.0, 0.0);
     glColor3f(1, 0, 0.0);
     glClear(GL_COLOR_BUFFER_BIT);
     render();
     glFlush();
}

void Click(int button, int state, int x, int y)
{
     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
     {

          p = x;
          q = 480 - y;
          printf("%d,%d\n", p, q);
     }

     if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
     {
          p1 = x;
          q1 = 480 - y;
          printf("%d,%d\n", p1, q1);
          DDA(p, q, p1, q1);
     }
}
void myinit()
{

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0, 640, 0.0, 480);
}
int main(int argc, char **argv)
{
     glutInit(&argc, argv);
     glutInitWindowPosition(100, 100);
     glutInitWindowSize(640, 480);
     glutCreateWindow("DDA Line Drawing Algorithm || Ishtpreet Singh");
     glutDisplayFunc(display);
     glutMouseFunc(Click);
     myinit();
     glutMainLoop();
     return 0;
}
