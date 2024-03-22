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
GLuint vao = 0,program=0;
void prepare() {
	double pos[] = {
		-0.5f,-0.5f,0.0f,
		0.5f,-0.5f,0.0f,
		0.0f,0.5f,0.0f,
		0.2f,0.3f,0.7f,
		0.1f,0.1f,0.5f,
		0.0f,-0.3,-0.5
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

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, posvbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double),(void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, colorvbo);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_DOUBLE, GL_FALSE, 3 * sizeof(double), (void*)0);

	glBindVertexArray(0);
	glCall(glDeleteBuffers(1, &posvbo));
	glCall(glDeleteBuffers(1, &colorvbo));
}
void preShader(){
	const char* vertexShaderSource = 
		"#version 460 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);\n"
		"}\0";
	const char* fragmentShaderSource = 
		"#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(0.37f,0.28f,0.61f,0.8f);\n"
		"}\n\0";
	GLuint vertex,fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertex,1,&vertexShaderSource,NULL);
	glShaderSource(fragment,1,&fragmentShaderSource,NULL);
	int success = 0;
	char infoLog[1024];
	glCompileShader(vertex);
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (success == 0) {
		glGetShaderInfoLog(vertex, 1024, NULL, infoLog);
		std::cout << "Error:SHADER COMPILE ERROR--VERTEX\n" << infoLog << std::endl;
	}
	glCompileShader(fragment);
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (success == 0) {
		glGetShaderInfoLog(fragment, 1024, NULL, infoLog);
		std::cout << "Error:SHADER COMPILE ERROR--FRAGMENT\n" << infoLog << std::endl;
	}
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	glGetProgramiv(program,GL_LINK_STATUS,&success);
	if (success == 0) {
		glGetProgramInfoLog(program, 1024, NULL, infoLog);
		std::cout << "Error:PROGRAM LINK ERROR\n" << infoLog << std::endl;
	}
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
void render() {
	glUseProgram(program);
	glBindVertexArray(vao);
	glDrawArrays(GL_LINE_LOOP, 0, 6);
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
	preShader();
	while (App->update()){
		glCall(glClear(GL_COLOR_BUFFER_BIT));
		render();
	}
	App->destroy();
	return 0;
}