/*!
	Ayush Shrestha
	OpenGL Basics
	May 2014
*/ 

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

void init(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640.0/480.0,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);


	//glTranslatef(0.0,0.0,-0.05);
	//glRotatef(0.5,0.0,0.0,1.0);
	glPushMatrix();
	glLoadIdentity();
	glScalef(1.5,1.5,1.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0,2,-10.0);
		glVertex3f(2,-2,-10.0);
		glVertex3f(-2,-2,-10.0);	
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glLoadIdentity();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0,2,-10.0);
		glVertex3f(2,-2,-10.0);
		glVertex3f(-2,-2,-10.0);	
	glEnd();
	glPopMatrix();


	glutSwapBuffers();
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE);

	glutInitWindowSize(640.0,480.0);
	glutInitWindowPosition(200.0,200.0);
	glutCreateWindow("Transformations");

	init();
	
	glutDisplayFunc(display);
	glutIdleFunc(display);
	
	glutMainLoop();
	return 0;
}
