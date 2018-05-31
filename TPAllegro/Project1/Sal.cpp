#include "Sal.h"

Sal::Sal()
{
	sprite = al_load_bitmap("sal.png");
}

Sal::Sal(float posX, float posY, bool latMovement)
{
	sprite = al_load_bitmap("sal.png");
	positionX = posX;
	positionY = posY;
	lateralMovement = latMovement;
}

Sal::~Sal()
{
	al_destroy_bitmap(sprite);
}

void Sal::Movimiento(int SCREEN_W, int SCREEN_H)
{
	if (lateralMovement)
	{
		if (positionX < -spriteW || positionX > SCREEN_W)
		{
			positionY = 1 + rand() % (SCREEN_H - spriteH);
			if (rand() % 100 > 50)
			{
				positionX = SCREEN_W;
				dir = -1;
			}
			else
			{
				positionX = 0 - spriteW;
				dir = 1;
			}
		}
		Move(speed * dir, 0);
	}
	else
	{
		if (positionY > SCREEN_H || positionY < -spriteH)
		{
			positionX = 1 + rand() % (SCREEN_W - spriteW);
			if (rand() % 100 > 50)
			{
				positionY = SCREEN_H;
				dir = -1;
			}
			else
			{
				positionY = 0 - spriteH;
				dir = 1;
			}
		}
		Move(0, speed * dir);
	}
}

void Sal::Initialize(int SCREEN_W, int SCREEN_H)
{
	positionX = rand() % SCREEN_W - spriteW;
	positionY = rand() % SCREEN_H - spriteH;
	if (rand() % 100 > 50)
	{
		dir = 1;
		lateralMovement = true;
	}
	else
		dir = -1;
}

void Sal::Update(int SCREEN_W, int SCREEN_H)
{
	Movimiento(SCREEN_W, SCREEN_H);
}

void Sal::Draw()
{
	al_draw_bitmap(sprite, positionX, positionY, 0);
}

ALLEGRO_BITMAP * Sal::GetSprite() const
{
	return sprite;
}

float Sal::GetPosX() const
{
	return positionX;
}

float Sal::GetPosY() const
{
	return positionY;
}

float Sal::CollisionW() const
{
	return spriteW;
}

float Sal::CollisionH() const
{
	return spriteH;
}

void Sal::Move(float x, float y)
{
	positionX += x;
	positionY += y;
}
