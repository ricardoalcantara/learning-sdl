#include "core/game.h"
#include "core/texturemanager.h"
#include "core/gameobject.h" 
#include "core/map.h"

<<<<<<< HEAD:src/core/game.cpp
GameObject* player;
SDL_Renderer* Game::renderer = nullptr;
Map* map;

SDL_Texture* playerTex;
SDL_Rect srcR, destR;

=======
>>>>>>> 69a4aca (Begin implementation):src/game.cpp
Game::Game() {
}

Game::~Game() {
	SDL_Quit();
}

int scale = 2;

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Starting systems..." << std::endl;
		window = SDL_CreateWindow(title, x, y, width * scale, height * scale, flags);

		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		SDL_RenderSetLogicalSize(renderer, width, height);
		
		isRunning = true;
	}
	else {
		isRunning = false; 
		std::cout << "Error! SDL had problems starting :(" << std::endl;
	}
<<<<<<< HEAD:src/core/game.cpp
	player = new GameObject("assets/player.png", 32, 32);
	map = new Map();
=======
>>>>>>> 69a4aca (Begin implementation):src/game.cpp
}

void Game::clear() {
	std::cout << "Game cleaned!" << std::endl;
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

template <typename T>
void Game::addState(const char* name)
{
	T *state = new T(this->renderer);
	// currentGameState = state;
}

void Game::loadState(const char*)
{
	if (currentGameState)
		currentGameState->load();
}

bool Game::isStateLoaded(const char*)
{
	return currentGameState && currentGameState->isLoaded();
}

void Game::selectState(const char*)
{

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
	if (currentGameState)
		currentGameState->update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	//DRAW HERE
	
<<<<<<< HEAD:src/core/game.cpp
	player->render();
	map->DrawMap();
=======
	if (currentGameState)
		currentGameState->render();
>>>>>>> 69a4aca (Begin implementation):src/game.cpp

	//END DRAW
	SDL_RenderPresent(renderer);
}