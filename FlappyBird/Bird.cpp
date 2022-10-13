#include "Bird.h"

void Bird::Render(SDL_Renderer* ren) {
	SDL_RenderCopy(ren, getTex(), &getScrDimension(), &getDesDimension());
}