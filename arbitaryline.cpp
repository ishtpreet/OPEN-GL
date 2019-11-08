#include <gl/glut.h>
#include <math.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int flag = 0;
float matrix[3][3]={{-100, 50, 1},{100, 50, 1},{0, 100, 1}};
void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
	{
	glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINES);
			glVertex2f(0,500);
			glVertex2f(0,-500);
			glVertex2f(-500,0);
			glVertex2f(500,0);
		glEnd();
		glFlush();
		
		cout<<"Before transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"   ";
			}
			cout<<endl;
		}
			
		glColor3f(0.0,1.0,1.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
		
		float m,ic;
		//cout<<"Enter the slope ";
		//cin>>m;
		m =-2;
		//cout<<"Enter the intercept ";
		//cin>>ic;
		ic = -4;
		
		float a1=(1-m*m)/(1+m*m);
		float b=2*m/(m*m+1);
		float c=-2*ic*m/(m*m+1);
		float d=2*ic/(m*m+1);
		float a[3][3]={{a1,b,0},{b,-a1,0},{c,d,1}};
		float ans[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				ans[i][j]=0;
		 		for(int k=0;k<3;k++)
		 		{
		  			ans[i][j]=matrix[i][k]*a[k][j]+ans[i][j];
		 		}
			}
		}
		
		matrix[0][0] = ans[0][0];
		matrix[0][1] = ans[0][1];
		matrix[1][0] = ans[1][0];
		matrix[1][1] = ans[1][1];
		matrix[2][0] = ans[2][0];
		
		cout<<"After transformation matrix is "<<endl;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				cout<<matrix[i][j]<<"  ";
			}
			cout<<endl;
		}
		
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
		glEnd();
		glFlush();
	
	}
}

void init() 
{
		glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
			glVertex2f(matrix[0][0], matrix[0][1]);
			glVertex2f(matrix[1][0], matrix[1][1]);
			glVertex2f(matrix[2][0], matrix[2][1]);
			glEnd();
			glFlush();
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(0,500);
	glVertex2i(0,-500);
	glVertex2i(-500,0);3
	glVertex2i(500,0);
	glEnd();
	glFlush(); 
}

int main(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Mouse Func");
	glutDisplayFunc(display);
	glutMouseFunc(myMouseFunc);
	//glutKeyboardFunc(processKeys);
	init();
	glutMainLoop();
	return 0;
}
