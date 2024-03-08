#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include"wrapper/checkError.h"
using namespace std;

static void frameBufferSizeCallBack(GLFWwindow* window,int width,int height) {
	glViewport(0, 0, width, height);
}
static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
	cout << "°´ÏÂÁË:" << key << endl << "scancode:"<<scancode << ' ' <<"action:" << action << ' ' <<"mods:" << mods << endl;
}



int main() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(800, 1200, "QDU_Campus_Navigation", NULL, NULL);
	glfwMakeContextCurrent(window);


	glfwSetFramebufferSizeCallback(window, frameBufferSizeCallBack);
	glfwSetKeyCallback(window, keyCallBack);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
		cout << "Failed to initialize GLAD";
		return -1;
	}
	glViewport(0, 0, 800, 1200);
	glClearColor(0.6f, 0.5f, 0.4f, 0.12f);

	while (!glfwWindowShouldClose(window)) {

		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
		checkError();

		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}