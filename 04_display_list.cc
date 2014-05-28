/*!
	Ayush Shrestha
	OpenGL Basics
	May 2014
*/ 

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

const int triangle=1;

void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640.0/480.0,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	
	glNewList(triangle, GL_COMPILE);
		glBegin(GL_TRIANGLES);
			glColor3f(1.0,0.0,0.0);
			glVertex3f(0,2,-10.0);
			glColor3f(0.0,1.0,0.0);
			glVertex3f(2,-2,-10.0);
			glColor3f(0.0,0.0,1.0);
			glVertex3f(-2,-2,-10.0);
		glEnd();
	glEndList();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glCallList(triangle);
	glFlush();
}

int main (int argc, char* argv[]){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(640,480);
	glutCreateWindow("Display List");

	init();

	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}
