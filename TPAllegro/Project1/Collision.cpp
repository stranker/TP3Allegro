#include "Collision.h"

bool Collision::AABB(Caracol* c, Sal* s)
{
	return ((c->GetPosX() < s->GetPosX() + s->CollisionW()) && (s->GetPosX() < c->GetPosX() + c->GetWidth())
		&& (c->GetPosY() < s->GetPosY() + s->CollisionH()) && (s->GetPosY() < c->GetPosY() + c->GetHeight()));
}

bool Collision::AABB(Rayo* r, Sal* s)
{
	return ((r->GetPosX() < s->GetPosX() + s->CollisionW()) && (s->GetPosX() < r->GetPosX() + r->CollisionW())
		&& (r->GetPosY() < s->GetPosY() + s->CollisionH()) && (s->GetPosY() < r->GetPosY() + r->CollisionH()));
}
