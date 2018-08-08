#include "Rayo.h"

Rayo::Rayo(float posX, float posY, const char* imageFile, int w, int h) : Sprite(posX, posY, imageFile, w, h)
{
	AddType(BULLET);
	sound = al_load_sample("Asset/Sound/laser.wav");
}

Rayo::~Rayo()
{
	al_destroy_bitmap(sprite);
	al_destroy_sample(sound);
}

void Rayo::Movimiento()
{
	Move(dirX * speed, dirY * speed);
	if (GetPosX() < 0 - GetWidth() || GetPosX() > SCREEN_W || GetPosY() < 0 - GetHeight() || GetPosY() > SCREEN_H)
		isActivated = false;
}

void Rayo::Update()
{
	Movimiento();
}

void Rayo::Shoot(float posX, float posY, float _dirX, float _dirY)
{
	SetPosition(posX - GetWidth()/2, posY);
	dirX = _dirX;
	dirY = _dirY;
	isActivated = true;
	al_play_sample(sound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

bool Rayo::GetActivated() const
{
	return isActivated;
}

void Rayo::SetActivated(bool val)
{
	isActivated = val;
}

void Rayo::Collision(Enemy* collision)
{
	if (CheckCollision(this,collision))
	{
		if (collision->GetType() == ENEMY && isActivated)
		{
			isActivated = false;
			collision->Kill();
		}
	}
}
