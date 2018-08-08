#pragma once
#include "Scene.h"
class CreditsScene :
	public Scene
{
private:
	ALLEGRO_FONT *titleFont,*creditsFont, *exitFont;
public:
	CreditsScene(int _SCREEN_W, int _SCREEN_H, int _FPS);
	~CreditsScene();
	virtual int Run();
	virtual void Draw();
	virtual void Update();
};

