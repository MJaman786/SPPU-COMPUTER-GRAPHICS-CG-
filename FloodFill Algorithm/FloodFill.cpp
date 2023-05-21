#include<iostream>
#include<GL/glut.h>

void init(){

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(500,200);

}

void project(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1080,0,720);

}

void polygon(){

	glBegin(GL_POLYGON);
	glVertex2i(300,100);
	glVertex2i(300,500);
	glVertex2i(700,500);
	glVertex2i(700,100);
	glEnd();

}

void floodfill(float x, float y, float fillcolor[], float interiorcolor[]){
	
	float color[3];
	glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
		
	if(color[0] == interiorcolor[0] && color[1] == interiorcolor[1] && color[2] == interiorcolor[2]){
	
		glColor3fv(fillcolor);
		glBegin(GL_POINTS);
			glVertex2i(x,y);
		glEnd();
		glFlush();
		floodfill(x+1, y, fillcolor, interiorcolor);
		floodfill(x-1, y, fillcolor, interiorcolor);
		floodfill(x, y+1, fillcolor, interiorcolor);
		floodfill(x, y-1, fillcolor, interiorcolor);
	
	}

}

void mouse(int button, int state, int x, int y){

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		
		int xi = x;
		int yi = 720 - y;
		
		float fillcolor     [] = {1.0,0.0,0.0};
		float interiorcolor [] = {1.0,1.0,1.0};
		
		floodfill(xi,xi,fillcolor,interiorcolor);
		
	}

}

void display(){

	polygon();
	glFlush();

}

int main(int argc,char** argv){

	glutInit(&argc,argv);
	init();
	glutCreateWindow("Ploygon");
	project();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();

	return 0;

}
