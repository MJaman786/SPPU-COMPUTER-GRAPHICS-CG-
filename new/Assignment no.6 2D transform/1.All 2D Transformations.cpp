#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float triangle[3][3] = {{100 , 200 , 300} , {100 , 300 , 100} , {1 , 1 , 1}};

float t_matrix[3][3] = {{0} , {0} , {0}}; //homogenous matrix
float result[3][3] = {{0} , {0} , {0}};	  //resultant matrix 
float theta;

int tx , ty , sx , sy , h = 0 , k = 0 , option;

void multiply()
{
    int i , j , l;

    for(i = 0; i < 3; i++)  //outer loop is for number of vertices
    {
        for(j = 0; j < 6; j++) //mid inner loop is for result matrix
        {
            result[i][j] = 0;

            for(l = 0; l < 3; l++)//inner loop is for multiplying matrix
            {
                result[i][j] += t_matrix[i][l] * triangle[l][j];
            }
        }
    }
}
void translate()
{
    t_matrix[0][0] = 1;
    t_matrix[0][1] = 0;
    t_matrix[0][2] = tx;
    t_matrix[1][0] = 0;
    t_matrix[1][1] = 1;
    t_matrix[1][2] = ty;
    t_matrix[2][0] = 0;
    t_matrix[2][1] = 0;
    t_matrix[2][2] = 1;
    multiply();
}

void scale()
{
    t_matrix[0][0] = sx;
    t_matrix[0][1] = 0;
    t_matrix[0][2] = 0;
    t_matrix[1][0] = 0;
    t_matrix[1][1] = sy;
    t_matrix[1][2] = 0;
    t_matrix[2][0] = 0;
    t_matrix[2][1] = 0;
    t_matrix[2][2] = 1;
    multiply();
}

void reflectionO()
{
    t_matrix[0][0] = -1;
    t_matrix[0][1] = 0;
    t_matrix[0][2] = 0;
    t_matrix[1][0] = 0;
    t_matrix[1][1] = -1;
    t_matrix[1][2] = 0;
    t_matrix[2][0] = 0;
    t_matrix[2][1] = 0;
    t_matrix[2][2] = 1;
    multiply();
}

void reflectionX()
{
    t_matrix[0][0] = -1;
    t_matrix[0][1] = 0;
    t_matrix[0][2] = 0;
    t_matrix[1][0] = 0;
    t_matrix[1][1] = 1;
    t_matrix[1][2] = 0;
    t_matrix[2][0] = 0;
    t_matrix[2][1] = 0;
    t_matrix[2][2] = 1;
    multiply();
}

void reflectionY()
{
    t_matrix[0][0] = 1;
    t_matrix[0][1] = 0;
    t_matrix[0][2] = 0;
    t_matrix[1][0] = 0;
    t_matrix[1][1] = -1;
    t_matrix[1][2] = 0;
    t_matrix[2][0] = 0;
    t_matrix[2][1] = 0;
    t_matrix[2][2] = 1;
    multiply();
}

void rotate()
{
    float m , n;

    m = -h * (cos(theta)-1) + k * (sin(theta));
    n = -k * (cos(theta)-1) - h * (sin(theta));

    t_matrix[0][0] = cos(theta);
    t_matrix[0][1] = -sin(theta);
    t_matrix[0][2] = m;
    t_matrix[1][0] = sin(theta);
    t_matrix[1][1] = cos(theta);
    t_matrix[1][2] = n;
    t_matrix[2][0] = 0;
    t_matrix[2][1] = 0;
    t_matrix[2][2] = 1;
    multiply();
}

void drawTriangle()
{
    glColor3f(1.0 , 1.0 , 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(triangle[0][0] , triangle[1][0]);
        glVertex2f(triangle[0][1] , triangle[1][1]);
        glVertex2f(triangle[0][2] , triangle[1][2]);
        glEnd();
        glFlush();
}

void drawTransformedTriangle()
{
    glColor3f(1.0 , 0.0 , 1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(result[0][0] , result[1][0]);
        glVertex2f(result[0][1] , result[1][1]);
        glVertex2f(result[0][2] , result[1][2]);
        glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0 , 1.0 , 1.0);
    glBegin(GL_LINES);
        glVertex2i(-650 , 0);
        glVertex2i(650 , 0);
        glVertex2i(0 , -650);
        glVertex2i(0 , 650);
        glEnd();

    drawTriangle();

    switch(option)
    {
        case 1 :
                translate();
                break;
        case 2 :
        		scale();
        		break;
        		
        case 3 :
        		rotate();
                break;
        case 4 :
        		reflectionX();
        		break;
        case 5 :
        		reflectionY();
        		break;
        case 6 :
                reflectionO();
                break;
    }

    drawTransformedTriangle();
    glFlush();
}

void init(){

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500 , 500);
    glutInitWindowPosition(0 , 0);

}

void project()
{
    glClearColor(0.0 , 0.0 , 0.0 , 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-650 , 650 , -650 , 650);
}

int main(int argc , char** argv)
{
    printf("1.Translation. 	\n");
    printf("2.Scale.		\n");
    printf("3.Rotate.		\n");
    printf("4.ReflectionX.	\n");
    printf("5.ReflectionY.	\n");
    printf("6.ReflectionO.	\n");
    printf("Enter your choice : ");
    scanf("%d" , &option);

    switch(option)
    {
        case 1 :
                printf("Enter tx : ");
                scanf("%d" , &tx);
                printf("Enter ty : ");
                scanf("%d" , &ty);
                break;
        case 2 :
        		printf("Enter sx : ");
                scanf("%d" , &sx);
                printf("Enter sy : ");
                scanf("%d" , &sy);
                break;
                
        case 3 :
                printf("Enter the angle of Rotation : ");
                scanf("%f" , &theta);
                break;
    }

    glutInit(&argc , argv);
    init();
    glutCreateWindow("2D Transformations");
    project();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
