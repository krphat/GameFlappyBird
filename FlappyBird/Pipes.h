#pragma once
#include "Object.h"


class Pipe : public Object
{
public: 

	void Render(SDL_Renderer* ren);
	void MovePipe1();
	void MovePipe2();
	bool isTop();
	
private:
	
	const int WIDTH_PIPE = 65;
	const int HEIGHT_PIPE = 373;
	const int DISTANCE_2PIPE = 250;
	const int between = 130;
	const int xPipeDouble1 = /*WIDTH_SCREEN +*/ 450;
	const int yPipeTop1 = -200;
	const int yPipeBottom1 = HEIGHT_PIPE + yPipeTop1 + between;
	const int xPipeDouble2 = DISTANCE_2PIPE + xPipeDouble1;
	const int yPipeTop2 = -120;
	const int yPipeBottom2 = HEIGHT_PIPE + yPipeTop2 + between;
	int xlocation1 = xPipeDouble1 ;
	int xlocation2 = xPipeDouble2;
};

