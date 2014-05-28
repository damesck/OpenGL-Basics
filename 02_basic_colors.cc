/*!
	Ayush Shrestha
	OpenGL Basics
	May 2014
*/ 

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>


/// This function clears the buffers and initializes the underlying matrices
void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640.0/480.0,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
}


/// This function is used for rendering. Note that when all three vertices
/// have different colors, the pixels between then have have interpolated 
/// colors.
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0,2,-10.0);
		glColor3f(0.0,1.0,0.0);
		glVertex3f(2,-2,-10.0);
		glColor3f(0.0,0.0,1.0);
		glVertex3f(-2,-2,-10.0);
	glEnd();
	glFlush();
}

int main (int argc, char* argv[]){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(640,480);
	glutCreateWindow("Basic Colors");

	init();

	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}
