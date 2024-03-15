#pragma once
#include<iostream>
#define App Application::getInstance()
class GLFWwindow;
using ResizeCallBack = void(*)(int width, int height);
class Application {
public:
	~Application();
	static Application* getInstance();
	uint32_t getWidth()const {
		return mWidth;
	}
	uint32_t getHeight()const {
		return mHeight;
	}
	bool init(const int& width = 800, const int& height = 1200);
	void setResizeCallBack(ResizeCallBack callback) {
		mResizeCallBack = callback;
	}
	bool update();
	void destroy();
private:
	static Application* mInstance;
	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	GLFWwindow* mWindow{ nullptr };
	ResizeCallBack mResizeCallBack{ nullptr };
	static void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);
	Application();
};