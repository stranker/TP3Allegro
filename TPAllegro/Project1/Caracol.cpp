#include "Caracol.h"

enum KEYS { UP, DOWN, LEFT, RIGHT };

Caracol::Caracol(float posX, float posY, const char * imageFile, int w, int h) : Sprite(posX, posY, imageFile, w, h)
{
	rayo = new Rayo(0, 0);
}

Caracol::~Caracol()
{
}

void Caracol::Movimiento(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_SPACE:
			if (canShoot)
			{
				rayo->SetPosition(GetPosX() + GetWidth() - 5, GetPosY() + 5);
				rayo->Shoot(dirX, dirY);
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
	Clamp(0, SCREEN_W, 0, SCREEN_H);
}

void Caracol::Update(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H) {
	Movimiento(ev, SCREEN_W, SCREEN_H);
	rayo->Update(SCREEN_W, SCREEN_H);
	if (!rayo->GetActivated())
		canShoot = true;
}

Rayo * Caracol::GetRayo() const
{
	return rayo;
}
