/*!
	Ayush Shrestha
	OpenGL Basics
	May 2014
*/ 

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

float angle =0.0;

void drawCube(float size){
	glBegin(GL_QUADS); // Deprecated in OpenGL 4.0
		//front face (red)
		glColor3f(1.0,0.0,0.0);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);
	
		//left face (green)
		glColor3f(0.0,1.0,0.0);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(-size/2,-size/2,size/2);
		
		//back face (yellow)
		glColor3f(1.0,1.0,0.0); 
		glVertex3f(size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(size/2,-size/2,-size/2);

		//right face (cyan)
		glColor3f(0.0,1.0,1.0);
		glVertex3f(size/2,size/2,-size/2);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,-size/2);
		
		//top face (blue)
		glColor3f(0.0,0.0,1.0);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(size/2,size/2,-size/2);		
		
		//bottom face (pink)
		glColor3f(1.0,0.0,1.0);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(size/2,-size/2,-size/2);
		
	glEnd();
}

void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640.0/480.0,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	//glEnable(GL_DEPTH_TEST);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0,1.0,1.0,1.0);
	glLoadIdentity();
	
	glTranslatef(0.0,0.0,-10.0);
	glRotatef(angle,1.0,1.0,0.0);

	//glutSolidCube(2.0);
	drawCube(2.0);
	
	glutSwapBuffers();
	angle+=1.0;
	if(angle>360) angle-=360;
}

int main (int argc, char* argv[]){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(640,480);
	glutCreateWindow("Basic Colors");

	init();
	
	glutDisplayFunc(display);
	glutIdleFunc(display);
	
	glutMainLoop();
	return 0;
}
