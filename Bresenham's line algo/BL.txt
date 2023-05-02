#include <GL/glut.h> // Include the GLUT library
#include<iostream>

using namespace std;


int x1, y_1, x2, y2; // Starting and ending points of the line

void init(){

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(500, 500); // Set the window size
    glutInitWindowPosition(100, 100); // Set the window position	
	
}

void project(){

	glMatrixMode(GL_PROJECTION); // Set the projection matrix
    glLoadIdentity(); // Load the identity matrix
    gluOrtho2D(0, 500, 0, 500); // Set the orthographic viewing area
    // glMatrixMode(GL_MODELVIEW); // Set the modelview matrix
    // glLoadIdentity(); // Load the identity matrix

}

// Bresenham's algorithm for drawing a line
void drawLine(int x1, int y_1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y_1;
    int x = x1;
    int y = y_1;
    int d = 2 * dy - dx;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    while (x < x2) {
        if (d > 0) {
            y++;
            d += 2 * (dy - dx);
        } else {
            d += 2 * dy;
        }
        x++;
        glVertex2i(x, y);
    }
    glEnd();
    glFlush();
}

// Display function
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the background color to black
    
    drawLine(x1, y_1, x2, y2); // Call the drawLine function with the starting and ending points of the line
}

// Main function
int main(int argc, char** argv) {
    cout<<"Enter the starting point of the line (x1, y_1): ";
    cin>>x1>>y_1;
    cout<<"Enter the ending point of the line (x2, y2): ";
    cin>>x2>>y2;
    glutInit(&argc, argv); // Initialize GLUT
    init();
    glutCreateWindow("Bresenham Line Drawing Algorithm"); // Create the window
    
    project();
    
    glutDisplayFunc(display); // Set the display callback function
    glutMainLoop(); // Enter the main loop
    return 0;
}
