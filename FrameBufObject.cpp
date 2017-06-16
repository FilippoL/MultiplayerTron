#include "FrameBufObject.h"
#include <iostream>

#define WIDTH 1600
#define HEIGHT 900

FrameBufObject::FrameBufObject()
{
	
}

void FrameBufObject::BindFBO()
{
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

}

void FrameBufObject::Initialise()
{
	
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);  
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);


	glGenRenderbuffers(1, &rboDepthStencil);
	glBindRenderbuffer(GL_RENDERBUFFER, rboDepthStencil);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, WIDTH, HEIGHT);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);


	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _texture, 0);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rboDepthStencil);
		
		
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout <<"ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}

GLuint &FrameBufObject::GetTexture()
{
	return _texture;
}
GLuint FrameBufObject::GetRBO()
{
	return rboDepthStencil;
}


void FrameBufObject::UnBindFBO()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBufObject::Delete()
{
	glDeleteFramebuffers(1, &fbo);  
}


FrameBufObject::~FrameBufObject()
{
	
}

/*
void FrameBufObject::BindFBO(int ind)
{
	glBindFramebuffer(GL_FRAMEBUFFER, fbo[ind]);
}

void FrameBufObject::Initialise()
{
	for (size_t i = 0; i < 2; i++)
	{
		glGenFramebuffers(1, &fbo[i]);
		glBindFramebuffer(GL_FRAMEBUFFER, fbo[i]);
	}

	glGenTextures(2, color_texture);
	
	for (int i = 0; i < 2; i++)
	{
		glBindTexture(GL_TEXTURE_2D, color_texture[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);  
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);  
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glBindTexture(GL_TEXTURE_2D, 0);


		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, color_texture[i], 0);

	}


	glGenRenderbuffers(1, &rboDepthStencil);
	glBindRenderbuffer(GL_RENDERBUFFER, rboDepthStencil);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, WIDTH, HEIGHT);
	
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepthStencil);
		
	GLuint attachments[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
	glDrawBuffers(2, attachments);  
	
	
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout <<"ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	
};


void FrameBufObject::UnBindFBO(int ind)
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void FrameBufObject::Delete(int ind)
{
	glDeleteFramebuffers(1, &fbo[ind]);  
}

GLuint & FrameBufObject::GetColorBuffer(int ind)
{
	return color_texture[ind];
}
*/