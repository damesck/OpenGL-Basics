/*!
	Ayush Shrestha
	OpenGL Basics
	May 2014
*/ 

#include <iostream>
#include <GL/glut.h>

using namespace std;

float _x, _y;
int _width, _height;
bool _followMouse;

void init(){
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640.0/480.0,1.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	
	_x =_y = 0.0;
	_followMouse = false;
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f((float)_x,(float)_y+1.0, -10.0);
		glVertex3f((float)_x+1.0f,(float)_y, -10.0);
		glVertex3f((float)_x-1.0f,(float)_y, -10.0);
	glEnd();

	glutSwapBuffers();
	//glFlush();
}

void reshape(int width, int height){
	_width = width;
	_height = height;
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
	if(state==GLUT_DOWN){
		if(button == GLUT_LEFT_BUTTON){
			_followMouse = true;
		}
		else{
			_followMouse = false;
		}
	}
}

void mouseMove(int x, int y){
	if(_followMouse){
		_x = (float)(x*4)/glutGet(GLUT_SCREEN_WIDTH);
		//_x *= _width;
		_y = -(float)(y*3)/glutGet(GLUT_SCREEN_WIDTH);
		//_y *= _height;
		cout<<_x<<","<<_y<<endl;
	}
	glutPostRedisplay();
}



int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50,200);
	
	_width = 800;
	_height = 600;
	glutInitWindowSize(_width,_height);

	glutCreateWindow("Mouse");
	init();

	glutDisplayFunc(display);
	glutIdleFunc(display);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMove);

	glutMainLoop();
	return 0;
}
