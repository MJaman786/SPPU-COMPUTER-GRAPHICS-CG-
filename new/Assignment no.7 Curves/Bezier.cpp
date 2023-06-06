#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

// Bezier control points
int p0x = 100, p0y = 100;
int p1x = 50, p1y = 300;
int p2x = 400, p2y = 100;
int p3x = 400, p3y = 300;

void points(){
	
	glPointSize(3);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(100,100);
	glVertex2f(100,300);
	glVertex2f(400,100);
	glVertex2f(400,300);
	glEnd();

}

void calculateBezierPoint(float t, int& x, int& y)
{
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    // Bezier formula for x and y coordinates
    x = round(uuu * p0x + 3 * uu * t * p1x + 3 * u * tt * p2x + ttt * p3x);
    y = round(uuu * p0y + 3 * uu * t * p1y + 3 * u * tt * p2y + ttt * p3y);
}

void bezier(){

	glColor3f(0.0,0.0,0.0);
    glBegin(GL_POINTS);
    for (int i = 0; i <= 1000; ++i)
    {
        float t = i / 1000.0;
        int x, y;
        calculateBezierPoint(t, x, y);
        glVertex2i(x, y);
    }

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

void display(){

    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    points();
    bezier();
    glEnd();

    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutCreateWindow("Bezier Curve");
    glutDisplayFunc(display);
    project();
    glutMainLoop();
    return 0;
}