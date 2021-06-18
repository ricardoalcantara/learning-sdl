#include "game.h"
#include <iostream>

SDL_Texture* playerTex;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Starting systems..." << std::endl;
		window = SDL_CreateWindow(title, x, y, width, height, flags);

		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		
		isRunning = true;
	}
	else {
		isRunning = false; 
		std::cout << "Error! SDL had problems starting :(" << std::endl;
	}
	SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}

void Game::clear() {
	std::cout << "Game cleaned!" << std::endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		clear();
		break;
	default:
		break;
	}
}

void Game::update() {
	ticker++;
	std::cout << "Tick: " << ticker << std::endl;
}

void Game::render() {
	SDL_RenderClear(renderer);
	//DRAW HERE
	
	SDL_RenderCopy(renderer, playerTex, NULL, NULL);

	//END DRAW
	SDL_RenderPresent(renderer);
}