#pragma once
#include "TextureManager.h"
class Entity {
public:
	SDL_Rect& getScrDimension();
	void setScrDimension(int x, int y, int w, int h);
	SDL_Rect& getDesDimension();
	void setDesDimension(int x, int y, int w, int h);
	
	SDL_Texture* getTex();
	void CreateTexture(const char* filelocation, SDL_Renderer* ren);
	virtual void Render(SDL_Renderer* ren) = 0;


	void SetAlpha(Uint8 alpha);
private:
	SDL_Rect scrDimension;
	SDL_Rect desDimension;
	SDL_Texture* tex;
};
