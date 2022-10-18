#include <iostream>
#include "GameLoop.h"
using namespace std;
int main(int argc, char* argv[]) {
	GameLoop* game = new GameLoop;
	double first;
	double last = 0;
	game->Initialize();
	while (game->getGameState())
	{
		game->Event();
		game->Update();
		game->Render();
		//fix FPS 60FPS
		first = SDL_GetTicks();
		if (first - last < 16.7)
		{
			SDL_Delay(16.7 - (first - last));
			//cout << 1000 / ((16.7 - (first - last)) + (first - last)) << endl;
		}
		//cout << first - last << endl;
		last = first;
	}
	game->Clean();
	return 0;
}