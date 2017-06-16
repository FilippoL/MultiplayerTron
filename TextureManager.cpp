#include "TextureManager.h"

#include <iostream>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <glew.h>
#include <windows.h>
#include <glm.hpp>
#include <glext.h>
#include <math.h>
#include <algorithm>



GLuint TextureManager::GetID(std::string name)
{
	return m_TextureMap[name];
}

bool TextureManager::LoadFile(std::string filename, std::string name, bool repeated)
{
	GLuint textureID;
	glGenTextures(1, &textureID);

	SDL_Surface* textureData = 0;
	textureData = IMG_Load(filename.c_str());

	if (!textureData)
	{

		std::cout << "ERROR LOADING TEXTURE FILE" << std::endl;

	}

	glBindTexture(GL_TEXTURE_2D, textureID);

	//RAW TEXTURES DATA
	unsigned char* pixels = (unsigned char*)textureData->pixels;
	unsigned int width = textureData->w;
	unsigned int height = textureData->h;
	unsigned int depth = textureData->format->BytesPerPixel;
	unsigned int format = ((depth == 4) ? GL_RGBA : GL_RGB);

	//MAGNIFICATION MINIFICATION WITH FILTER
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//WRAPPING TEXTURE FILTER
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (repeated) ? GL_MIRRORED_REPEAT : GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (repeated) ? GL_MIRRORED_REPEAT : GL_REPEAT);

	//BIND STUFF WITH TEXTURE
	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, 
		GL_UNSIGNED_BYTE, pixels);

	glBindTexture(GL_TEXTURE_2D, 0);

	//REMOVE RAW IMAGE FROM MEMORY
	SDL_FreeSurface(textureData);

	m_TextureMap[name] = textureID;

	for (auto it =  m_TextureMap.begin(); it != m_TextureMap.end(); it++)
	{
		std::cout << it->first <<"  "<< it->second << std::endl;
	}
	

	return true;
}

void TextureManager::AddTexture(std::string ID, GLuint Texture)
{
	m_TextureMap[ID] = Texture;
}


void TextureManager::UnloadSingleFile(std::string ID)
{
	//for (auto it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
	//{
	//	std::remove_if(m_TextureMap.begin(), m_TextureMap.end(), ToBeRemoved(m_TextureMap));
	//		
	//	//m_TextureMap.find();	glDeleteTextures(1, &(it->second));

	//}
	//glDeleteTextures(1, &m_TextureMap[ID]);

}


void TextureManager::UnloadFile()
{
	for (auto it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
	{
		glDeleteTextures(1, &(it->second));

	}

}

TextureManager::~TextureManager()
{
}

