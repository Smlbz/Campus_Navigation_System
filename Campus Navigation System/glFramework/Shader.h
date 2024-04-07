#pragma once
#include "core.h"
#include<string>
class Shader {
public:
	Shader(const char* vertexPath,const char* fragmentPath);
	~Shader();
	void begin();//use this Shader
	void end();//no use this Shader
private:
	void checkShaderErrors(GLuint target, std::string type); 
private:
	GLuint mProgram{ 0 };
};