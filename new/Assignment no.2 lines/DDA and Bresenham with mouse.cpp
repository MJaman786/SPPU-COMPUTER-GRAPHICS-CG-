#include <GL/glut.h>
#include <iostream>

using namespace std;

float x1,y_1,x2,y2;
float steps;
int option;

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
    gluOrtho2D(-500,500,-500,500);
}

void dda(float x1, float y_1, float x2, float y2){
	
	float dx = x2 - x1;
	float dy = y2 - y_1;
	
	if(abs(dx)>abs(dy)){
	
		steps = dx;
	
	}
	else{
	
		steps = dy;
	
	}
	
	float x_increment = dx/steps;
	float y_increment = dy/steps;
	
	float x = x1;
	float y = y_1; 
	
	switch(option){
	
		case 1:
			for(int i=0; i<steps; i++){
				glBegin(GL_POINTS);
					
					x += x_increment;
					y += y_increment;
				if(i%20==0){
				
				glVertex2f(x,y);
				
				}
				glEnd();
				glFlush();
				
			}
		break;
		
		case 2:
				glBegin(GL_POINTS);
			for(int i=0; i<steps; i++){
					
					x += x_increment;
					y += y_increment;
					
					glVertex2f(x,y);
				
			}
			glEnd();
			glFlush();
		break;
	
	}
}

void bresenham(float x1, float y_1, float x2, float y2){
	
	float dx = x2 - x1;
	float dy = y2 - y_1;
	
	float x = x1;
	float y = y_1;
	
	float d = 2 * dy - dx;
	
	glBegin(GL_POINTS);
	while(x<x2){
	
		if(d>0){
		
			x++;
			y++;
			
			d += 2 * (dy - dx); 
		}
		else{
		
			x++;
			d += 2 * dy;
		
		}
		glVertex2f(x,y);
	}
	glEnd();
	glFlush();
}

void mouse(int button, int state, int x, int y){

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		
		x1  = x - 500/2;
		y_1 = 500/2 - y;
		
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        x2 = x - 500/2;
        y2 = 500/2 - y; // Flip the y-coordinate to match OpenGL's coordinate system
        
        bresenham(x1,y_1,x2,y2);
        
    }
   
}

void display(){

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    dda(-500,0,500,0);
    dda(0,-500,0,500);
    glFlush();

}



int main(int argc, char** argv)
{	
	
	cout<<"1.Dotted Line"<<endl;
	cout<<"2.Simple Line"<<endl;
	cout<<"Enter option = ";
	cin>>option;	
	
    glutInit(&argc, argv);
    init();
    glutCreateWindow("Assignment 2");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    project();
    glutMainLoop();
    return 0;
}