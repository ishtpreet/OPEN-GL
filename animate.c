#include<GL/glut.h>
#include<math.h>

GLfloat theta,thetar;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    thetar=theta/(3.14159/180.0);        
    glVertex2f(cos(thetar),sin(thetar));
    glVertex2f(-sin(thetar),cos(thetar));
    glVertex2f(-cos(thetar),-sin(thetar));
    glVertex2f(sin(thetar),-cos(thetar));
    glEnd();
    glFlush();
    glutSwapBuffers();
}
void idle()
{
    theta+=2;
    if(theta>=360.0) theta-=360.0;
    glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)      

{
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    glutIdleFunc(idle);
    if(button==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
        glutIdleFunc(NULL);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutCreateWindow("Ishtpreet Singh");
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
