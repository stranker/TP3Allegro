#include "Enemy.h"



Enemy::Enemy(float posX, float posY, const char* fileLoc, int w, int h) : Sprite(posX,posY,fileLoc,w,h)
{
	AddType(ENEMY);
}


Enemy::~Enemy()
{
}

void Enemy::Kill()
{
}

bool Enemy::IsAlive()
{
	return isAlive;
}
