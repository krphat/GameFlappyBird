#include"Object.h"
#include"TextureManager.h"

Object::Object()
{
	Tex = NULL;
}

SDL_Texture* Object::getTexture() 
{
	return Tex;
}
SDL_Rect& Object::getDest() 
{
	return dest;
}
SDL_Rect& Object::getSrc()
{
	return src;
}
void Object::setDest(int x, int y, int w, int h)
{
	dest.x = x;
	dest.y = y;
	dest.w = w;
	dest.h = h;
}
void Object::setSource(int x, int y, int w, int h)
{
	src.x = x;
	src.y = y;
	src.w = w;
	src.h = h;
}
//void setPipeSoure(int x, int y, int w, int h)
//{
//	dest.x= 
//}
void Object::CreateTexture(const char* address, SDL_Renderer* ren)
{
	Tex = TextureManager::Texture(address, ren);
}
//void TextureManager::Render(short int x, short int y, short int angle, SDL_Rect* clip, SDL_RendererFlip flip)
//{
//	SDL_Rect Rec_Render = { x, y, tWidth, tHeight };
//
//	if (clip != NULL)
//	{
//		Rec_Render.w = clip->w;
//		Rec_Render.h = clip->h;
//	}
//
//	SDL_RenderCopyEx(gRenderer, Texture, clip, &Rec_Render, angle, NULL, flip);

//bool Object::isNULL()
//{
//	if (getTexture == NULL)
//		return true;
//	return false;
// }