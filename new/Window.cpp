#include <GL/glut.h>
#include <iostream>

using namespace std;

void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(200, 100);
}

void project()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1080, 0, 720);
}

void display(){

    glClearColor(0.0,0.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    init();
    glutCreateWindow("Translation");
    glutDisplayFunc(display);
    project();
    glutMainLoop();
    return 0;
}