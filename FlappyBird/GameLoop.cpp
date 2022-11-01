#include"GameLoop.h"
#include"Object.h"
#include"Pipes.h"
#include "Background.h"

GameLoop::GameLoop() {
	window = NULL;
	renderer = NULL;
//	gameState = false;
	gameState =NULL;
	//player set
	p.setSource(0, 0, 37, 27);
	p.setDest(20, 200, 37, 27);
	//pipe set
	pi1.setSource(0, 0, 65, 373);
	pi1.setDest(40, -100, 65, 373);
	pi2.setSource(0, 0, 65, 373);
	pi2.setDest(40, 400, 65, 373);
	pi3.setSource(0, 0, 65, 373);
	pi3.setDest(350, -200, 65, 373);
	pi4.setSource(0, 0, 65, 373);
	pi4.setDest(350, 300, 65, 373);
	// land set
	land1.setSource(0, 0, 400, 130);
	land1.setDest(0, 500, 400, 130);
	land2.setSource(0, 0, 400, 130);
	land2.setDest(0, 500, 400, 130);
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
			
			b.CreateTexture("background.png", renderer);
			p.CreateTexture("yellowbird-midflap2.png", renderer);
			land1.CreateTexture("floor.png", renderer);
			land2.CreateTexture("floor.png", renderer);
			//pipe create
			pi1.CreateTexture("pipe1.png",renderer);
			pi2.CreateTexture("pipe2.png", renderer);
			pi3.CreateTexture("pipe1.png", renderer);
			pi4.CreateTexture("pipe2.png", renderer);

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
	pi1.MovePipe1();
	pi2.MovePipe1();
	pi3.MovePipe2();
	pi4.MovePipe2();
	land1.Landmove1();
	land2.Landmove2();
		
}
void GameLoop::Render() {
	SDL_RenderClear(renderer);
	b.Render(renderer);
	//pipe render
	pi1.Render(renderer);
	pi2.Render(renderer);
	pi3.Render(renderer);
	pi4.Render(renderer);
	//land render
	land1.Render(renderer);
	land2.Render(renderer);
	p.Render(renderer);
	SDL_RenderPresent(renderer);
}

void GameLoop::Clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}
