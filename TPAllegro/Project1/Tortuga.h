#ifndef TORTUGA_H
#define TORTUGA_H

#include "Enemy.h"

class Tortuga :	public Enemy
{
private:
	const int speed = 1;
	int dir = 1;
	ALLEGRO_SAMPLE *hit = NULL;
	bool isAlive = true;
public:
	Tortuga();
	Tortuga(float posX, float posY, const char* fileLoc, int w, int h);
	~Tortuga();
	void Movimiento();
	void Initialize();
	void Update();
	virtual void Kill();
};

#endif