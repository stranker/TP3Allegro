#ifndef SPRITE_H
#define SPRITE_H

#include "Resources.h"

using namespace std;

class Sprite
{
private:
	ALLEGRO_BITMAP * sprite = NULL;
	float positionX;
	float positionY;
	int spriteW;
	int spriteH;
	int type;
	bool flipH = false;
public:
	Sprite(float posX, float posY, const char* fileLoc, int w, int h);
	~Sprite();
	float GetPosX() const;
	float GetPosY() const;
	float GetWidth() const;
	float GetHeight() const;
	ALLEGRO_BITMAP* GetSprite() const;
	void Draw();
	void Move(float x, float y);
	void SetPosition(float x, float y);
	void Clamp(int xIni, int xFin, int yIni, int yFin);
	void FlipH(bool val);
	void ChangeSprite(const char* file);
	void Collision(Sprite* sprite);
	void AddType(int _type);
	int GetType() const;
};

#endif



