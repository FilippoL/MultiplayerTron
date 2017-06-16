#pragma once
#include "Singleton.h"
#include <iostream>
#include <fstream>
#include <string>
#include <SDL.h>
#include <GLM.hpp>
#include <GLEW.h>

class ShaderManager
{
	friend class Singleton<ShaderManager>;
public:

	GLuint GetShaderID();
	bool CreateProgram();
	bool CreateShaders();
	bool CompileShaders(std::string f);
	bool AttachShaders();
	bool LinkProgram();
	void DetachDestroy();
	
	
	

private:
	const GLchar* finalCode;
	GLint compileResult;
	GLint linkResult;

	GLuint m_vertexShaderID;
	GLuint m_fragmentShaderID;
	GLuint m_shaderProgramID;

private:
	ShaderManager() {}
	ShaderManager(const ShaderManager&);
	ShaderManager& operator=(const ShaderManager&);
};

typedef Singleton<ShaderManager> Shade;