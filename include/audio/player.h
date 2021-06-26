#ifndef PLAYER_H
#define PLAYER_H

#include <map>
#include <SDL_mixer.h>

class Player
{
public:
    Player();
    ~Player();
    void addSample(int, Mix_Chunk *);
    void addMusic(int, Mix_Music *);
    void playSample(int);
    void playMusic(int);
    void isPlayMusic();
    void setMusicVolume(int);
    int getMusicVolume();
    void setSampleVolume(int, int);
    int getSampleVolume(int);
    void setVolume(int);
    int getVolume();

private:
    std::map<int, Mix_Chunk *> samples;
    std::map<int, Mix_Music *> musics;
};

#endif