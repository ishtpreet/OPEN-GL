#include<GL/glut.h>
#include<math.h>

void init()
{
  glClearColor(1.0,1.0,1.0,1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 100, 0, 100);
}

void display()
{
//	glClearColor(0.7956413,0.0,0.1,1);
    glClearColor(1.0,1.0,1.0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
// sky
   // glColor3f(0.85,0.5,1.0);
   glColor3f(0.5,1.0,1.0);
	glBegin(GL_QUADS);
	glVertex2f (0,100);
    glVertex2f (0,50);
    glVertex2f (100,50);
    glVertex2f (100,100);    
    glEnd();
   // ground 
    glColor3f(0.0,1.0,0.0);
	glBegin(GL_QUADS);
	glVertex2f (0,0);
    glVertex2f (100,0);
    glVertex2f (100,50);
    glVertex2f (0,50);    
    glEnd();
    
    // sun
    float theta; int i,j;
	
	glColor3f(1.0,1.0,0.0);
	
	glBegin(GL_POLYGON);
		
	for(i=0;i<360;++i)
	{
		theta = i*3.142/180;
		glVertex2f(67+7*cos(theta),90+7*sin(theta));
	}
	
    
	
	glEnd();
	
	// mountains    glColor3f(0.85,0.5,1.0) 
    glColor3f(0.2,0.5,0.0);
	//glColor3f(0.85,0.5,1.0);
	glBegin(GL_TRIANGLES);
	    glVertex2f (0, 50);
        glVertex2f (30, 50);
    glColor3f(1.0,1.0,1.0);
        glVertex2f (15,85);
       glEnd();
       
       
    glColor3f(0.2,0.5,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f (30, 50);
    glVertex2f (70,50);
	glColor3f(1.0,1.0,1.0);
	    glVertex2f (50, 90);

       glEnd();
       
    glColor3f(0.2,0.5,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f (70, 50);
    glVertex2f (100,50);
    glColor3f(1.0,1.0,1.0);
	    glVertex2f (85, 85);
        
       glEnd();
       
       // hut
      glColor3f(1.0,0.0,0.0);
       glBegin(GL_QUADS);
       glVertex2f (10,5);
       glVertex2f (45,5);
       glVertex2f (45,35);
       glVertex2f (10,35);
	   
	   glEnd(); 
       //door
        glColor3f(0.82,0.41,0.117);
       glBegin(GL_QUADS);
       glVertex2f (22.5,5);
       glVertex2f (22.5,20);
       glVertex2f (32.5,20);
       glVertex2f (32.5,5);
       
	   
	   glEnd(); 
	// triangle   
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f (10, 35);
    glVertex2f (45,35);
	glVertex2f (27.5,50);
        
       glEnd();
       
       // tree1
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(65,25);
       glVertex2f(80,25);
       glVertex2f(72.5,40);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(65,30);
       glVertex2f(80,30);
       glVertex2f(72.5,45);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(65,35);
       glVertex2f(80,35);
       glVertex2f(72.5,50);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(65,40);
       glVertex2f(80,40);
       glVertex2f(72.5,55);
       glEnd();
      
	  // bar1
	    glColor3f(0.35,0.0,0.0);
       glBegin(GL_QUAD_STRIP);
       glVertex2f (70,10);
       glVertex2f (75,10);
       glVertex2f (70,25);
       glVertex2f (75,25);
       glEnd();
	   
	    // tree2
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(81,25);
       glVertex2f(100,25);
       glVertex2f(91.5,40);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(81,30);
       glVertex2f(100,30);
       glVertex2f(91.5,45);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(81,35);
       glVertex2f(100,35);
       glVertex2f(91.5,50);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(81,40);
       glVertex2f(100,40);
       glVertex2f(90.5,55);
       glEnd();
      
	  // bar2
	    glColor3f(0.35,0.0,0.0);
       glBegin(GL_QUAD_STRIP);
       glVertex2f (88,10);
       glVertex2f (94,10);
       glVertex2f (88,25);
       glVertex2f (94,25);
       glEnd();
	   
       
       
    
       glFlush();
}
void keyPressed (unsigned char key, int x, int y)

{
    if(key==32)
    {
    //	glClearColor(0.7956413,0.0,0.1,1);
    glClearColor(1.0,1.0,1.0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
// sky
   // glColor3f(0.85,0.5,1.0);
   glColor3f(.5,.5,.5);
	glBegin(GL_QUADS);
	glVertex2f (0,100);
    glVertex2f (0,50);
    glVertex2f (100,50);
    glVertex2f (100,100);    
    glEnd();
   // ground 
    glColor3f(.5,1.0,0.5);
	glBegin(GL_QUADS);
	glVertex2f (0,0);
    glVertex2f (100,0);
    glVertex2f (100,50);
    glVertex2f (0,50);    
    glEnd();
    
    // sun
    float theta; int i,j;
	
	glColor3f(1.0,1.0,1);
	
	glBegin(GL_POLYGON);
		
	for(i=0;i<360;++i)
	{
		theta = i*3.142/180;
		glVertex2f(30+7*cos(theta),90+7*sin(theta));
	}
	
    
	
	glEnd();
	
	// mountains    glColor3f(0.85,0.5,1.0) 
    glColor3f(0.2,0.5,0.0);
	//glColor3f(0.85,0.5,1.0);
	glBegin(GL_TRIANGLES);
	    glVertex2f (0, 50);
        glVertex2f (30, 50);
    glColor3f(1.0,1.0,1.0);
        glVertex2f (15,85);
       glEnd();
       
       
    glColor3f(0.2,0.5,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f (30, 50);
    glVertex2f (70,50);
	glColor3f(1.0,1.0,1.0);
	    glVertex2f (50, 90);

       glEnd();
       
    glColor3f(0.2,0.5,0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f (70, 50);
    glVertex2f (100,50);
    glColor3f(1.0,1.0,1.0);
	    glVertex2f (85, 85);
        
       glEnd();
       
       // hut
      glColor3f(1.0,0.0,0.0);
       glBegin(GL_QUADS);
       glVertex2f (10,5);
       glVertex2f (45,5);
       glVertex2f (45,35);
       glVertex2f (10,35);
	   
	   glEnd(); 
       //door
        glColor3f(0.82,0.41,0.117);
       glBegin(GL_QUADS);
       glVertex2f (22.5,5);
       glVertex2f (22.5,20);
       glVertex2f (32.5,20);
       glVertex2f (32.5,5);
       
	   
	   glEnd(); 
	// triangle   
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f (10, 35);
    glVertex2f (45,35);
	glVertex2f (27.5,50);
        
       glEnd();
       
       // tree1
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(65,25);
       glVertex2f(80,25);
       glVertex2f(72.5,40);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(65,30);
       glVertex2f(80,30);
       glVertex2f(72.5,45);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(65,35);
       glVertex2f(80,35);
       glVertex2f(72.5,50);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(65,40);
       glVertex2f(80,40);
       glVertex2f(72.5,55);
       glEnd();
      
	  // bar1
	    glColor3f(0.35,0.0,0.0);
       glBegin(GL_QUAD_STRIP);
       glVertex2f (70,10);
       glVertex2f (75,10);
       glVertex2f (70,25);
       glVertex2f (75,25);
       glEnd();
	   
	    // tree2
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(81,25);
       glVertex2f(100,25);
       glVertex2f(91.5,40);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(81,30);
       glVertex2f(100,30);
       glVertex2f(91.5,45);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(81,35);
       glVertex2f(100,35);
       glVertex2f(91.5,50);
       glEnd();
       
       glColor3f(0.0,0.2,0.0);
       glBegin(GL_TRIANGLES);
       glVertex2f(81,40);
       glVertex2f(100,40);
       glVertex2f(90.5,55);
       glEnd();
      
	  // bar2
	    glColor3f(0.35,0.0,0.0);
       glBegin(GL_QUAD_STRIP);
       glVertex2f (88,10);
       glVertex2f (94,10);
       glVertex2f (88,25);
       glVertex2f (94,25);
       glEnd();
	   
       
       
    
       glFlush();
    }
}

int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(640,480);
glutCreateWindow("Ishtpreet Singh");
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyPressed);
glutMainLoop();
}
