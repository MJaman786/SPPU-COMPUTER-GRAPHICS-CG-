//this code is creating GL_POINTS window.

#include<GL/glut.h>

void init()
{
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE); //DisplayMode API for screen display mode.
	glutInitWindowSize(600,600); //WindowSize API.
	glutInitWindowPosition(500,500); //WindowPosition API.
	
}
void display()
{
	glClearColor(0.2,0.5,0.5,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10);
	
	glBegin(GL_POINTS);	//Start of group
	glVertex2f(-0.5,0.5);
	glVertex2f(0.5,0.5);
	glVertex2f(0.5,-0.5);
	glVertex2f(-0.5,-0.5);
	glEnd(); //end of group.
	
	glFlush();
}

int main(int argc, char** argv) //passing parametrs.
{
	glutInit(& argc,argv);		//initalizing glut library
	init();
	glutCreateWindow("Customized Window"); //this is API.
	glutDisplayFunc(display); //function swhould have zero parameters and no writen type.
	glutMainLoop();
	return 0;
}


//aman@aman-virtual-machine:~$ g++ CreateWindow.cpp -o CreateWindow -lglut -lGLU -lGL
//aman@aman-virtual-machine:~$ ./CreateWindow
