						Assignment  : Koch Curve

#include<iostream>
#include<GL/glut.h>

void init(){

	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1080,720);
	glutInitWindowPosition(200,100);

}

void drawKochCurve(float x1, float y1, float x2, float y2, float iterations){

	if(iterations == 0){
	
		glBegin(GL_LINES);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
		glEnd();
	
	}
	else{
	
	
		float dx = (x2 - x1)/3;
		float dy = (y2 - y1)/3;
		
		float xA = x1 + dx;
		float yA = y1 + dy;
		
		float xB = x1 + 2 * dx;
		float yB = y1 + 2 * dy;
		
		float xC = xA + (xB-xA)*0.5 - (yB - yA)*0.866;
		float yC = yA + (xB-xA)*0.866 + (yB - yA)*0.5; 
		
		drawKochCurve(x1,y1,xA,yA,iterations - 1);
		drawKochCurve(xA,yA,xC,yC,iterations - 1);
		drawKochCurve(xC,yC,xB,yB,iterations - 1);
		drawKochCurve(xB,yB,x2,y2,iterations - 1);
		
	}
	
}

void display(){

	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	
	//vertex 1
	float x1 = 200;
	float y1 = 200;
	
	//vertex 2
	float x2 = 200;
	float y2 = 600;
	
	//vertex 3
	float x3 = 600;
	float y3 = 600;
	
	//vertex 4
	float x4 = 600;
	float y4 = 200;
	
	float iterations = 8;
	
	drawKochCurve(x1,y1,x2,y2,iterations);
	drawKochCurve(x2,y2,x3,y3,iterations);
	drawKochCurve(x3,y3,x4,y4,iterations);
	drawKochCurve(x4,y4,x1,y1,iterations);
	
	glFlush();
	
}

void project(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1080,0,720);
	
}

int main(int argc,char** argv){

	glutInit(&argc,argv);
	init();
	glutCreateWindow("Koch Curve");
	project();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
	
}
