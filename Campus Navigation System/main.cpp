#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
using namespace std;


static void frameBufferSizeCallBack(GLFWwindow* window,int width,int height) {
	cout << "size:" << width <<"  "<< height<<endl;
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

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}