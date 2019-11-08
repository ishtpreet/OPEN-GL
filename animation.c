#include<GL/glut.h>
#include<math.h>
#define DEG_TO_RAD 0.017453


GLfloat theta = 0.0;

void mydisplay()

{

  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
glColor3f(1.0, 0.0, 0.0);
    glVertex2f(cos(DEG_TO_RAD*theta), sin(DEG_TO_RAD*theta));
  glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-sin(DEG_TO_RAD*theta), cos(DEG_TO_RAD*theta));
  glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-cos(DEG_TO_RAD*theta), -sin(DEG_TO_RAD*theta));
  glColor3f(1.0, 1.0, 1.0);
    glVertex2f(sin(DEG_TO_RAD*theta), -cos(DEG_TO_RAD*theta));
  glEnd();
  glutSwapBuffers();
}
void spinDisplay(void)

{
  theta -= 1;
  if (theta < -360.0) theta += 360.0;
  glutPostRedisplay();

}
void init()

{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glColor3f(1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 gluOrtho2D(-4.0, 4.0, -4.0, 4.0);
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(640,480);
glutCreateWindow("Ishtpreet Singh");
init();
glutDisplayFunc(mydisplay);
glutMainLoop();
}
