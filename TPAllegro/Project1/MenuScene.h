#ifndef MENU_SCENE_H
#define MENU_SCENE_H
#include "Scene.h"
class MenuScene :
	public Scene
{
private:
	ALLEGRO_FONT * titleFont, *menuFont;
	ALLEGRO_SAMPLE *titleSound = NULL;
public:
	virtual int Run(Game &game);
};

#endif