#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include"wrapper/checkError.h"
#include"application/Application.h"
static void OnResize(int width, int height) {
	glCall(glViewport(0, 0, width, height));
}
static void OnKey(int key, int scancode, int action, int mods) {
	;
}
static void OnCursor(double xpos, double ypos) {
	;
}
GLuint vao, program;
int main() {
	if (!App->init(600, 1000)) {
		return -1;
	}
	App->setResizeCallBack(OnResize);
	App->setKeyCallBack(OnKey);
	App->setCursorPos(OnCursor);
	glCall(glViewport(0, 0, 600, 1000));
	glCall(glClearColor(0.8f, 0.2f, 0.1f, 0.15f));
	while (App->update()){
		glCall(glClear(GL_COLOR_BUFFER_BIT));
	}
	App->destroy();
	return 0;
}