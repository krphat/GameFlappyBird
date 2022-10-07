#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "Background.h"
using namespace std;

class GameLoop {
public:
	GameLoop();
	bool getGameState();
	void Initialize();
	void Render();
	void Event();
	void Update();
	void Clean();
private:
	const int WIDTH_SCREEEN = 800;
	const int HEIGHT_SCREEN = 640;
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool gameState;
	SDL_Event exit;
};
