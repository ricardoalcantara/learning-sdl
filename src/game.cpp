#include "game.h"
#include "texturemanager.h"
#include "gameobject.h"

GameObject* player;

Game::Game() {}

Game::~Game() {}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems OK!..." << std::endl;
		window = SDL_CreateWindow(title, x, y, width, height, flags);
		if (window) {
			std::cout << "Window Created" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 103, 215, 255, 0);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}

	player = new GameObject("assets/player.png", renderer, 0, 0);
}

void Game::handleEvent() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
	break;
	default:
		break;
	}
}

void Game::update() {
	player->update();
	cnt++;
	std::cout << "Number:" << cnt << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer);
	//DRAW THINGS
	player->render();
	//END DRAW
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}