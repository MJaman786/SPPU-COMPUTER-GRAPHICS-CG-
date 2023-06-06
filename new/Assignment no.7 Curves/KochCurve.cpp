#include <GL/glut.h>
#include <iostream>

using namespace std;

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

void koch(float x1, float y1, float x2, float y2, float iterations){

	if(iterations <= 0){
	
		glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glEnd();
		glFlush();
	
	}
	else{
	
		float dx = (x2 - x1)/3;
		float dy = (y2 - y1)/3;
		
		float xA = x1 + dx;
		float yA = y1 + dy;
		
		float xB = x1 + 2 * dx;
		float yB = y1 + 2 * dy;
		
		float xC = xA + (xB - xA) * 0.5 - (yB - yA) * 0.866;
		float yC = yA + (xB - xA) * 0.866 + (yB - yA) * 0.5;
		
		koch(x1,y1,xA,yA,iterations-1);
		koch(xA,yA,xC,yC,iterations-1);
		koch(xC,yC,xB,yB,iterations-1);
		koch(xB,yB,x2,y2,iterations-1);   
	
	} 

}

void display(){

    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    
    float x1 = 100;
    float y1 = 200;
    float x2 = 250;
    float y2 = 400;
    float x3 = 400;
    float y3 = 200;
    
    float iterations = 5;
    
    koch(x1,y1,x2,y2,iterations);
    koch(x2,y2,x3,y3,iterations);
    koch(x3,y3,x1,y1,iterations);
    
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutCreateWindow("Koch Curve");
    glutDisplayFunc(display);
    project();
    glutMainLoop();
    return 0;
}