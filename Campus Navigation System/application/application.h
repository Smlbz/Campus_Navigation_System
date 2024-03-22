#pragma once
#include<iostream>
#define App Application::getInstance()
class GLFWwindow;
using ResizeCallBack = void(*)(int width, int height);
using OnKeyCallBack = void(*)(int key, int scancode, int action, int mods);
using CursorPosCallBack = void(*)(double xpos, double ypos);
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
	void setKeyCallBack(OnKeyCallBack callback) {
		mKeyCallBack = callback;
	}
	void setCursorPos(CursorPosCallBack callback) {
		mCursorPos = callback;
	}
	bool update();
	void destroy();
private:
	static Application* mInstance;
	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	GLFWwindow* mWindow{ nullptr };
	ResizeCallBack mResizeCallBack{ nullptr };
	OnKeyCallBack mKeyCallBack{ nullptr };
	CursorPosCallBack mCursorPos{ nullptr };
	static void frameBufferSizeCallBack(GLFWwindow* window, int width, int height);
	static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursorPos(GLFWwindow* window, double xpos, double ypos);
	Application();
};