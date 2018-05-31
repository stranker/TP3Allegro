#ifndef COLLISION_H
#define COLLISION_H

#include "Caracol.h"
#include "Sal.h"
#include "Rayo.h"

class Collision
{
public:
	static bool AABB(Caracol* c, Sal* s);
	static bool AABB(Rayo* r, Sal* s);
};

#endif // !COLLISION_H

