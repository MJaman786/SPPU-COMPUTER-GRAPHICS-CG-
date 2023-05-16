#include <GL/glut.h>
#include <stdio.h>


void drawLine(int x1, int y1, int x2, int y2) {
	glBegin(GL_LINES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}


void drawPolygon() {
/*
	drawLine(100, 100, 300, 100);
	drawLine(300, 100, 300, 300);
	drawLine(300, 300, 100, 300);
	drawLine(100, 300, 100, 100);
*/	
	glBegin(GL_LINE_LOOP);
	glVertex2i(200,200);
	glVertex2i(200,400);
	glVertex2i(400,400);
	glVertex2i(400,200);
	glEnd();
	glFlush();
}


void cordinate(){
	
	glBegin(GL_LINES);
	glVertex2i(100,100);
	glVertex2i(100,460);
	glVertex2i(100,100);
	glVertex2i(630,100);
	glEnd();
	//glVertex2i(200,200);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    cordinate();
    drawPolygon();
    glFlush();
}




void floodFill4(int x, int y, float fillColor[], float interiorColor[]) {
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color);
    if(color[0] == interiorColor[0] && color[1] == interiorColor[1] && color[2] == interiorColor[2]) {
        glColor3fv(fillColor);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();
        floodFill4(x + 1, y, fillColor, interiorColor);
        floodFill4(x - 1, y, fillColor, interiorColor);
        floodFill4(x, y + 1, fillColor, interiorColor);
        floodFill4(x, y - 1, fillColor, interiorColor);
    }
}

void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int xi = x;
        int yi = (480 - y);
        float fillColor[] = {1.0, 0.0, 0.0};
        float interiorColor[] = {0.0, 0.0, 0.0};
        floodFill4(xi, yi, fillColor, interiorColor);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Flood Fill Algorithm");
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

/*
In this implementation, the floodFill4() function is used to recursively fill the closed boundary with the fillColor specified by the user. The glReadPixels() function is used to read the color of the pixel at (x,y), and if the color matches the interiorColor, the fillColor is set and the pixel is filled. The function then recursively calls itself for the neighboring pixels until the boundary is completely filled.

The mouse() function is used to capture the user's input and pass it to the floodFill4() function. In this example, the user clicks on the screen with the left mouse button, and the algorithm starts filling the boundary from that point.

The main function initializes the OpenGL environment and sets up the display, mouse, and keyboard functions. Finally, the main loop of the program is started with the glutMainLoop() function.
*/

