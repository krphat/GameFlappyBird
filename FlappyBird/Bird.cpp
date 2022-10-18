#include "Bird.h"
#include "GameLoop.h"
using namespace std;
void Bird::Render(SDL_Renderer* ren) {
	timeAnimation++;
	if (timeAnimation < 20) {
		SDL_RenderCopyEx(ren, getTex(), &getScrDimension(), &getDesDimension(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (timeAnimation >= 20 && timeAnimation <= 40) {
		SDL_RenderCopyEx(ren, tex1, &getScrDimension(), &getDesDimension(), 0, NULL, SDL_FLIP_NONE);
	}
	else if (timeAnimation > 40) {
		SDL_RenderCopyEx(ren, tex2, &getScrDimension(), &getDesDimension(), 0, NULL, SDL_FLIP_NONE);
	}
	if (timeAnimation > 60) {
		timeAnimation = 0;
	}
}

void Bird::Gravity() {
	if (getJumpState()) {
		jumpHeight = gravity + jumpHeight;
		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		bird_position = bird_position + gravity + accelerator1 + accelerator2 + jumpHeight;
		setDesDimension(50, bird_position, 34, 24);
		if (jumpHeight > 0) {
			inJump = false;
			jumpHeight = -7;
		}
	}
	else {
		accelerator1 = accelerator1 + 0.035;
		accelerator2 = accelerator2 + 0.035;
		bird_position = bird_position + gravity + accelerator1 + accelerator2;
		setDesDimension(50, bird_position, 34, 24);
	}
}

double Bird::getBirdPosition() {
	return bird_position;
}

void Bird::getJumpTime() {
	jumptimer = SDL_GetTicks();
}

bool Bird::getJumpState() {
	return inJump;
}

void Bird::Jump() {
	if (jumptimer - lastJump > 100) {
		accelerator1 = 0;
		accelerator2 = 0;
		inJump = true;
		lastJump = jumptimer;
	}
	else
	{
		Gravity();
	}
}

void Bird::CreateTexture1(const char* filelocation, SDL_Renderer* ren) {
	tex1 = TextureManager::Texture(filelocation, ren);
}

void Bird::CreateTexture2(const char* filelocation, SDL_Renderer* ren) {
	tex2 = TextureManager::Texture(filelocation, ren);
}