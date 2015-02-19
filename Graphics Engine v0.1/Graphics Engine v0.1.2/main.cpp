#define GLFW_DLL
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <stdio.h>
#include "AdditionalFunctions.h"
#include "ShaderLoader.h"

typedef enum{RED, GREEN, BLUE}Color;

Color currentColor = RED;

float red = 0, green = 0, blue = 0;

//Closes GLFWwindow upon press of ESC
static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_R){
		currentColor = RED;
		printf("%f\n", red);
	}
	else if (key == GLFW_KEY_G){
		currentColor = GREEN;
		printf("%f\n", green);
	}
	else if (key == GLFW_KEY_B){
		currentColor = BLUE;
		printf("%f\n", blue);
	}
	else if (key == GLFW_KEY_UP){
		if (currentColor == RED && red < 1){
			red += 0.01;
		}
		else if (currentColor == GREEN && green < 1){
			green += 0.01;
		}
		else if (currentColor == BLUE && blue < 1){
			blue += 0.01;
		}
	}
	else if (key == GLFW_KEY_DOWN){
		if (currentColor == RED && red > 0){
			red -= 0.01;
		}
		else if (currentColor == GREEN && green > 0){
			green -= 0.01;
		}
		else if (currentColor == BLUE && blue > 0){
			blue -= 0.01;
		}
	}
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

	ShaderLoader l;
	l.CreateShader(GL_VERTEX_SHADER, "C:\\Users\\Rexy712\\Desktop\\new.txt");

	//Main loop. Swaps GLFWwindow buffer and polls events.
	while (!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(red, green, blue, 1.0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	//Clean up GLFW.
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}