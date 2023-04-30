#include<iostream>
#include<GL/glut.h>

using namespace std;

void init(void){

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(500,100);

}

float start_x,start_y;
float end_x,end_y;
float steps;

void DDA(){

	float dx = end_x-start_y;
	float dy = end_y-start_y;
	
	if(dx>dy)
	{
		
			steps = dx;
		
	}
	else
	{
	
			steps = dy;
		
	}
	
	//incrementing  value for x and y
	float x_increment = dx/steps;
	float y_increment = dy/steps;
	
	//initalize starting point(start_x,start_y)==(x1,y1)
	float x = start_x;
	float y = start_y;
	
	glBegin(GL_POINTS);
	
	for(int i=0; i<steps; i++){
	
		glVertex2f(x,y);
		
		x+=x_increment;
		y+=y_increment;
	
	}
	
	glEnd();
	glFlush();

}

void display(void){

	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,1.0);
	glPointSize(2);
	glLineWidth(5);
	DDA();
	glFlush();

}

int main(int argc, char** argv){

	cout<<"Enter start X1 and Y1 = ";
	cin>> start_x >> start_y;
	cout<<endl;
	
	cout<<"Enter end X2 and Y2 = ";
	cin>> end_x >> end_y;

	glutInit(& argc,argv);
	init();
	glutCreateWindow("DDA");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1080,0,720);
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}

/*
OUTPUT = 

aman@aman-virtual-machine:~$ g++ DDA.cpp -o DDA -lglut -lGLU -lGL
aman@aman-virtual-machine:~$ ./DDA

Enter start X1 and Y1 = 100 100

Enter end X2 and Y2 = 600 600


*/
