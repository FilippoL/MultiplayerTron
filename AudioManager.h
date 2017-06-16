#pragma once
#include <string>
#include "Singleton.h"
#include <glm.hpp>
#include <glew.h>
#include <map>
#include <fmod.hpp>

class AudioManager
{
public:
	friend class Singleton<AudioManager>;

public:
	bool Init();
	bool LoadMusic(const std::string& filename);
	bool LoadSFX(const std::string& filename);

	void Unload();
	void ShutDown();
	void Update();

public:
	FMOD::Sound *GetMusic() { return m_backg_music; };
	FMOD::Sound *GetSFX() { return m_flashsound; };
	FMOD::System *GetSystem() { return m_system; };


private:
	AudioManager();
	AudioManager(const AudioManager&);
	AudioManager& operator=(const AudioManager&);
	~AudioManager();

private:
	FMOD::System* m_system;
	FMOD::Sound* m_backg_music;
	FMOD::Sound* m_flashsound;

};

typedef Singleton<AudioManager> Audio;