#include "Caracol.h"

enum KEYS { UP, DOWN, LEFT, RIGHT };

Caracol::Caracol(float posX, float posY, const char * imageFile, int w, int h) : Sprite(posX, posY, imageFile, w, h)
{
	rayo = new Rayo(posX, posY, "laser.png", 32, 32);
}

Caracol::~Caracol()
{
}

void Caracol::Movimiento(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_SPACE:
			if (canShoot) {
				if (dirX == -1)
					rayo->Shoot(GetPosX(), GetPosY() + 10, dirX, dirY);
				else
					rayo->Shoot(GetPosX() + GetWidth(),GetPosY() + 10,dirX, dirY);
				canShoot = false;
			}
			break;
		case ALLEGRO_KEY_UP:
			keys[UP] = true;
			dirY = -1;
			dirX = 0;
			break;
		case ALLEGRO_KEY_DOWN:
			keys[DOWN] = true;
			dirY = 1;
			dirX = 0;
			break;
		case ALLEGRO_KEY_LEFT:
			keys[LEFT] = true;
			dirX = -1;
			dirY = 0;
			break;
		case ALLEGRO_KEY_RIGHT:
			keys[RIGHT] = true;
			dirX = 1;
			dirY = 0;
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

void Caracol::Update(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H) {
	Movimiento(ev, SCREEN_W, SCREEN_H);
	if (rayo->GetActivated())
		rayo->Update(SCREEN_W, SCREEN_H);
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
