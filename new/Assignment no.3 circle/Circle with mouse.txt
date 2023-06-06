#include <GL/glut.h>
#include <iostream>

using namespace std;

int xc = 0;
int yc = 0;
int r =  100;

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
    gluOrtho2D(-500 , 500 , -500 , 500);
}

void line(int x1, int y1,int x2,int y2){
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	glFlush();
}

void circle(int xc,int yc,int r){

	int x = 0;
	int y = r;
	
	int d = 3 - 2 * r;
	
	while(x<y){
				
			glPointSize(3);
			glColor3f(1.0,0.0,1.0);
			glBegin(GL_POINTS);
		glVertex2f(xc + x , yc + y);
		glVertex2f(xc + x , yc - y);
		glVertex2f(xc - x , yc + y);
		glVertex2f(xc - x , yc - y);
		glVertex2f(xc + y , yc + x);
		glVertex2f(xc + y , yc - x);
		glVertex2f(xc - y , yc + x);
		glVertex2f(xc - y , yc - x);	
		
		if(d<0){
		
			x++;
			d += 4 * x + 6;
		
		}
		else{
		
			x++;
			y--;
			d += 4 * (x - y) + 10;
		
		}
	glVertex2f(x,y);

	}
	glEnd();
	glFlush();

}

void mouse(int button,int state,int x,int y){

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	
		xc = x - 500/2;
		yc = 500/2 - y;
		r  = 150;
		circle(xc,yc,r);
	
	}
	
}

void display(){

    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    line(-500,0,500,0);
    line(0,-500,0,500);
    circle(xc , yc , r);
    circle(xc+2*r , yc , r);
    circle(xc-2*r , yc , r);
    circle(xc , yc+2*r , r);
    circle(xc , yc-2*r , r);
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutCreateWindow("");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    project();
    glutMainLoop();
    return 0;
}