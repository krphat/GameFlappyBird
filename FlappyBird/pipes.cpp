#include "Pipes.h"
#include "Object.h"


void Pipe::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, getTexture(), &getSrc(), &getDest());
}
bool Pipe::isTop()
{

	if (getyDest() < 0)
	{
		return true;
	}
	else
		return false;
}

void Pipe::MovePipe1()
{
	xlocation1 -= 1;
	xlocation2 -= 1;

	if (isTop() == true)
	{
		setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
		setDest(xlocation1, yPipeTop1, WIDTH_PIPE, HEIGHT_PIPE);
	}
	else
	{
		setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
		setDest(xlocation1, yPipeBottom1, WIDTH_PIPE, HEIGHT_PIPE);
	}


	if (xlocation1 + WIDTH_PIPE <= -0)
	{
		xlocation1 = xlocation2 + WIDTH_PIPE + DISTANCE_2PIPE -80;
		

	}
	if (xlocation2 + WIDTH_PIPE <= -0)
	{
		xlocation2 = xlocation1 + WIDTH_PIPE + DISTANCE_2PIPE -50 ;
	}

}

void Pipe::MovePipe2()
{
	xlocation1 -= 1;
	xlocation2 -= 1;
	if (isTop() == true)
	{
		setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
		setDest(xlocation2, yPipeTop2, WIDTH_PIPE, HEIGHT_PIPE);
	}
	else
	{
		setSource(0, 0, WIDTH_PIPE, HEIGHT_PIPE);
		setDest(xlocation2, yPipeBottom2, WIDTH_PIPE, HEIGHT_PIPE);
	}
	

	if (xlocation1 + WIDTH_PIPE <= -0)
	{
		xlocation1 = xlocation2 + WIDTH_PIPE + DISTANCE_2PIPE - 80;
	}
	if (xlocation2 + WIDTH_PIPE <= -0)
	{
		xlocation2 = xlocation1 + WIDTH_PIPE + DISTANCE_2PIPE -50 ;
	}

}




