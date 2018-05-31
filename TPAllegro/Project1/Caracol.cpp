#include "Caracol.h"

enum KEYS { UP, DOWN, LEFT, RIGHT };

Caracol::Caracol(float posX, float posY)
{
	sprite = al_load_bitmap("player.png");
	positionX = posX;
	positionY = posY;
}

Caracol::~Caracol()
{
	al_destroy_bitmap(sprite);
}

void Caracol::Movimiento(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H)
{
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_SPACE:
			if (canShoot)
			{
				/*
				laserX = playerX + playerW;
				laserY = playerY + 5;
				canShoot = false;
				laserDirX = dirX;
				laserDirY = dirY;*/
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
	positionY -= keys[UP] * speed;
	positionY += keys[DOWN] * speed;
	positionX -= keys[LEFT] * speed;
	positionX += keys[RIGHT] * speed;
	if (positionX < 0)
		positionX = 0;
	else if (positionX > SCREEN_W - spriteW)
		positionX = SCREEN_W - spriteW;
	if (positionY < 0)
		positionY = 0;
	else if (positionY > SCREEN_H - spriteH)
		positionY = SCREEN_H - spriteH;
}

void Caracol::Update(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H) {
	Movimiento(ev, SCREEN_W, SCREEN_H);
}

void Caracol::Draw()
{
	al_draw_bitmap(sprite, positionX, positionY, 0);
}

ALLEGRO_BITMAP* Caracol::GetSprite() const
{
	return sprite;
}

float Caracol::GetPosX() const
{
	return positionX;
}

float Caracol::GetPosY() const
{
	return positionY;
}

float Caracol::CollisionW() const
{
	return spriteW;
}

float Caracol::CollisionH() const
{
	return spriteH;
}

void Caracol::Move(float x, float y)
{
	positionX += x;
	positionY += y;
}