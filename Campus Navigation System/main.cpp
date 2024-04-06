#include<iostream>
#include"glFramework/core.h"
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string>
#include"wrapper/checkError.h"
#include"application/Application.h"
#include"glFramework/Shader.h"
static void OnResize(int width, int height) {
	glCall(glViewport(0, 0, width, height));
}
static void OnKey(int key, int scancode, int action, int mods) {
	;
}
static void OnCursor(double xpos, double ypos) {
	;
}
Shader* shader = nullptr;
GLuint vao;
void prepareVAO() {
	float positions[] = {
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f,
	};
	float colors[] = {
		1.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,
		0.0f,0.0f,1.0f
	};
	unsigned int indices[] = {
		0,1,2,
	};
	GLuint posVbo, colorVbo;
	glGenBuffers(1, &posVbo);
	glBindBuffer(GL_ARRAY_BUFFER, posVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

	glGenBuffers(1, &colorVbo);
	glBindBuffer(GL_ARRAY_BUFFER, colorVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

	GLuint ebo;
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, posVbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)* 3, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, colorVbo);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void*)0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBindVertexArray(0);
}
void prepareShader() {
	shader = new Shader("assets/Shaders/vertex.glsl", "assets/Shaders/fragment.glsl");
}
void render() {
	glCall(glClear(GL_COLOR_BUFFER_BIT));
	shader->begin();
	glCall(glBindVertexArray(vao));
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	shader->end();
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
	prepareVAO();
	prepareShader();
	while (App->update()){
		render();
	}
	App->destroy();
	return 0;
}