/*
	1.first find the xc,yc and r;
	
		xc = 0;
		yc = 0;
		r = 200;
	
	2. find decision parameter.
	
		decision parameter (d) = 3 - 2 * r;
	
	3. ploat pixel
	
		x = 0;
		y = r;
		while(x<y){
		
		}
		
	if(d<0){
	
		x++;
		d = d + 4 * x + 6;
	
	}
	else{
	
		x++;
		y--;
		d = d + 4 * (x - y) + 10;
	
	}


*/

#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

// Define the radius of the circle and the center point
int r ;//= 400;
int xc ;//= 0;
int yc ;//= 0;

// Initialize OpenGL 
void init(void) {

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    
}

void project(){

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);

}

// Draw the circle using Bresenham's algorithm
void drawCircle() {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y) {
        // Draw the points in all eight octants
        glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc - y, yc - x);
        glEnd();

        // If decision parameter is less than zero, move to next pixel horizontally
        if (d < 0) {
        	x++;
            d = d + 4 * x + 6;
        }
        // If decision parameter is greater than or equal to zero, move to next pixel diagonally
        else {
        	x++;
        	y--;
            d = d + 4 * (x - y) + 10;
        }
    }
}

// Display the circle
void display(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_LINES);
    glColor3f(1.0,1.0,1.0);
    glVertex2i(-500,0);
    glVertex2i(500,0);
    glVertex2i(0,-500);
    glVertex2i(0,500);
    glEnd();
    glFlush();
    
    drawCircle();
    glFlush();
}

int main(int argc, char** argv) {

	cout<<"Enter xc , yc : ";
	cin>>xc>>yc;
	
	cout<<endl;
	
	cout<<"Enter r : ";
	cin>>r;

    glutInit(&argc, argv);
    init();
    glutCreateWindow("Bresenham Circle Drawing Algorithm");
    project();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

/*
Now, let's take a closer look at the drawCircle() function which implements the Bresenham's Circle Drawing Algorithm.

1.We initialize the starting point of the circle at (0,r), and the decision parameter d at 3 - 2 * r.
2.We use a while loop to iterate through all the points on the circle's circumference, from x=0 to y=r.
3.We draw the eight points in each octant of the circle using the glBegin() and glVertex2i() functions. Note that we use the glVertex2i() function to draw integer coordinates instead of float coordinates.
4.We calculate the decision parameter d at each point, based on the current position and the radius of the circle.
5,If d is less than zero, we move to the next pixel horizontally by incrementing x.
6.If d is greater than or equal to zero, we move to the next pixel diagonally by decrementing y and incrementing x.
7.We continue this process until we have drawn
*/