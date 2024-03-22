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
void prepare() {
	double pos[] = {
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f
	};
	double color[] = {
		1.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,
		0.0f,0.0f,1.0f
	};
	GLuint posvbo = 0;
	GLuint colorvbo = 0;

	glCall(glGenBuffers(1, &posvbo));
	glBindBuffer(GL_ARRAY_BUFFER, posvbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pos), pos, GL_STATIC_DRAW);

	glCall(glGenBuffers(1, &colorvbo));
	glBindBuffer(GL_ARRAY_BUFFER, colorvbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color), color, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, posvbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double),(void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, colorvbo);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);

	glBindVertexArray(0);
	glCall(glDeleteBuffers(1, &posvbo));
	glCall(glDeleteBuffers(1, &colorvbo));

	GLuint vboarr[] = {0,0,0};

	glCall(glGenBuffers(3, vboarr));

	glCall(glDeleteBuffers(3, vboarr));
}
int main() {
	if (!App->init(600, 1000)) {
		return -1;
	}
	App->setResizeCallBack(OnResize);
	App->setKeyCallBack(OnKey);
	App->setCursorPos(OnCursor);
	glCall(glViewport(0, 0, 600, 1000));
	glCall(glClearColor(0.8f, 0.2f, 0.1f, 0.15f));
	prepare();
	while (App->update()){
		glCall(glClear(GL_COLOR_BUFFER_BIT));
	}
	App->destroy();
	return 0;
}