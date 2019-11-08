#include<GL/glut.h>
#include<math.h>
void display()
{	
	
}

void myMouseFunc(int button, int state, int x, int y)
{
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			{
				if(x<320)
				{
					DrawCircle(160,240,5,5);
				}	
				else
				{
					drawellipse(160,240,25,50,5);
				}
			}
			
	

}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	int ii;
	float theta,x,y;
    glBegin(GL_LINE_LOOP);
    for(ii = 0; ii < num_segments; ii++)
    {
        theta = 2.0f * 3.1415926f * ii / num_segments;//get the current angle

        x = r * cosf(theta);//calculate the x component
        y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void drawellipse(float cx, float cy, float rx, float ry, int num_segments) 
{ 
	float theta,c,s,x,y;
    theta = 2 * 3.1415926 / num_segments; 
    c = cosf(theta);//precalculate the sine and cosine
    s = sinf(theta);
    float t;
    int ii;

    x = 1;//we start at angle = 0 
    y = 0; 

    glBegin(GL_LINE_LOOP); 
    for(ii = 0; ii < num_segments; ii++) 
    { 
        //apply radius and offset
        glVertex2f(x * rx + cx, y * ry + cy);//output vertex 

        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    } 
     glFlush();
	 
	 glutSwapBuffers();
	 glutPostRedisplay();
     glEnd(); 
   
}

void init() 
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0f, 640.0f, 0.0f, 480.0f);
}

int main(int argc,char **argv)
{
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutCreateWindow(argv[0]);
	init();	
	glutMouseFunc(myMouseFunc);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
