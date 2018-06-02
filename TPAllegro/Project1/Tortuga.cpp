#include "Tortuga.h"

Tortuga::Tortuga(int SCREEN_W, int SCREEN_H) : Sprite(0, 0, "tortuga.png", 80, 40)
{
	Initialize(SCREEN_W, SCREEN_H);
}

Tortuga::Tortuga(float posX, float posY, const char * fileLoc, int w, int h) : Sprite(posX, posY, fileLoc, w , h)
{
}

Tortuga::~Tortuga()
{
}

void Tortuga::Movimiento(int SCREEN_W, int SCREEN_H)
{
	if (GetPosX() < 0 - GetWidth())
	{
		dir = -1;
		SetPosition(0 - GetWidth(), rand() % SCREEN_H);
		FlipH(true);
	}
	else if (GetPosX() > SCREEN_W)
	{
		dir = 1;
		SetPosition(SCREEN_W, rand() % SCREEN_H);
		FlipH(false);
	}
	Move(dir*speed, 0);
}

void Tortuga::Initialize(int SCREEN_W, int SCREEN_H)
{
	if (rand() % 100 > 50)
	{
		dir = 1;
		SetPosition(0 - GetWidth(), rand() % (int)(SCREEN_H - GetHeight()));
		FlipH(true);
	}
	else
	{
		dir = -1;
		SetPosition(SCREEN_W, rand() % (int)(SCREEN_H - GetHeight()));
		FlipH(false);
	}
}

void Tortuga::Update(int SCREEN_W, int SCREEN_H)
{
	Movimiento(SCREEN_W, SCREEN_H);
}

void Tortuga::Kill(int SCREEN_W, int SCREEN_H)
{
	Initialize(SCREEN_W, SCREEN_H);
}
