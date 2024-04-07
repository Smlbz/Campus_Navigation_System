#include "Shader.h"
#include "Shader.h"
#include"../wrapper/checkError.h"
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
Shader::Shader(const char* vertexPath, const char* fragmentPath){
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		std::stringstream fShaderStream;
		fShaderStream << fShaderFile.rdbuf();
		vShaderFile.close();
		fShaderFile.close();
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure& error) {
		std::cout << "ERROR:Shader File Error: " << error.what() << std::endl;
	}
	const char* vertexShaderSource = vertexCode.c_str();
	const char* fragmentShaderSource = fragmentCode.c_str();
	GLuint vertex, fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertex, 1, &vertexShaderSource, NULL);
	glShaderSource(fragment, 1, &fragmentShaderSource, NULL);
	glCompileShader(vertex);
	checkShaderErrors(vertex, "COMPILE");
	glCompileShader(fragment);
	checkShaderErrors(fragment, "COMPILE");
	mProgram = glCreateProgram();
	glAttachShader(mProgram, vertex);
	glAttachShader(mProgram, fragment);
	glLinkProgram(mProgram);
	checkShaderErrors(mProgram, "LINK");
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

Shader::~Shader(){

}

void Shader::begin(){
	glCall(glUseProgram(mProgram));
}

void Shader::end(){
	glCall(glUseProgram(0));
}

void Shader::checkShaderErrors(GLuint target, std::string type){
	int success = 0;
	char infoLog[1024];
	if (type == "COMPILE") {
		glGetShaderiv(target, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(target, 1024, NULL, infoLog);
			std::cout << "ERROR:SHADER COMPILE ERROR" << std::endl << infoLog << std::endl;
		}
	}
	else if (type == "LINK") {
		glGetProgramiv(target, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(target, 1024, NULL, infoLog);
			std::cout << "ERROR:SHADER LINK ERROR" << std::endl << infoLog << std::endl;
		}
	}
	else {
		std::cout << "Error:Check shader errors Type is wrong!"<<std::endl;
	}
}
