#include"Entity.h"

SDL_Texture* Entity::getTex()
{
	return Tex;
}

SDL_Rect Entity::getScrDimension()
{
	return src;
}

SDL_Rect Entity::getDesDimension()
{
	return dest;
}


void Entity::setScrDimension(int x, int y, int w, int h)
{
	src.x = x;
	src.y = y;
	src.h = h;
	src.w = w;
}

void Entity::setDesDimension(int x, int y, int w, int h)
{
	dest.x = x;
	dest.y = y;
	dest.h = h;
	dest.w = w;
}

void Entity::CreateTexture(const char* filelocation, SDL_Renderer* ren)
{
	Tex = TextureManager::Texture(filelocation, ren);
}



void Entity::SetAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(getTexture(), alpha);
}