#ifndef ADDITIONAL_FUNCTIONS_H
#define ADDITIONAL_FUNCTIONS_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>

/*
  * Function to simplify the process of obtaining the OpenGL version number (not that it was
  * particularly difficult to get the version number to start). The version number is returned as
  * a float, a much more intuitive method of handling a version number.
  * @returns = Version number of current OpenGL environment as a float.
*/
float GetGLVersion(){
	GLint versionMajor, versionMinor;
	glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
	glGetIntegerv(GL_MINOR_VERSION, &versionMinor);
	return versionMajor + (float)versionMinor / 10;
}

#endif