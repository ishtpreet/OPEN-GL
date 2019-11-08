#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
int iteration = 1;
float rectangle[4][3] = {{200, 200, 1}, {300, 200, 1}, {300, 300, 1}, {200, 300, 1}};
float rectangle2[4][3];
float rectangle3[4][3];
float rectangle4[4][3];

void axis()
{
    glBegin(GL_LINES);
    glColor3f(1, 1, 0.00);
    glVertex2i(0, 500);
    glVertex2i(0, -500);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glVertex2i(500, 0);
    glVertex2i(-500, 0);
    glEnd();
    glFlush();
}
void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
    glLineWidth(3);
    glPointSize(2);

    //glClear(GL_COLOR_BUFFER_BIT);
}

void display()
{
    //glClear(GL_COLOR_BUFFER_BIT);
}

void keyPressed(unsigned char key, int x, int y)
{
    if (key == 32 && iteration == 1)
    {
    	glClearColor(0.0, 0.0, 0.0, 0.0);
    	axis();
        iteration++;
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 1);
        glVertex2i(rectangle[0][0], rectangle[0][1]);
        glVertex2i(rectangle[1][0], rectangle[1][1]);
        glVertex2i(rectangle[2][0], rectangle[2][1]);
        glVertex2i(rectangle[3][0], rectangle[3][1]);
        glEnd();
        glFlush();
    }

    else if (key == 32 && iteration == 2)
    {
        int c=0,d=0,k=0;
        float y[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
        int sum = 0;
        for (c = 0; c < 4; c++)
        {
            for (d = 0; d < 3; d++)
            {
                for (k = 0; k < 3; k++)
                {
                    sum = sum + rectangle[c][k] * y[k][d];
                }
                rectangle3[c][d] = sum;
                sum = 0;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        axis();
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 1);
        glVertex2i(rectangle3[0][0], rectangle3[0][1]);
        glVertex2i(rectangle3[1][0], rectangle3[1][1]);
        glVertex2i(rectangle3[2][0], rectangle3[2][1]);
        glVertex2i(rectangle3[3][0], rectangle3[3][1]);
        glEnd();
        glFlush();
        iteration++;
        glutPostRedisplay();
    }
    else if (key == 32 && iteration == 3)
    {
    	int c=0,d=0,k=0;
        float multiplication[3][3] = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
        int sum =0;
        for (c = 0; c < 4; c++)
        {
            for (d = 0; d < 3; d++)
            {
                for (k = 0; k < 3; k++)
                {
                    sum = sum + rectangle3[c][k] * multiplication[k][d];
                }
                rectangle2[c][d] = sum;
                sum = 0;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        axis();
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 1);
        glVertex2i(rectangle2[0][0], rectangle2[0][1]);
        glVertex2i(rectangle2[1][0], rectangle2[1][1]);
        glVertex2i(rectangle2[2][0], rectangle2[2][1]);
        glVertex2i(rectangle2[3][0], rectangle2[3][1]);
        glEnd();
        glFlush();
        iteration++;
        glutPostRedisplay();
    }
     else if (key == 32 && iteration == 4)
    {
        int c=0,d=0,k=0;
        float y[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
        int sum = 0;
        for (c = 0; c < 4; c++)
        {
            for (d = 0; d < 3; d++)
            {
                for (k = 0; k < 3; k++)
                {
                    sum = sum + rectangle2[c][k] * y[k][d];
                }
                rectangle4[c][d] = sum;
                sum = 0;
            }
        }
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0, 0.0, 0.0, 0.0);
        axis();
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 1);
        glVertex2i(rectangle4[0][0], rectangle4[0][1]);
        glVertex2i(rectangle4[1][0], rectangle4[1][1]);
        glVertex2i(rectangle4[2][0], rectangle4[2][1]);
        glVertex2i(rectangle4[3][0], rectangle4[3][1]);
        glEnd();
        glFlush();
        iteration++;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(640, 480);
    glutCreateWindow("VIVA-2 || Ishtpreet Singh");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    init();
    glutMainLoop();
    return 0;
}
