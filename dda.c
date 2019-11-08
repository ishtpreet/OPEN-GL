#include<stdbool.h>
#include<GL/Glut.h>
#include<stdlib.h>
#include<math.h>

float x= 0.0, y = 0.0;
bool check=true;
int X[3] = {0, 0, 0};
int Y[3] = {0, 0, 0};
int counter = 0;

void mouse(int button, int state, int mousex, int mousey)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
       check=true;
        x = mousex;
        y = 480-mousey;
        X[counter] = x;
        Y[counter] = y;
        counter++;
        if(counter == 2)
        {
        counter = 0;
        }
   }
glutPostRedisplay();
}
         
void display(void)
{  
    glColor3f(1.0 , 0.0 , 0.0); // sets the current drawing (foreground) color to blue
   
    glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
    glLoadIdentity();//multiply the current matrix by identity matrix
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);

if(check)  
{      
int i;
float theta;

          glBegin(GL_POINTS);
  for ( i = 0; i < 360 ; i ++)
{  
theta = i*3.142/180;
glVertex2f(X[0] + 10 * cos(theta), Y[0] + 10 * sin(theta));
//glVertex2f(X[1] + 10 * cos(theta), Y[1] + 10 * sin(theta));
//glVertex2f(X[2] + 10 * cos(theta), Y[2] + 10 * sin(theta));
}
/*glVertex2f(X[0], Y[0]);
glVertex2f(X[1], Y[1]);
glVertex2f(X[2], Y[2]); */
glEnd();

  glBegin(GL_POINTS);
  for ( i = 0; i < 360 ; i ++)
{  
theta = i*3.142/180;
//glVertex2f(X[0] + 10 * cos(theta), Y[0] + 10 * sin(theta));
glVertex2f(X[1] + 10 * cos(theta), Y[1] + 10 * sin(theta));

}
glEnd();

glBegin(GL_POINTS);
  for ( i = 0; i < 360 ; i ++)
{  
theta = i*3.142/180;
glVertex2f(X[2] + 10 * cos(theta), Y[2] + 10 * sin(theta));
}
glEnd();

glBegin(GL_LINE_STRIP);
glColor3f(0.00, 0.00, 1.00);
glVertex2f(X[0], Y[0]);
glVertex2f(X[1], Y[1]);
glVertex2f(X[2], Y[2]);
glEnd();
}
    glFlush();  
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Ishtpreet Singh");
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}