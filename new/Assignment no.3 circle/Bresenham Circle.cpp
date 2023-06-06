#include<GL/glut.h>
#include<iostream>

using namespace std;

float xc,yc,radius;

void line(float x1,float y1, float x2, float y2){
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	glFlush();
	
}

void circle(float xc, float yc, float radius){

	float x = 0;
	float y = radius;
	
	float d = 3 - 2 * radius;
	
	while(x<y){
		
		glColor3f(1.0,0.0,1.0);
		glPointSize(2);
		glBegin(GL_POINTS);
		glVertex2f(xc + x , yc + y);
		glVertex2f(xc + x , yc - y);
		glVertex2f(xc - x , yc + y);
		glVertex2f(xc - x , yc - y);
		glVertex2f(xc + y , yc + x);
		glVertex2f(xc + y , yc - x);
		glVertex2f(xc - y , yc + x);
		glVertex2f(xc - y , yc - x);
		glEnd();
		
		if(d<0){
		
			x++;
			d += 4 * x + 6; 
		
		}
		else{
		
			x++;
			y--;
			d += 4 * (x - y) + 10;
		
		}
	
	}

}

void init(){

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);

}

void project(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);

}

void display(){

	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	line(-500,0,500,0);
	line(0,-500,0,500);
	circle(xc , yc , radius); //middle
	circle(xc+2*radius , yc , radius); // x+
	circle(xc , yc+2*radius , radius); // y+ 
	circle(xc-2*radius , yc , radius); // x-
	circle(xc , yc-2*radius , radius); // y-
	glFlush();	

}

int main(int argc, char** argv){

	cout<<"Enter X-cordinate = ";
	cin>>xc;
	cout<<"Enter Y-cordinate = ";
	cin>>yc;
	cout<<"Enter Radius = ";
	cin>>radius;

	glutInit(&argc,argv);
	init();
	glutCreateWindow("Bresenham circle");
	project();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}