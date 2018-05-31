#ifndef SAL_H
#define SAL_H

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
class Sal
{
private:
	ALLEGRO_BITMAP * sprite = NULL;
	float positionX;
	float positionY;
	const int spriteW = 60;
	const int spriteH = 96;
	bool lateralMovement = false;
	const int speed = 2;
	int dir = 1;
public:
	Sal();
	Sal(float posX, float posY, bool lateralMovement);
	~Sal();
	void Movimiento(int SCREEN_W, int SCREEN_H);
	void Initialize(int SCREEN_W, int SCREEN_H);
	void Update(int SCREEN_W, int SCREEN_H);
	void Draw();
	ALLEGRO_BITMAP* GetSprite() const;
	float GetPosX() const;
	float GetPosY() const;
	float CollisionW() const;
	float CollisionH() const;
	void Move(float x, float y);
	void Kill(int SCREEN_W, int SCREEN_H);
};

#endif // ! SAL_H




