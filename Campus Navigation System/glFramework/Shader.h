#pragma once
#include "core.h"

class Shader {
public:
	Shader(const char* vertexPath,const char* fragmentPath);
	~Shader();
	void begin();//use this Shader
	void end();//no use this Shader
private:
	GLuint mProgram{ 0 };
};