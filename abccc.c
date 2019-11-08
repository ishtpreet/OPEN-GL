#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
int iteration = 1;
typedef struct cordiantePoint{
float x;
float y;
}cordiantePoint;

cordiantePoint xy1, xy2, xy3, xy4;

void myMouseFunc(int button, int state, int x, int y)
{
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && iteration==1)
			{
				xy1.x = x;
				xy1.y =480 - y;
				iteration++;
			}
		
		
		   else	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && iteration==2)
			{
				xy2.x = x;
				xy2.y =480 - y;
				iteration++;
			}
			
			else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && iteration==3)
			{
				xy3.x = x;
				xy3.y =480 - y;
				iteration++;
			}
	
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && iteration==4)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		xy4.x = x;
		xy4.y = 480 - y;
		printf("(%f, %f)\t", xy1.x, xy1.y);
		printf("(%f, %f)\t", xy2.x, xy2.y);
		printf("(%f, %f)\t", xy3.x, xy3.y);
		printf("(%f, %f)\n", xy4.x, xy4.y);
		glFlush();
		glutPostRedisplay();
		iteration++;
	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && iteration==5)
	{
			float bCol[] = {1,1,0};
            float color[] = {0,1,1};
            bound_it(x,480 - y,color,bCol); 
					                
	}
	else if(button == GLUT_RIGHT_BUTTON && state== GLUT_DOWN && iteration==5)	
	{
		float intCol[] = {1,0,0};
            float color[] = {0,0,1};
            glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,intCol);
           flood_it(x,480-y,color,intCol);
				
	}
	

}

void init() 
{
 glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void display()
{
//glClear(GL_COLOR_BUFFER_BIT);
glLineWidth(3);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_LINE_LOOP);
glColor3f(1, 1, 0.00);
glVertex2i(xy1.x, xy1.y);
glVertex2i(xy2.x, xy2.y);
glVertex2i(xy3.x, xy3.y);
glVertex2i(xy4.x, xy4.y);
glEnd();
glFlush();
    
}

void keyPressed (unsigned char key, int x, int y)
{  
	if (key == 27) { 
	// bound_it(x,480 - y,color,bCol); 
	
}
	else if(key==32)
	{
		//flood_it(x,480 - y,color,bCol);
	} 
}
void flood_it(int x, int y, float* fillColor, float* ic){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if(color[0]==ic[0] && color[1]==ic[1] && color[2]==ic[2]){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        flood_it(x-2,y,fillColor,ic);
        flood_it(x+1,y,fillColor,ic);
        flood_it(x,y+1,fillColor,ic);
        flood_it(x,y-2,fillColor,ic);
    }
}


void bound_it(int x, int y, float* fillColor, float* bc){
    float color[3];
    glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
    if((color[0]!=bc[0] || color[1]!=bc[1] || color[2]!=bc[2])&&(
     color[0]!=fillColor[0] || color[1]!=fillColor[1] || color[2]!=fillColor[2])){
        glColor3f(fillColor[0],fillColor[1],fillColor[2]);
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        glFlush();
        bound_it(x+1,y,fillColor,bc);
        bound_it(x-2,y,fillColor,bc);
        bound_it(x,y+2,fillColor,bc);
        bound_it(x,y-2,fillColor,bc);
    }
}

int main(int argc, char **argv) 
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(200, 200);
glutInitWindowSize(640, 480);
glutCreateWindow("VIVA || Ishtpreet Singh");
glutDisplayFunc(display);
glutMouseFunc(myMouseFunc);
glutKeyboardFunc(keyPressed);
init();
glutMainLoop();
return 0;
}
