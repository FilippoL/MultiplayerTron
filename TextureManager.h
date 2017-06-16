#pragma once
#include <string>
#include "Singleton.h"
#include <glm.hpp>
//#include <glext.h>
#include <glew.h>
#include <map>

class TextureManager
{
public:
	friend class Singleton<TextureManager>;

public:
	GLuint GetID(std::string);


public:

	bool LoadFile(std::string filename, std::string name, bool repeated = false);
	void AddTexture(std::string, GLuint);
	void UnloadSingleFile(std::string ID);
	void UnloadFile();

private:
	TextureManager() {};
	TextureManager(const TextureManager&);
	TextureManager& operator=(const TextureManager&);

	std::map<std::string, GLuint>  m_TextureMap;



	~TextureManager();
};
typedef Singleton<TextureManager> Texture;