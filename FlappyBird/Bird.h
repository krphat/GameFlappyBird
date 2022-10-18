#pragma once
#include "Entity.h"

class Bird : public Entity {
public:
	void Render(SDL_Renderer* ren);
	void Gravity();
	double getBirdPosition();
	void getJumpTime();
	void Jump();
	bool getJumpState();
	void CreateTexture1(const char* filelocation, SDL_Renderer* ren);
	void CreateTexture2(const char* filelocation, SDL_Renderer* ren);
private:
	int timeAnimation = 0;
	double gravity = 0.2;
	double bird_position = 50;
	double jumpHeight = -7;
	double accelerator1 = 0;
	double accelerator2 = 0;
	bool inJump = false;
	double jumptimer;
	double lastJump = 0;
	SDL_Event jump;
	SDL_Texture* tex1;
	SDL_Texture* tex2;
};
