#include "Rayo.h"


Rayo::Rayo(float posX, float posY)
{
	sprite = al_load_bitmap("laser.png");
	positionX = posX;
	positionY = posY;
}

Rayo::~Rayo()
{
	al_destroy_bitmap(sprite);
}

void Rayo::Movimiento(int SCREEN_W, int SCREEN_H)
{
	Move(dirX * speed, dirY * speed);
	if (positionX < 0 - spriteW || positionX > SCREEN_W || positionY < 0 - spriteH || positionY > SCREEN_H)
		isActivated = false;
}

void Rayo::Update(int SCREEN_W, int SCREEN_H)
{
	Movimiento(SCREEN_W, SCREEN_H);
}

void Rayo::Draw()
{
	if (isActivated)
		al_draw_bitmap(sprite, positionX, positionY, 0);
}

ALLEGRO_BITMAP * Rayo::GetSprite() const
{
	return sprite;
}

float Rayo::GetPosX() const
{
	return positionX;
}

float Rayo::GetPosY() const
{
	return positionY;
}

float Rayo::CollisionW() const
{
	return spriteW;
}

float Rayo::CollisionH() const
{
	return spriteH;
}

void Rayo::Move(float x, float y)
{
	positionX += x;
	positionY += y;
}

void Rayo::SetPosition(float x, float y)
{
	positionX = x;
	positionY = y;
}

void Rayo::Shoot(float _dirX, float _dirY)
{
	dirX = _dirX;
	dirY = _dirY;
	isActivated = true;
}

bool Rayo::GetActivated() const
{
	return isActivated;
}
