#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <string>

/*
  * ShaderLoader is a rather simple class just used to make loading of shader files less of a hassle.
  * Current functionality is to load shaders from files, to compile the shader, and to link the shaders into a program.
  * Any further use this class can provide is yet to be seen.
*/
class ShaderLoader{
public:
	GLuint CreateShader(GLenum shaderType, char *fileName);
	GLuint CreateProgram(char *vsFilename, char *fsFilename);
private:
	std::string LoadShader(char *fileName);
};

#endif