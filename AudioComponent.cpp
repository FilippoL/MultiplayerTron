#include "AudioComponent.h"
#include "AudioManager.h"



AudioComponent::AudioComponent()
{
	m_audioData = nullptr;
	m_channel = nullptr;
	m_channelgroup = nullptr;

}

void AudioComponent::SetMusic()
{
	m_audioData = Audio::Instance()->GetMusic();
}

void AudioComponent::SetSFX()
{
	m_audioData = Audio::Instance()->GetSFX();
}

void AudioComponent::Play()
{
	FMOD::System* system = Audio::Instance()->GetSystem();
	system->playSound(m_audioData, m_channelgroup, false, &m_channel);
}

void AudioComponent::Pause()
{
}

void AudioComponent::Stop()
{
}

void AudioComponent::Resume()
{
}


void AudioComponent::SetPan(float pan)
{
	if (m_channel)
	{
		m_channel->setPan(pan);
	}
}

AudioComponent::~AudioComponent()
{
}
