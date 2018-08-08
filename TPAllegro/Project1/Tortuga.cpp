#include "Tortuga.h"

Tortuga::Tortuga() : Sprite(0, 0, "Asset/Sprite/tortuga.png", 80, 40)
{
	AddType(ENEMY);
	hit = al_load_sample("Asset/Sound/tortugaHit.wav");
	Initialize();
}

Tortuga::Tortuga(float posX, float posY, const char * fileLoc, int w, int h) : Sprite(posX, posY, fileLoc, w , h)
{
}

Tortuga::~Tortuga()
{
	al_destroy_sample(hit);
}

void Tortuga::Movimiento()
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

void Tortuga::Initialize()
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

void Tortuga::Update()
{
	Movimiento();
}

void Tortuga::Kill()
{
	al_play_sample(hit, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	Initialize();
}

void Tortuga::Collision(Sprite * collision)
{
	if (CheckCollision(this, collision))
	{
		if (collision->GetType() == BULLET)
		{
			Kill();
			gameScore += SCORE_TORTUGA;
		}
	}
}
