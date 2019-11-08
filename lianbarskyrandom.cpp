#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<random>

using namespace std;
int iteration=1;
int x1=0,x2=0,y3=0,y2=0;
typedef struct cordiantePoint{
int x;
int y;
}cordiantePoint;

cordiantePoint a, b;
float u1=0,u2=1;
int xmin=-50,ymin=-50,xmax=50,ymax=50;
double p[4],q[4];
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320,320,-240,240);
}
void clip(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1,dy=y2-y1,i;
    double t;
    p[0]=-dx;q[0]=x1-xmin;
    p[1]=dx;q[1]=xmax-x1;
    p[2]=-dy;q[2]=y1-ymin;
    p[3]=dy;q[3]=ymax-y1;

    for(i=0;i<4;i++)
    {
        if(p[i]==0 && q[i]<0)
            return;
        if(p[i]<0)
        {
            t=(q[i])/(p[i]);  
            if(t>u1 && t<u2)
                {u1=t;}
        }
        else if(p[i]>0)
        {
            t=(q[i])/(p[i]);  // This calculation was returning a zero because both q and p were int
            if(t>u1 && t<u2)
                {u2=t;}
        }
    }
    if(u1<u2)
    {
        x1=x1+u1*(x2-x1);
        y1=y1+u1*(y2-y1);
        x2=x1+u2*(x2-x1);
        y2=y1+u2*(y2-y1);
        glBegin(GL_LINES);
            glVertex2i(-50,-50);
            glVertex2i(-50,50);
            glVertex2i(-50,50);
            glVertex2i(50,50);
            glVertex2i(50,50);
            glVertex2i(50,-50);
            glVertex2i(50,-50);
            glVertex2i(-50,-50);
        glEnd();
        glFlush();
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINES);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glEnd();
        glFlush();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
      glVertex2i(x1,y3);
    glVertex2i(x2,y2);
   glEnd();
   glFlush();
        glBegin(GL_LINES);
            glVertex2i(-50,-50);
            glVertex2i(-50,50);
            glVertex2i(-50,50);
            glVertex2i(50,50);
            glVertex2i(50,50);
            glVertex2i(50,-50);
            glVertex2i(50,-50);
            glVertex2i(-50,-50);
        glEnd();
        glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && iteration==1)
			{
				a.x = x;
				a.y =480 - y;
				iteration++;
			}	
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && iteration==2)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		b.x = x;
		b.y = 480 - y;
	//	printf("(%d, %d)\t", a.x, a.y);
	//	printf("(%d, %d)\t", b.x, b.y);
		glFlush();
		glutPostRedisplay();
		iteration++;
	}
}

void myKey(unsigned char key,int x,int y)
{
glClear(GL_COLOR_BUFFER_BIT);
    if(key=='c')
    {
          clip(::x1,y3,x2,y2);
    }


}

int randomm()
{
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(-200, 200); // define the range    
    return distr(eng);
}
int main(int argc,char ** argv)
{
	x1 = randomm();
	x2 = randomm();
	y3 = randomm();
	y2 = randomm();
	cout<<x1<<"\t"<<x2<<"\t"<<y3<<"\t"<<y2;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Clip || Ishtpreet Singh");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKey);
    glutMouseFunc(myMouseFunc);
    init();
    glutMainLoop();
    return 0;
}
