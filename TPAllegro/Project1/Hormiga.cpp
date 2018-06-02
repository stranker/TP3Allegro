#include "Hormiga.h"



Hormiga::Hormiga(float posX, float posY, int dX, int dY) : Sprite(posX, posY, "Asset/Sprite/hormiga.png", 20, 20)
{
	dirX = dX;
	dirY = dY;
}

Hormiga::~Hormiga()
{
}

void Hormiga::Movimiento(int SCREEN_W, int SCREEN_H)
{
	Move(dirX * speed, dirY * speed);
}

void Hormiga::Update(int SCREEN_W, int SCREEN_H)
{
	Movimiento(SCREEN_W, SCREEN_H);
}

void Hormiga::Kill()
{
	if (isAlive)
		isAlive = false;
}

void Hormiga::SetDir(int x, int y)
{
	dirX = x;
	dirY = y;
}

bool Hormiga::IsAlive() const
{
	return isAlive;
}

void Hormiga::Revive()
{
	isAlive = true;
}
