#ifndef SAL_H
#define SAL_H

#include "Sprite.h"

class Sal : public Sprite
{
private:
	//const int spriteW = 60;
	//const int spriteH = 96;
	bool lateralMovement = false;
	const int speed = 2;
	int dir = 1;
public:
	Sal(const char *imageFile, int SCREEN_W, int SCREEN_H);
	Sal(float posX, float posY, const char* imageFile, int w, int h, bool lateralMovement);
	~Sal();
	void Movimiento(int SCREEN_W, int SCREEN_H);
	void Initialize(int SCREEN_W, int SCREEN_H);
	void Update(int SCREEN_W, int SCREEN_H);
	void Kill(int SCREEN_W, int SCREEN_H);
};

#endif // ! SAL_H




