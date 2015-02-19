#include "ShaderLoader.h"

/*
  * Creates a new OpenGL shader of specified type from specified source.
  * @param shaderType = Glenum representing type of OpenGL shader to create.
  * @param *shaderSource = Path to the shader source file.
  * @returns = GLuint assigned to the newly created shader.
*/
GLuint ShaderLoader::CreateShader(GLenum shaderType, char *shaderSource){
	std::string shaderContents = LoadShader(shaderSource);
	GLuint shader = 1;// = glCreateShader(shaderType);

	const char* shaderContentsArray = shaderContents.c_str();
	const int shaderLength = shaderContents.length();

	//glShaderSource(shader, 1, &shaderContentsArray, &shaderLength);
	//glCompileShader(shader);
	
	return shader;
}

/*
  * Creates an OpenGL shader program consisting of a vertex shader and a fragment shader.
  * @param *vsFilename = Path to vertex shader source file.
  * @param *fsFilename = Path to fragment shader source file.
  * @returns GLuint assigned to the newly created shader program.
*/
GLuint ShaderLoader::CreateProgram(char *vsFilename, char *fsFilename){
	GLuint vShader = CreateShader(GL_VERTEX_SHADER, vsFilename);
	GLuint fShader = CreateShader(GL_FRAGMENT_SHADER, fsFilename);

	GLuint program = glCreateProgram();
	glAttachShader(program, vShader);
	glAttachShader(program, fShader);
	glLinkProgram(program);

	return program;
}

/*
  * Private member function which actually loads the contents of a shader source file into active memory.
  * @param *shaderSource = Path to the shader source file.
  * @returns = std::string object containing the contents of the shader file.
*/
std::string ShaderLoader::LoadShader(char* shaderSource){
	FILE* file = fopen(shaderSource, "r");
	std::string fileContents = "";
	char input[50];
	while (fgets(input, NULL, file)){
		fileContents += input;
	}
	printf("\n%s", fileContents.c_str());
	fclose(file);
	return fileContents;
}