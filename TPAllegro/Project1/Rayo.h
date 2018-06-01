#ifndef RAYO_H
#define RAYO_H

#include "Sprite.h"

class Rayo : public Sprite{
	ALLEGRO_BITMAP * sprite = NULL;
	int dirX;
	int dirY;
	const int speed = 5;
	bool isActivated = false;
public:
	Rayo(float posX, float posY, const char* imageFile, int w, int h);
	~Rayo();
	void Movimiento(int SCREEN_W, int SCREEN_H);
	void Update(int SCREEN_W, int SCREEN_H);
	void Shoot(float posX, float posY, float dirX, float dirY);
	bool GetActivated() const;
	void SetActivated(bool val);
};
#endif

