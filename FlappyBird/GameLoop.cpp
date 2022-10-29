#include"GameLoop.h"
#include"Object.h"
#include"Pipes.h"
#include "Background.h"

GameLoop::GameLoop() {
	window = NULL;
	renderer = NULL;
//	gameState = false;
	gameState =NULL;
	p.setSource(0, 0, 37, 27);
	p.setDest(20, 200, 37, 27);
	setPipe();
	land1.setSource(0, 0, 400, 130);
	land1.setDest(0, 500, 400, 130);
	land2.setSource(0, 0, 400, 130);
	land2.setDest(0, 500, 400, 130);
}

bool GameLoop::getGameState() {
	return gameState;
}
void GameLoop::setPipe()
{
	piTOP1.setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
	piTOP1.setDest(xPipeDouble1, yPipeTop1, WIDTH_PIPE, HEIGHT_PIPE);
	piUNDER1.setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
	piUNDER1.setDest(xPipeDouble1, yPipeBottom1, WIDTH_PIPE, HEIGHT_PIPE);
	piTOP2.setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
	piTOP2.setDest(xPipeDouble2, yPipeTop2, WIDTH_PIPE, HEIGHT_PIPE);
	piUNDER2.setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
	piUNDER2.setDest(xPipeDouble2, yPipeBottom2, WIDTH_PIPE, HEIGHT_PIPE);
}

void GameLoop::MovePipe()
{
	xlocation1 -= 1;
	
	xlocation2 -= 1;
	piTOP1.setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
	piTOP1.setDest(xlocation1, yPipeTop1, WIDTH_PIPE, HEIGHT_PIPE);
	piUNDER1.setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
	piUNDER1.setDest(xlocation1, yPipeBottom1, WIDTH_PIPE, HEIGHT_PIPE);
	piTOP2.setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
	piTOP2.setDest(xlocation2, yPipeTop2, WIDTH_PIPE, HEIGHT_PIPE);
	piUNDER2.setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
	piUNDER2.setDest(xlocation2, yPipeBottom2, WIDTH_PIPE, HEIGHT_PIPE);
	if (xlocation1 + WIDTH_PIPE <= 0)
	{
		xlocation1 = xlocation2+ WIDTH_PIPE +DISTANCE_2PIPE-50;
		
		
	}
	if (xlocation2 + WIDTH_PIPE <= 0)
	{
		xlocation2 = xlocation1 + WIDTH_PIPE + DISTANCE_2PIPE - 50;
	}
	
}

void GameLoop::Initialize() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH_SCREEN, HEIGHT_SCREEN, SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL) {
			cout << "Succeeded!" << endl;
			gameState = true;
			b.CreateTexture("background.png", renderer);
			p.CreateTexture("yellowbird-midflap2.png", renderer);
			land1.CreateTexture("floor.png", renderer);
			land2.CreateTexture("floor.png", renderer);
			piTOP1.CreateTexture("pipe1.png", renderer);
			piUNDER1.CreateTexture("pipe2.png", renderer);
			piTOP2.CreateTexture("pipe1.png", renderer);
			piUNDER2.CreateTexture("pipe2.png", renderer);

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
	land1.Landmove1();
	land2.setSource(0, 0, 400, 130);
	land2.setDest(xlocation2, 500, 400, 130);

	land2.Landmove2();
	MovePipe();
}

void GameLoop::Update() {
	//Source Dismension:
	
	//Destination Sismension:
		
}
void GameLoop::Render() {
	SDL_RenderClear(renderer);
	b.Render(renderer);
	piTOP1.Render(renderer);
	piUNDER1.Render(renderer);
	piTOP2.Render(renderer);
	piUNDER2.Render(renderer);
	land1.Render(renderer);
	land2.Render(renderer);
	p.Render(renderer);
	SDL_RenderPresent(renderer);
}

void GameLoop::Clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
