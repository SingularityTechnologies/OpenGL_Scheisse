#define GLFW_DLL
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <stdio.h>
#include "AdditionalFunctions.h"

//Closes GLFWwindow upon press of ESC
static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(){

	//Initialize GLFW. Closes program upon failure.
	if (!glfwInit())
		return 1;

	//GLFWwindow creation. Closes program upon failure.
	GLFWwindow *window = glfwCreateWindow(640, 480, "Rexy712", NULL, NULL);
	if (!window){
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, KeyCallback);

	//Initialize GLEW
	glewExperimental = GL_TRUE;
	glewInit();
	
	//Print OpenGL version to the console.
	printf("OpenGL Version: %.1f", GetGLVersion());

	//Main loop. Swaps GLFWwindow buffer and polls events.
	while (!glfwWindowShouldClose(window)){
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//Clean up GLFW.
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}