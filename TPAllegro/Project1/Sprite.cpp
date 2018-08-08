#include "Sprite.h"

Sprite::Sprite(float posX, float posY, const char* fileLoc, int w, int h)
{
	sprite = al_load_bitmap(fileLoc);
	positionX = posX;
	positionY = posY;
	spriteW = w;
	spriteH = h;
}

Sprite::~Sprite()
{
	al_destroy_bitmap(sprite);
}

void Sprite::Draw()
{
	if(flipH)
		al_draw_bitmap(sprite, positionX, positionY, ALLEGRO_FLIP_HORIZONTAL);
	else
		al_draw_bitmap(sprite, positionX, positionY, 0);

}

ALLEGRO_BITMAP * Sprite::GetSprite() const
{
	return sprite;
}

float Sprite::GetPosX() const
{
	return positionX;
}

float Sprite::GetPosY() const
{
	return positionY;
}

float Sprite::GetWidth() const
{
	return spriteW;
}

float Sprite::GetHeight() const
{
	return spriteH;
}

void Sprite::Move(float x, float y)
{
	positionX += x;
	positionY += y;
}

void Sprite::SetPosition(float x, float y)
{
	positionX = x;
	positionY = y;
}

void Sprite::Clamp(int xIni, int xFin, int yIni, int yFin)
{
	if (positionX < xIni)
		positionX = xIni;
	else if (positionX > xFin)
		positionX = xFin;
	if (positionY < yIni)
		positionY = yIni;
	else if (positionY > yFin)
		positionY = yFin;
}

void Sprite::FlipH(bool val)
{
	flipH = val;
}

void Sprite::ChangeSprite(const char * file)
{
	sprite = al_load_bitmap(file);
}

void Sprite::AddType(int _type)
{
	type = _type;
}

int Sprite::GetType() const
{
	return type;
}

bool Sprite::CheckCollision(Sprite * s1, Sprite * s2)
{
	return Collision::AABB(s1->GetPosX(),s1->GetPosY(),s1->GetWidth(),s1->GetHeight(),
		s2->GetPosX(), s2->GetPosY(), s2->GetWidth(), s2->GetHeight());
}

