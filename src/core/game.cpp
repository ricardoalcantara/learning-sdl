#include "core/game.h"
#include "core/assetsmanager.h"
#include "core/gameobject.h"
#include "core/map.h"

#include <SDL_ttf.h>

SDL_Renderer *Game::renderer = nullptr;

Game::Game()
{
	gameStateManager = new GameStateManager();
}

Game::~Game()
{
	SDL_Quit();
}

void Game::init(const char *title, int x, int y, int scale, bool fullscreen)
{

	scale = scale;
	static int width = 320;
	static int height = 176;

	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Starting systems..." << std::endl;
		window = SDL_CreateWindow(title, x, y, width * scale, height * scale, flags);

		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			std::cout << "Renderer created!" << std::endl;
		}

		SDL_RenderSetLogicalSize(renderer, width, height);

		isRunning = true;
	}
	else
	{
		isRunning = false;
		std::cout << "Error! SDL had problems starting :(" << std::endl;
	}

	if (TTF_Init() == -1)
	{
		std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
		isRunning = false;
	}
}

void Game::clear()
{
	std::cout << "Game cleaned!" << std::endl;
	TTF_Quit();
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		clear();
		break;
	default:
		break;
	}
}

void Game::update()
{
	gameStateManager->getCurrentState()->update();
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255);
	SDL_RenderClear(renderer);
	//DRAW HERE

	gameStateManager->getCurrentState()->render();

	//END DRAW
	SDL_RenderPresent(renderer);
}