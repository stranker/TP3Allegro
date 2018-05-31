#include "Collision.h"

bool Collision::AABB(Sprite* c, Sprite* s)
{
	return ((c->GetPosX() < s->GetPosX() + s->GetWidth()) && (s->GetPosX() < c->GetPosX() + c->GetWidth())
		&& (c->GetPosY() < s->GetPosY() + s->GetHeight()) && (s->GetPosY() < c->GetPosY() + c->GetHeight()));
}
