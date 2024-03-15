#include "Application.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
Application* Application::mInstance = nullptr;
Application* Application::getInstance() {
	if (mInstance == nullptr) {
		mInstance = new Application();
	}
	return mInstance;
}
Application::Application() {

}
Application::~Application() {

}
bool Application::init(const int& width,const int& height){
	mWidth = width;
	mHeight = height;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	mWindow = glfwCreateWindow(mWidth, mHeight, "QDU_Campus_Navigation", NULL, NULL);
	if (mWindow == NULL) {
		return false;
	}
	glfwMakeContextCurrent(mWindow);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD";
		return false;
	}
	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallBack);
	return true;
}
bool Application::update() {
	if (glfwWindowShouldClose(mWindow)) {
		return false;
	}
	glfwPollEvents();
	glfwSwapBuffers(mWindow);
	return true;
}
void Application::destroy() {
	glfwTerminate();
}
void Application::frameBufferSizeCallBack(GLFWwindow* window, int width, int height) {
	if (Application::getInstance()->mResizeCallBack != nullptr) {
		Application::getInstance()->mResizeCallBack(width, height);
	}
}