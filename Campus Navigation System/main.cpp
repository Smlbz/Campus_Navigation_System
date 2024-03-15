#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include"wrapper/checkError.h"
#include"application/Application.h"
void OnResize(int width, int height) {
	glCall(glViewport(0, 0, width, height));
}
/*static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	std::cout << "°´ÏÂÁË:" << key <<std:: endl << "scancode:"<<scancode << ' ' <<"action:" << action << ' ' <<"mods:" << mods << std::endl;
}*/
int main() {
	if (!App->init(600, 1000)) {
		return -1;
	}
	App->setResizeCallBack(OnResize);
	//glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	//glfwSetKeyCallback(window, keyCallBack);
	glCall(glViewport(0, 0, 600, 1000));
	glCall(glClearColor(0.8f, 0.2f, 0.1f, 0.15f));

	while (App->update()){
		glCall(glClear(GL_COLOR_BUFFER_BIT));
	}
	App->destroy();
	return 0;
}