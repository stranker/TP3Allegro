#ifndef COLLISION_H
#define COLLISION_H

#include "Sprite.h"

class Collision
{
public:
	static bool AABB(Sprite* c, Sprite* s);
};

#endif // !COLLISION_H

