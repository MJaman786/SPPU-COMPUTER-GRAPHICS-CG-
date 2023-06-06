#include <GL/glut.h>
#include<math.h>
#include <iostream>

int tx,ty,sx,sy,k=0,h=0,angle,option;

using namespace std;

float triangle[3][3] = {{100,200,300},{100,300,100},{1,1,1}};

float h_matrix[3][3] = {{0},{0},{0}};
float r_matrix[3][3] = {{0},{0},{0}};

void multiply(){

	for(int i=0; i<3; i++){
	
		for(int j=0; j<6; j++){
		
			r_matrix[i][j] = 0;
			
			for(int k=0; k<3; k++){
			
				r_matrix[i][j] += h_matrix[i][k] * triangle[k][j];
			
			}
		
		}
	
	}

}

void translate(){

	h_matrix[0][0] = 1;
	h_matrix[0][1] = 0;
	h_matrix[0][2] = tx;
	h_matrix[1][0] = 0;
	h_matrix[1][1] = 1;
	h_matrix[1][2] = ty;
	h_matrix[2][0] = 0;
	h_matrix[2][1] = 0;
	h_matrix[2][2] = 1;
	multiply();

}

void scale(){

	h_matrix[0][0] = sx;
	h_matrix[0][1] = 0;
	h_matrix[0][2] = 0;
	h_matrix[1][0] = 0;
	h_matrix[1][1] = sy;
	h_matrix[1][2] = 0;
	h_matrix[2][0] = 0;
	h_matrix[2][1] = 0;
	h_matrix[2][2] = 1;
	multiply();

}

void reflectionO(){

	h_matrix[0][0] = -1;
	h_matrix[0][1] = 0;
	h_matrix[0][2] = 0;
	h_matrix[1][0] = 0;
	h_matrix[1][1] = -1;
	h_matrix[1][2] = 0;
	h_matrix[2][0] = 0;
	h_matrix[2][1] = 0;
	h_matrix[2][2] = 1;
	multiply();

}

void reflectionX(){

	h_matrix[0][0] = 1;
	h_matrix[0][1] = 0;
	h_matrix[0][2] = 0;
	h_matrix[1][0] = 0;
	h_matrix[1][1] = -1;
	h_matrix[1][2] = 0;
	h_matrix[2][0] = 0;
	h_matrix[2][1] = 0;
	h_matrix[2][2] = 1;
	multiply();

}

void reflectionY(){

	h_matrix[0][0] = -1;
	h_matrix[0][1] = 0;
	h_matrix[0][2] = 0;
	h_matrix[1][0] = 0;
	h_matrix[1][1] = 1;
	h_matrix[1][2] = 0;
	h_matrix[2][0] = 0;
	h_matrix[2][1] = 0;
	h_matrix[2][2] = 1;
	multiply();

}

void rotate(){

	int m = - h * (cos (angle) -1) + k * (sin (angle) );
	int n = - k * (cos (angle) -1) - h * (sin (angle) );
	
	h_matrix[0][0] = cos(angle);
	h_matrix[0][1] = -sin(angle);
	h_matrix[0][2] = m;
	h_matrix[1][0] = sin(angle);
	h_matrix[1][1] = cos(angle);
	h_matrix[1][2] = n;
	h_matrix[2][0] = 0;
	h_matrix[2][1] = 0;
	h_matrix[2][2] = 1;
	multiply();

}

void draw_triangle(){
	
	glPointSize(3);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(triangle[0][0],triangle[1][0]);
	glVertex2f(triangle[0][1],triangle[1][1]);
	glVertex2f(triangle[0][2],triangle[1][2]);
	glEnd();
	glFlush();
	
}

void transform_triangle(){
	
	glPointSize(3);
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(r_matrix[0][0],r_matrix[1][0]);
	glVertex2f(r_matrix[0][1],r_matrix[1][1]);
	glVertex2f(r_matrix[0][2],r_matrix[1][2]);
	glEnd();
	glFlush();	

}

void lines(int x1,int y1,int x2,int y2){

	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glEnd();
	glFlush();

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
    gluOrtho2D(-500,500,-500,500);
}

void display(){

    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    lines(-500,0,500,0);
    lines(0,-500,0,500);
    
    draw_triangle();
    
    switch(option){
    
    	case 1:
    		translate();
    	break;
    	
    	case 2:
    		scale();
    	break;
    	
    	case 3:
    		reflectionO();
    	break;
    	
    	case 4:
    		reflectionX();
    	break;
    	
    	case 5:
    		reflectionY();
    	break;
    	
    	case 6:
    		rotate();
    	break;
    
    }
    transform_triangle();
    
    glFlush();

}

int main(int argc, char** argv)
{
	
	cout<<"1.Translation \n";
	cout<<"2.Scale       \n";
	cout<<"3.Reflection-o\n";
	cout<<"4.Reflection-x\n";
	cout<<"5.Reflection-y\n";
	cout<<"6.Rotation	 \n";
	
	cout<<"Enter option = ";
	cin>>option;
	
	switch(option){
	
		case 1:
			cout<<"Enter tx = ";
			cin>>tx;
			cout<<"Enter ty = ";
			cin>>ty;
		break;
		
		case 2:
			cout<<"Enter sx = ";
			cin>>sx;
			cout<<"Enter sy = ";
			cin>>sy;
		break;
		
		case 6:
			cout<<"Enter angle = ";
			cin>>angle;
		break;
	
	}
	
	
    glutInit(&argc, argv);
    init();
    glutCreateWindow("2D-Transformation");
    glutDisplayFunc(display);
    project();
    glutMainLoop();
    return 0;
}