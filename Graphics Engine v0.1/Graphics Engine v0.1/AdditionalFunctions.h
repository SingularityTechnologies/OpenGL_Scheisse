#ifndef ADDITIONAL_FUNCTIONS_H
#define ADDITIONAL_FUNCTIONS_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>

//Returns OpenGL version in the form of a float.
float GetGLVersion(){
	GLint versionMajor, versionMinor;
	glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
	glGetIntegerv(GL_MINOR_VERSION, &versionMinor);
	return versionMajor + (float)versionMinor / 10;
}

#endif