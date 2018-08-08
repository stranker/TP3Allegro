#ifndef MENU_SCENE_H
#define MENU_SCENE_H
#include "Scene.h"
#include "Caracol.h"

class MenuScene :
	public Scene
{
private:
	ALLEGRO_FONT * titleFont, *menuFont;
	Caracol* caracol;
	ALLEGRO_SAMPLE *titleSound = NULL;
	int nextScene = 0;
public:
	MenuScene();
	~MenuScene();
	virtual int Run();
	virtual void Draw();
	virtual void Update();
};

#endif