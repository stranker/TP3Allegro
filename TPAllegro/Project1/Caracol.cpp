#include "Caracol.h"

enum KEYS { UP, DOWN, LEFT, RIGHT };

Caracol::Caracol(float posX, float posY) : Sprite(posX, posY, "Asset/Sprite/player.png", 78, 50)
{
	AddType(PLAYER);
	rayo = new Rayo(posX, posY, "Asset/Sprite/laser.png", 32, 32);
	hit = al_load_sample("Asset/Sound/playerHit.wav");
}

Caracol::Caracol(float posX, float posY, const char * imageFile, int w, int h) : Sprite(posX, posY, imageFile, w, h)
{
	rayo = new Rayo(posX, posY, "Asset/Sound/laser.png", 32, 32);
	hit = al_load_sample("Asset/Sound/playerHit.wav");
}

Caracol::~Caracol()
{
	al_destroy_sample(hit);
}

void Caracol::Movimiento(ALLEGRO_EVENT ev)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_SPACE:
			if (canShoot) {
				if (dirY != 0)
					if (dirY == -1)
						rayo->Shoot(GetPosX() + GetHeight() / 2, GetPosY(), 0, dirY);
					else
						rayo->Shoot(GetPosX() + GetHeight() / 2, GetPosY() + GetWidth(), 0, dirY);
				else
					if (dirX == -1)
						rayo->Shoot(GetPosX(), GetPosY() + 10, dirX, 0);
					else
						rayo->Shoot(GetPosX() + GetWidth(), GetPosY() + 10, dirX, 0);
				canShoot = false;
			}
			break;
		case ALLEGRO_KEY_UP:
			keys[UP] = true;
			dirY = -1;
			ChangeSprite("Asset/Sprite/playerUp.png");
			break;
		case ALLEGRO_KEY_DOWN:
			keys[DOWN] = true;
			dirY = 1;
			ChangeSprite("Asset/Sprite/playerDown.png");
			break;
		case ALLEGRO_KEY_LEFT:
			keys[LEFT] = true;
			FlipH(true);
			dirX = -1;
			dirY = 0;
			ChangeSprite("Asset/Sprite/player.png");
			break;
		case ALLEGRO_KEY_RIGHT:
			keys[RIGHT] = true;
			FlipH(false);
			dirY = 0;
			dirX = 1;
			ChangeSprite("Asset/Sprite/player.png");
			break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP:
			keys[UP] = false;
			break;
		case ALLEGRO_KEY_DOWN:
			keys[DOWN] = false;
			break;
		case ALLEGRO_KEY_LEFT:
			keys[LEFT] = false;
			break;
		case ALLEGRO_KEY_RIGHT:
			keys[RIGHT] = false;
			break;
		}
	}
	Move(0, -keys[UP] * speed);
	Move(0, keys[DOWN] * speed);
	Move(-keys[LEFT] * speed, 0);
	Move(keys[RIGHT] * speed, 0);
	Clamp(0, SCREEN_W - GetWidth(), 0, SCREEN_H - GetHeight());
}

void Caracol::Update(ALLEGRO_EVENT ev) {
	Movimiento(ev);
	if (rayo->GetActivated())
		rayo->Update();
	else
		canShoot = true;
}

void Caracol::SetCanShoot(bool val)
{
	canShoot = val;
}

bool Caracol::GetCanShoot() const
{
	return canShoot;
}

int Caracol::GetDirX() const
{
	return dirX;
}

int Caracol::GetDirY() const
{
	return dirY;
}

Rayo * Caracol::GetRayo() const
{
	return rayo;
}

void Caracol::TakeDamage()
{
	if (IsAlive())
	{
		life--;
		al_play_sample(hit, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		SetPosition(SCREEN_W / 2 - GetWidth() / 2, SCREEN_H / 2 - GetHeight() / 2);
	}

}

int Caracol::GetLives() const
{
	return life;
}

void Caracol::Collision(Enemy * collision)
{
	if (CheckCollision(this, collision))
	{
		if (collision->GetType() == ENEMY)
		{
			if (collision->IsAlive())
			{
				TakeDamage();
				collision->Kill();
			}
		}
	}
}

void Caracol::ResetStats()
{
	life = MAX_LIFE;
	SetPosition(SCREEN_W / 2 - GetWidth() / 2, SCREEN_H / 2 - GetHeight() / 2);
	keys[0] = false;
	keys[1] = false;
	keys[2] = false;
	keys[3] = false;
}

bool Caracol::IsAlive() const
{
	return life > 0;
}
