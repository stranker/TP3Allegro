#ifndef HORMIGA_H
#define HORMIGA_H
#include "Enemy.h"

class Hormiga :	public Enemy
{
private:
	const int speed = 2;
	bool isAlive = true;
	int dirX;
	int dirY;
	ALLEGRO_SAMPLE *hit = NULL;
public:
	Hormiga(float posX, float posY, int dX, int dY);
	~Hormiga();
	void Movimiento();
	void Update();
	virtual void Kill();
	void SetDir(int x, int y);
	bool IsAlive() const;
	void Revive();
};

#endif