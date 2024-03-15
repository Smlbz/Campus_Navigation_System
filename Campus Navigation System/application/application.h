#pragma once
#include<iostream>
#define App Application::getInstance()
class GLFWwindow;
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
	bool update();
	void destroy();
private:
	static Application* mInstance;
	uint32_t mWidth{ 0 };
	uint32_t mHeight{ 0 };
	GLFWwindow* mWindow{ nullptr };
	Application();
};