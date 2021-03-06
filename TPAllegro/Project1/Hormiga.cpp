#include "Hormiga.h"

Hormiga::Hormiga(float posX, float posY, int dX, int dY) : Enemy(posX, posY, "Asset/Sprite/hormiga.png", 40, 40)
{
	dirX = dX;
	dirY = dY;
	hit = al_load_sample("Asset/Sound/hormigaHit.wav");
	if (dX == 1)
		ChangeSprite("Asset/Sprite/hormigaR.png");
	else if(dX == -1)
		ChangeSprite("Asset/Sprite/hormigaL.png");
	else if(dY == 1)
		ChangeSprite("Asset/Sprite/hormigaD.png");
}

Hormiga::~Hormiga()
{
	al_destroy_sample(hit);
}

void Hormiga::Movimiento()
{
	Move(dirX * speed, dirY * speed);
}

void Hormiga::Update()
{
	Movimiento();
}

void Hormiga::Kill()
{
	if (isAlive)
	{
		isAlive = false;
		al_play_sample(hit, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		gameScore += SCORE_HORMIGA;
	}
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
