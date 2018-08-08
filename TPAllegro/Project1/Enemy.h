#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"

class Enemy :
	public Sprite
{
private:
	bool isAlive = true;
public:
	Enemy(float posX, float posY, const char* fileLoc, int w, int h);
	~Enemy();
	virtual void Kill();
	bool IsAlive();
};
#endif
