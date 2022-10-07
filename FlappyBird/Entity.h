#pragma once
#include "TextureManager.h"
class Entity {
public:
	SDL_Rect getScrDimension();
	void setScrDimension(int x, int y, int w, int h);
	SDL_Rect getDesDimension();
	void setDesDimension(int x, int y, int w, int h);
	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	SDL_Texture* getTex();
	void CreateTexture(const char* filelocation, SDL_Renderer* ren);
	virtual void Render(SDL_Renderer* ren) = 0;
private:
	SDL_Rect scrDimension;
	SDL_Rect desDimension;
	SDL_Texture* tex;
	int x;
	int y;
};