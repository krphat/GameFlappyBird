#include"GameLoop.h"

GameLoop::GameLoop() {
	window = NULL;
	renderer = NULL;
	gameState = false;
}

bool GameLoop::getGameState() {
	return gameState;
}

void GameLoop::Initialize() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH_SCREEN, HEIGHT_SCREEN, SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL) {
			cout << "Succeeded!" << endl;
			gameState = true;
			

		}
		else {
			cout << "Not created!" << endl;
		}
	}
	else {
		cout << "window not created!" << endl;
	}
}

void GameLoop::Event() {
	SDL_PollEvent(&exit);
	if (exit.type == SDL_QUIT) {
		gameState = false;
	}
	
}

void GameLoop::Update() {
	//Source Dismension:
	
	//Destination Sismension:
		
}
void GameLoop::Render() {
	SDL_RenderClear(renderer);
	
	SDL_RenderPresent(renderer);
}

void GameLoop::Clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}