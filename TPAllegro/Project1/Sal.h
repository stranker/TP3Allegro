#ifndef SAL_H
#define SAL_H

#include "Sprite.h"

class Sal : public Sprite
{
private:
	bool lateralMovement = false;
	const int speed = 2;
	int dir = 1;
	ALLEGRO_SAMPLE *hit = NULL;
public:
	Sal();
	Sal(float posX, float posY, const char* imageFile, int w, int h, bool lateralMovement);
	~Sal();
	void Movimiento();
	void Initialize();
	void Update();
	void Kill();
};

#endif // ! SAL_H




