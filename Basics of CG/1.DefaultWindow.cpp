//this code is only for creating default size window.

#include<GL/glut.h>

void display()
{
	
}

int main(int argc, char** argv)
{
	glutInit(& argc,argv);
	glutCreateWindow("Basic OpenGl Program"); //this is API.
	glutDisplayFunc(display); //function swhould have zero parameters and no writen type.
	glutMainLoop();
	return 0;
}


//aman@aman-virtual-machine:~$ g++ CreateWindow.cpp -o CreateWindow -lglut -lGLU -lGL
//aman@aman-virtual-machine:~$ ./CreateWindow
