#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include"wrapper/checkError.h"
#include"application/Application.h"
static void frameBufferSizeCallBack(GLFWwindow* window,int width,int height) {
	glCall(glViewport(0, 0, width, height));
}
static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	std::cout << "°´ÏÂÁË:" << key <<std:: endl << "scancode:"<<scancode << ' ' <<"action:" << action << ' ' <<"mods:" << mods << std::endl;
}



int main() {
	if (!App->init(800, 1200)) {
		return -1;
	}
	//glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	//glfwSetKeyCallback(window, keyCallBack);
	glCall(glViewport(0, 0, 800, 1200));
	glCall(glClearColor(0.8f, 0.2f, 0.1f, 0.15f));

	while (App->update()){
		glCall(glClear(GL_COLOR_BUFFER_BIT));
	}
	App->destroy();
	return 0;
}