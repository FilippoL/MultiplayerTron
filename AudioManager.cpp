#include "AudioManager.h"
#include <iostream>



AudioManager::AudioManager()
{
	m_system = nullptr;
	m_backg_music = nullptr;
	m_flashsound = nullptr;

}


bool AudioManager::Init()
{
	System_Create(&m_system);
	m_system->init(100, FMOD_INIT_NORMAL, NULL);
	if (!m_system)
	{
		std::cout << "Audio not intialised!" << std::endl;
		return false;
	}

	return true;
}

bool AudioManager::LoadMusic(const std::string & filename)
{
	m_system->createStream(filename.c_str(),FMOD_LOOP_NORMAL,0, &m_backg_music );

	if (!m_backg_music)
	{
		std::cout << "Music not loaded!" << std::endl;
		return false;

	}

	return true;
}

bool AudioManager::LoadSFX(const std::string & filename)
{
	m_system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &m_flashsound);

	if (!m_flashsound)
		{
			std::cout << "SFX not loaded!" << std::endl;
			return false;

		}

	return true;
}

void AudioManager::Unload()
{

	m_backg_music->release();
	m_flashsound->release();
}

void AudioManager::ShutDown()
{
	m_system->release();
}

void AudioManager::Update()
{

	m_system->update();
}

AudioManager::~AudioManager()
{
}
