#include "ShaderManager.h"
#include "DebugManager.h"


GLuint ShaderManager::GetShaderID()
{
	return m_shaderProgramID;
}

bool ShaderManager::CreateProgram()
{
	m_shaderProgramID = glCreateProgram();

	if (m_shaderProgramID == 0) 
	{     
		return false;
	}

	return true;
}

bool ShaderManager::CreateShaders()
{
	m_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	
	if (m_vertexShaderID == 0) 
	{
		return false;
	}

	m_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	if (m_fragmentShaderID == 0)
	{
		return false;
	}

	return true;
}

bool ShaderManager::CompileShaders(std::string filename)
{
	std::fstream file;
	std::string lineText = ""; 
	std::string finalString = "";

	file.open(filename);

	if (!file) {return false;} 


	while (!file.eof()) 
	{ 
		getline(file, lineText);     
		finalString += lineText + "\n"; 
	}

	file.close();

	//CONVERTING FROM STRING TO GLCHAR ARRAY
	const GLchar* finalcode = static_cast<const GLchar*>(finalString.c_str());

	GLuint ShaderID;

	if (filename.substr(filename.length() - 5) == ".vert")//TO BE IMPLEMENTED WITH OTHER FILE FORMAT
	{
		ShaderID = m_vertexShaderID;

	}

	else if (filename.substr(filename.length() - 5) == ".frag")

	{
		ShaderID = m_fragmentShaderID;
		
	}


	else { std::cout << "Your shader file format not supported by shadercompiler!" << std::endl; return false; }


	glShaderSource(ShaderID, 1, &finalcode, NULL);

	glCompileShader(ShaderID);

	GLint compileResult;

	glGetShaderiv(ShaderID, GL_COMPILE_STATUS, &compileResult);

	if (compileResult == GL_FALSE)
	{
		GLchar error[1000];
		GLsizei length = 1000;

		glGetShaderInfoLog(ShaderID, 1000, &length, error);
		std::cout << error << std::endl;
		return false;
	}

	return true;
}

bool ShaderManager::AttachShaders()
{
	glAttachShader(m_shaderProgramID, m_vertexShaderID); 
	glAttachShader(m_shaderProgramID, m_fragmentShaderID);

	if (m_vertexShaderID == GL_FALSE || m_fragmentShaderID == GL_FALSE) 
	{
		return false;
	} 

	return true;
}

bool ShaderManager::LinkProgram()
{
	glLinkProgram(m_shaderProgramID);

	glGetProgramiv(m_shaderProgramID, GL_LINK_STATUS, &linkResult);

	if (linkResult == GL_FALSE) 
	{
		return false;
	} 

	glUseProgram(m_shaderProgramID);

	return true;
}

void ShaderManager::DetachDestroy()
{
	glDetachShader(m_shaderProgramID, m_fragmentShaderID); 
	glDetachShader(m_shaderProgramID, m_vertexShaderID);

	glDeleteShader(m_fragmentShaderID);
	glDeleteShader(m_vertexShaderID);

	glDeleteProgram(m_shaderProgramID);
}
