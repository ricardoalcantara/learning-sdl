#include "audio/player.h"

#include <iostream>
#include "core/assetsmanager.h"

Player::Player()
{
}
Player::~Player()
{
    // Todo:: clean up our resources
	// Mix_FreeChunk(sample);
	// Mix_FreeMusic(music);
}

void Player::addSample(int id, Mix_Chunk *sample)
{
    samples.insert(std::make_pair(id, sample));
}

void Player::addMusic(int id, Mix_Music *music)
{
    musics.insert(std::make_pair(id, music));
}

void Player::playSample(int id)
{
    auto sample = samples[id];
    if (Mix_PlayChannel(-1, sample, 0) == -1)
    {
        std::cout << "Error: Playing sound" << id << std::endl;
    }
}

void Player::playMusic(int id)
{
    auto music = musics[id];

    if (Mix_PlayingMusic())
    {
        std::cout << "Error: Cannot play music while there is other music playing: " << id << std::endl;
        return;
    }

    if (Mix_PlayMusic(music, -1) == -1)
    {
        std::cout << "Error: Playing sound" << id << std::endl;
    }
}

void Player::isPlayMusic()
{
}

void Player::setMusicVolume(int volume)
{
    if (volume < 0 || volume > MIX_MAX_VOLUME)
    {
        std::cout << "Error: Volume must be set between 0 and " << MIX_MAX_VOLUME << std::endl;
        return;
    }

    Mix_VolumeMusic(volume);
}

int Player::getMusicVolume()
{
    return Mix_VolumeMusic(-1);
}

void Player::setSampleVolume(int id, int volume)
{
    auto sample = samples[id];
    if (volume < 0 || volume > MIX_MAX_VOLUME)
    {
        std::cout << "Error: Volume must be set between 0 and " << MIX_MAX_VOLUME << std::endl;
        return;
    }

    Mix_VolumeChunk(sample, volume);
}

int Player::getSampleVolume(int id)
{
    auto sample = samples[id];
    // Todo: check if it works, the documentation doesn't say that it returns the current volume
    return Mix_VolumeChunk(sample, -1);
}

void Player::setVolume(int volume)
{
    if (volume < 0 || volume > MIX_MAX_VOLUME)
    {
        std::cout << "Error: Volume must be set between 0 and " << MIX_MAX_VOLUME << std::endl;
        return;
    }

    Mix_Volume(-1, volume);
    setMusicVolume(volume);
}

