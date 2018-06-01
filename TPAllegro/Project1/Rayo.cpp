#include "Rayo.h"

Rayo::Rayo(float posX, float posY, const char* imageFile, int w, int h) : Sprite(posX, posY, imageFile, w, h)
{
}

Rayo::~Rayo()
{
	al_destroy_bitmap(sprite);
}

void Rayo::Movimiento(int SCREEN_W, int SCREEN_H)
{
	Move(dirX * speed, dirY * speed);
	if (GetPosX() < 0 - GetWidth() || GetPosX() > SCREEN_W || GetPosY() < 0 - GetHeight() || GetPosY() > SCREEN_H)
		isActivated = false;
}

void Rayo::Update(int SCREEN_W, int SCREEN_H)
{
	Movimiento(SCREEN_W, SCREEN_H);
}

void Rayo::Shoot(float posX, float posY, float _dirX, float _dirY)
{
	SetPosition(posX, posY);
	dirX = _dirX;
	dirY = _dirY;
	isActivated = true;
}

bool Rayo::GetActivated() const
{
	return isActivated;
}

void Rayo::SetActivated(bool val)
{
	isActivated = val;
}
