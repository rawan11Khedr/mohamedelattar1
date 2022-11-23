#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include<math.h>


const double PI = 3.14;

int frameNumber = 0; // for routation

void drawCircle(double radius) {
	int i;
	glBegin(GL_POLYGON);
	for (i = 0; i < 360; i++) {
		double angle = i*PI/180 ;
		glVertex2d( radius*cos(angle), radius*sin(angle));
	}

	glEnd();

}


// a sun


void drawSun() {
	int i;
	glColor3f(1,1,0);
	for (i = 0; i < 13; i++) { // Draw 13 lines
		glRotatef( 360 / 13, 0, 0, 1 );
		glBegin(GL_LINES);
		glVertex2f(0, 0);
		glVertex2f(0.75f, 0);
		glEnd();
	}
	drawCircle(0.5);

}

float step=0; //for animation


void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();



//draw cloud

    // cloud 1
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(1.7+step,3);
    glVertex2f(1+step,3.3);
    glVertex2f(0.3+step,3);
    glVertex2f(1+step,2.7);
    glEnd();

    //cloud 2

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(2.7+step,3.3);
    glVertex2f(2+step,3.6);
    glVertex2f(1.3+step,3.3);
    glVertex2f(2+step,3);
    glEnd();







//draw the mountain

    //mountain 1

	glColor3f(0.5f,0.35f,0.05f);
	glBegin(GL_POLYGON);
	glVertex2f(-3,-1);
	glVertex2f(1.5,1.65);
	glVertex2f(5,-1);
	glEnd();

	//mountain 2

	glBegin(GL_POLYGON);
	glVertex2f(-2,-1);
	glVertex2f(4,2.1);
	glVertex2f(8,-1);
	glEnd();

//draw tree

    //triangle
    glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(1,1);
	glVertex2f(0.5,0);
	glVertex2f(1.5,0);
	glEnd();

    //line
    glLineWidth(20);
	glColor3f(0.1f, 0.0f, 0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1,0);
	glVertex2f(1,-0.5);
	glEnd();


	//draw the road

	glColor3f(0.4f, 0.4f, 0.5f);
	glBegin(GL_POLYGON);
	glVertex2f(0,-0.99);
	glVertex2f(15,-0.99);
	glVertex2f(0,-0.2);
	glVertex2f(15,-0.2);
	glEnd();

    //line in road

	glLineWidth(6);
	glColor3f(1,1,1);
	glBegin(GL_LINES);
	glVertex2f(0,-0.6);
	glVertex2f(15,-0.6);
	glEnd();



//draw the Sun


	glPushMatrix();
	glTranslated(5.8,3,0);
	glRotated(-frameNumber*0.7,0,0,1);
	drawSun();
	glPopMatrix();
    glutSwapBuffers();

}  // end display

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}


void doFrame(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,doFrame,0);
}

    //init
    void init() {
        glClearColor(0.7, 0.9, 1.0, 0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 7, -1, 4, -1, 1);
        glMatrixMode(GL_MODELVIEW);
}



void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
	step+=0.01;


}



//main

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(200,0);
    glutCreateWindow("Rawan Reda Khedr & Mohamed Magdy Elattar 20102182/20102847");

    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutTimerFunc(0,doFrame,0);

    init();
    glutMainLoop();

    return 0;
}

