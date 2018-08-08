#include "Sal.h"

Sal::Sal() : Enemy (0,0,"Asset/Sprite/sal.png",60,96)
{
	Initialize();
	hit = al_load_sample("Asset/Sound/salHit.wav");
}

Sal::Sal(float posX, float posY, const char * imageFile, int w, int h, bool latMov) : Enemy(posX, posY, imageFile, w, h)
{
	lateralMovement = latMov;
	hit = al_load_sample("Asset/Sound/salHit.wav");
}

Sal::~Sal()
{
	al_destroy_sample(hit);
}

void Sal::Movimiento()
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

void Sal::Initialize()
{
	isAlive = true;
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

void Sal::Update()
{
	Movimiento();
}

void Sal::Kill()
{
	if (isAlive)
	{
		isAlive = false;
		gameScore += SCORE_SAL;
		al_play_sample(hit, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		Initialize();
	}

}
