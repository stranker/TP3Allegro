#ifndef RAYO_H
#define RAYO_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

class Rayo {
	ALLEGRO_BITMAP * sprite = NULL;
	float positionX;
	float positionY;
	const int spriteW = 40;
	const int spriteH = 8;
	int dirX;
	int dirY;
	const int speed = 5;
public:
	Rayo(float posX, float posY);
	~Rayo();
	void Movimiento(int SCREEN_W, int SCREEN_H);
	void Update(int SCREEN_W, int SCREEN_H);
	void Draw();
	ALLEGRO_BITMAP* GetSprite() const;
	float GetPosX() const;
	float GetPosY() const;
	float CollisionW() const;
	float CollisionH() const;
	void Move(float x, float y);
	void SetPosition(float x, float y);
};
#endif

