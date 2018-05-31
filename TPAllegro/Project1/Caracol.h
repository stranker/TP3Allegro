#ifndef CARACOL_H
#define CARACOL_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Rayo.h"


class Caracol
{
private:
	ALLEGRO_BITMAP * sprite = NULL;
	float positionX;
	float positionY;
	const int spriteW = 155;
	const int spriteH = 100;
	bool keys[4] = { false, false, false, false };
	int dirX = 1;
	int dirY = 0;
	const int speed = 3;
	Rayo* rayo;
	bool canShoot = true;
public:
	Caracol(float posX, float posY);
	~Caracol();
	void Movimiento(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H);
	void Update(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H);
	void Draw();
	ALLEGRO_BITMAP* GetSprite() const;
	float GetPosX() const;
	float GetPosY() const;
	float CollisionW() const;
	float CollisionH() const;
	void Move(float x, float y);
	void SetPosition(float x, float y);
	Rayo* GetRayo() const;
};

#endif

