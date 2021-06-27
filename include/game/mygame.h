#ifndef MYGAME_H
#define MYGAME_H

#include "core/game.h"

class MyGame : public Game
{
public:
	enum GameStateEnum
	{
		Sandbox = 0,
		Map = 1
	};

public:
	void init(const char *title, int x, int y, int scale, bool fullscreen) override;
	void update() override;
	void render() override;
};

#endif