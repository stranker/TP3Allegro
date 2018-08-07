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
	MenuScene(int _SCREEN_W, int _SCREEN_H, int _FPS);
	virtual int Run();
	virtual void Draw();
	virtual void Update();
};

#endif