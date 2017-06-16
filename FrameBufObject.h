#pragma once
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <glew.h>
#include <glm.hpp>


class FrameBufObject
{
public:
	FrameBufObject();

	void BindFBO();


	void Initialise();

	GLuint & GetTexture();

	GLuint GetRBO();

	void UnBindFBO();

	void Delete();

	//void BindFBO(int ind);
	//void UnBindFBO(int ind);

	//void Delete(int ind);

	//GLuint &GetColorBuffer(int ind);


	//GLuint fbo[2];
	
	GLuint fbo;
	GLuint rboDepthStencil;
	GLuint color_texture[2];
	GLuint _texture;

	GLuint attachments[2];

	~FrameBufObject();
	GLuint & GetColorBuffer(int ind);
};

