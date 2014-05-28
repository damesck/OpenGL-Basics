/*!
	Ayush Shrestha
	OpenGL Basics
	May 2014
*/ 

/// I borrowed some of this code from the cplusplusguy youtube channel

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

float angle =0.0;



void drawCube(float size){
	glBegin(GL_TRIANGLE_STRIP); // Deprecated in OpenGL 4.0
		//front face (red)
		//glNormal3f(0.0,0.0,1.0);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(size/2,size/2,size/2);
	
		//left face (green)
		//glNormal3f(-1.0,0.0,0.0);
		glColor3f(0.0,1.0,0.0);
		glVertex3f(size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,-size/2);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(size/2,size/2,-size/2);
		
		//back face (yellow)
		//glNormal3f(0.0,0.0,-1.0);
		glColor3f(1.0,1.0,0.0); 
		glVertex3f(size/2,-size/2,-size/2);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,-size/2);

		//right face (cyan)
		//glNormal3f(1.0,0.0,0.0);
		glColor3f(0.0,1.0,1.0);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(-size/2,size/2,size/2);
		
		//top face (blue)
		//glNormal3f(0.0,1.0,0.0);
		glColor3f(0.0,0.0,1.0);
		glVertex3f(-size/2,-size/2,-size/2);
		glVertex3f(size/2,-size/2,-size/2);
		glVertex3f(-size/2,-size/2,size/2);
		glVertex3f(size/2,-size/2,size/2);	
		
		//bottom face (pink)
		//glNormal3f(0.0,-1.0,0.0);
		glColor3f(1.0,0.0,1.0);
		glVertex3f(-size/2,size/2,size/2);
		glVertex3f(size/2,size/2,size/2);
		glVertex3f(-size/2,size/2,-size/2);
		glVertex3f(size/2,size/2,-size/2);
		
	glEnd();
}

void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640.0/480.0,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	
	glShadeModel(GL_FLAT);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	
	glEnable(GL_COLOR_MATERIAL);
	
	glEnable(GL_LIGHT0);
	
	float dif[] = {1.0,1.0,1.0,1.0};
	glLightfv(GL_LIGHT0,GL_DIFFUSE,dif);
	
	float amb[] = {0.2,0.2,0.2,1.0};
	glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
	
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	float pos[] = {-2.0,-2.0,-3.0,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	
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

	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(640,480);
	glutCreateWindow("Basic Colors");

	init();
	
	glutDisplayFunc(display);
	glutIdleFunc(display);
	
	glutMainLoop();
	return 0;
}
