#ifndef CARACOL_H
#define CARACOL_H
#include "Rayo.h"
#include "Sprite.h"
#define MAX_LIFE 3

class Caracol : public Sprite
{
private:
	bool keys[4] = { false, false, false, false };
	int dirX = 1;
	int dirY = 0;
	const int speed = 3;
	bool canShoot = true;
	Rayo* rayo;
	int life = MAX_LIFE;
public:
	Caracol(float posX, float posY);
	Caracol(float posX, float posY, const char* imageFile, int w, int h);
	~Caracol();
	void Movimiento(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H);
	void Update(ALLEGRO_EVENT ev, int SCREEN_W, int SCREEN_H);
	void SetCanShoot(bool val);
	bool GetCanShoot() const;
	int GetDirX() const;
	int GetDirY() const;
	Rayo* GetRayo() const;
	void TakeDamage();
	bool isAlive() const;
	int GetLives() const;
};

#endif

