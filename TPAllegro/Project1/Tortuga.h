#ifndef TORTUGA_H
#define TORTUTA_H

#include "Sprite.h"

class Tortuga :	public Sprite
{
private:
	const int speed = 1;
	int dir = 1;
public:
	Tortuga(int SCREEN_W, int SCREEN_H);
	Tortuga(float posX, float posY, const char* fileLoc, int w, int h);
	~Tortuga();
	void Movimiento(int SCREEN_W, int SCREEN_H);
	void Initialize(int SCREEN_W, int SCREEN_H);
	void Update(int SCREEN_W, int SCREEN_H);
	void Kill(int SCREEN_W, int SCREEN_H);
};

#endif