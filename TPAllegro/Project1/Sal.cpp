#include "Sal.h"

Sal::Sal(int SCREEN_W, int SCREEN_H) : Sprite (0,0,"sal.png",60,96)
{
	Initialize(SCREEN_W,SCREEN_H);
}

Sal::Sal(float posX, float posY, const char * imageFile, int w, int h, bool latMov) : Sprite(posX, posY, imageFile, w, h)
{
	lateralMovement = latMov;
}

Sal::~Sal()
{
}

void Sal::Movimiento(int SCREEN_W, int SCREEN_H)
{
	if (lateralMovement)
	{
		if (GetPosX() < -GetWidth() || GetPosX() > SCREEN_W)
		{
			int posY = rand() % (int) (SCREEN_H - GetHeight());
			int posX;
			if (rand() % 100 > 50)
			{
				posX = SCREEN_W;
				dir = -1;
			}
			else
			{
				posX = 0 - GetWidth();
				dir = 1;
			}
			SetPosition(posX, posY);
		}
		Move(speed * dir, 0);
	}
	else
	{
		if (GetPosY() > SCREEN_H || GetPosY() < -GetHeight())
		{
			int posY;
			int posX = 1 + rand() % (int)(SCREEN_W - GetWidth());
			if (rand() % 100 > 50)
			{
				posY = SCREEN_H;
				dir = -1;
			}
			else
			{
				posY = 0 - GetHeight();
				dir = 1;
			}
			SetPosition(posX, posY);
		}
		Move(0, speed * dir);
	}
}

void Sal::Initialize(int SCREEN_W, int SCREEN_H)
{
	int posX;
	int posY;
	switch (rand() % 4)
	{
	case 0:
		posX = 0;
		posY = 0;
		break;
	case 1:
		posX = SCREEN_W;
		posY = 0;
		break;
	case 2:
		posX = 0;
		posY = SCREEN_H;
		break;
	case 3:
		posX = SCREEN_W;
		posY = SCREEN_H;
		break;
	default:
		break;
	}
	if (rand() % 100 > 50)
	{
		dir = 1;
		lateralMovement = true;
	}
	else
		dir = -1;
	SetPosition(posX, posY);
}

void Sal::Update(int SCREEN_W, int SCREEN_H)
{
	Movimiento(SCREEN_W, SCREEN_H);
}

void Sal::Kill(int SCREEN_W, int SCREEN_H)
{
	Initialize(SCREEN_W, SCREEN_H);
}
