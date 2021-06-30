#include "core/game.h"
#include "core/assetsmanager.h"
#include "core/gameobject.h"
#include "core/map.h"
#include "core/inputmanager.h"

#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include <sstream>

SDL_Renderer *Game::renderer = nullptr;

Game::Game()
{
	gameStateManager = GameStateManager::getInstance();
	inputManager = InputManager::getInstance();
}

Game::~Game()
{
	SDL_Quit();
}

void Game::init(const char *title, int x, int y, int scale, bool fullscreen)
{
	this->title = title;
	this->scale = scale;
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

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		std::cout << "Mix_OpenAudio: " << Mix_GetError() << std::endl;
		isRunning = false;
	}
}

void Game::clear()
{
	std::cout << "Game cleaned!" << std::endl;
	// quit SDL_mixer
	Mix_CloseAudio();
	// quit SDL_ttf
	TTF_Quit();
	// quit SDL_s
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			isRunning = false;
			return;
		}

		inputManager->handleEvents(&event);
		gameStateManager->handleEvents(&event);
	}
}

void Game::update()
{
	inputManager->update();
	gameStateManager->update();
	inputManager->end();
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 135, 206, 250, 255);
	SDL_RenderClear(renderer);
	//DRAW HERE

	gameStateManager->render();

	//END DRAW
	SDL_RenderPresent(renderer);
}

void Game::loop()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame * FPS))
		;

	deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

	deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

	ticksLastFrame = SDL_GetTicks();

	int timeToWait = FPS - (SDL_GetTicks() - ticksLastFrame);

	Uint32 frameStart;
	int frameTime;

	std::cout << SDL_GetBasePath() << std::endl;

	// FPS COUNT
	float fpsDelta = 0;
	float fpsDeltaTime = 0;
	int fpsCount;

	Uint64 now = SDL_GetPerformanceCounter();
	Uint64 last = 0;
	// FPS COUNT

	while (running())
	{
		// FPS COUNT
		last = now;
		now = SDL_GetPerformanceCounter();
		fpsDeltaTime = (double)((now - last) / (double)SDL_GetPerformanceFrequency());
		// FPS COUNT

		handleEvents();
		update();
		render();

		if (timeToWait > 0 && timeToWait <= FPS)
		{
			SDL_Delay(timeToWait);
		}

		// FPS COUNT
		fpsDelta += fpsDeltaTime;
		fpsCount++;
		if (fpsDelta >= 1.0f)
		{
			std::stringstream sstm;
			sstm << this->title << " - FPS: " << fpsCount;
			SDL_SetWindowTitle(window, sstm.str().c_str());
			fpsDelta = 0;
			fpsCount = 0;
		}
		// FPS COUNT
	}

	clear();
}