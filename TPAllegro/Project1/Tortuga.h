#ifndef TORTUGA_H
#define TORTUGA_H

#include "Sprite.h"

class Tortuga :	public Sprite
{
private:
	const int speed = 1;
	int dir = 1;
	ALLEGRO_SAMPLE *hit = NULL;
public:
	Tortuga();
	Tortuga(float posX, float posY, const char* fileLoc, int w, int h);
	~Tortuga();
	void Movimiento();
	void Initialize();
	void Update();
	void Kill();
	void Collision(Sprite* collision);
};

#endif