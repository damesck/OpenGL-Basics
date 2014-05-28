/*!
	Ayush Shrestha
	OpenGL Basics
	May 2014
*/ 

#include<iostream>
#include<GL/glut.h>
#include<GL/glu.h>

void display(){
	
	/// This basically clears the buffers - and since we havent specified what to reset it to
	/// by default clears to black ie 0.0, 0.0, 0.0, 0.0
	glClear(GL_COLOR_BUFFER_BIT);
	
	/// This sets the color of all the vertices
	glColor3f(1.0,0.0,0.0);

	/// By default when you dont specify anything, the screen coordinates range from 0.0 ... 1.0
	/// Any coordinates bigger than that will be clipped.
	glBegin(GL_TRIANGLES);
		glVertex3f(0,.5,0.0);
		glVertex3f(.5,-.5,0.0);
		glVertex3f(-.5,-.5,0.0);
	glEnd();

	/// This is for the static drawing. For dynamic ones, you need to use glSwapBuffers() instead.
	glFlush();
}

int main (int argc, char* argv[]){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(512,512);
	glutCreateWindow("Basic Colors");

	/// The parameter to the glutDisplayFunc() is the name of the function which is used to render.
	/// The name of the function happened to be 'display' in this case. But it can be anything that
	/// is permitted by C++. See the display function up ^
	glutDisplayFunc(display); 
	
	
	glutMainLoop();
	return 0;
}
