#ifndef SCENE_H
#define SCENE_H

#include "Game.h"

using namespace std;

class Scene
{
private:
	bool sceneRunning;
public:
	virtual int Run(Game &game) = 0;
};

#endif