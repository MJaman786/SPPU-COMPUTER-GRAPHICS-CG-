#include <GL/glut.h>
#include <iostream>

using namespace std;
	
void polygon(){

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(100,100);
    	glVertex2f(100,400);
    	glVertex2f(400,400);
    	glVertex2f(400,100);
	glEnd();
	glFlush();

}
void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
}

void project()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

void floodfill(int x,int y,float fillcolor[],float interiorcolor[]){

	float color[3];
	glReadPixels(x , y , 1.0 , 1.0 , GL_RGB , GL_FLOAT , color);
	if(color[0]==interiorcolor[0] && color[1]==interiorcolor[1] && color[2]==interiorcolor[2]){
	
		glColor3fv(fillcolor);
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
		glFlush();
		
		floodfill(x+1,y,fillcolor,interiorcolor);
		floodfill(x-1,y,fillcolor,interiorcolor);
		floodfill(x,y+1,fillcolor,interiorcolor);
		floodfill(x,y-1,fillcolor,interiorcolor);
		
	}

}

void boundaryfill(int x, int y, float fillcolor[], float boundarycolor[]){

float color[3];
	glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,color);
	if((color[0] != boundarycolor[0] || color[1] != boundarycolor[1] || color[2] != boundarycolor[2]) &&
		(color[0] != fillcolor[0] || color[1] != fillcolor[1] || color[2] != fillcolor[2]))
		{
	
			glColor3fv(fillcolor);
			glBegin(GL_POINTS);
			glVertex2f(x,y);
			glEnd();
			glFlush();
			
			boundaryfill(x+1,y,fillcolor,boundarycolor);
			boundaryfill(x-1,y,fillcolor,boundarycolor);
			boundaryfill(x,y+1,fillcolor,boundarycolor);
			boundaryfill(x,y-1,fillcolor,boundarycolor);
	
		}

}

void mouse(int button, int state, int x, int y){

	int xi = x;
	int yi = 500 - y;
	
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	
		float fillcolor[]={1.0,0.0,0.0};
		float interiorcolor[]={1.0,1.0,1.0};
		
		floodfill(xi , yi , fillcolor , interiorcolor); 
	
	}
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
		
		int xi = x;
		int yi = 500 - y;
		
		float fillcolor[]={1.0,0.0,1.0};
		float boundarycolor[]={1.0,1.0,1.0};
		
		boundaryfill(xi,yi,fillcolor,boundarycolor);
		
	}

}

void display(){

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    polygon();
    
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutCreateWindow("POLYGON FILLING");
    glutDisplayFunc(display);
 	glutMouseFunc(mouse);
    project();
    glutMainLoop();
    return 0;
}