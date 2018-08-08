#ifndef RAYO_H
#define RAYO_H

#include "Sprite.h"
#include "Enemy.h"

class Rayo : public Sprite{
	ALLEGRO_BITMAP * sprite = NULL;
	ALLEGRO_SAMPLE *sound = NULL;
	int dirX;
	int dirY;
	const int speed = 5;
	bool isActivated = false;
public:
	Rayo(float posX, float posY, const char* imageFile, int w, int h);
	~Rayo();
	void Movimiento();
	void Update();
	void Shoot(float posX, float posY, float dirX, float dirY);
	bool GetActivated() const;
	void SetActivated(bool val);
	void Collision(Enemy* collision);
};
#endif

