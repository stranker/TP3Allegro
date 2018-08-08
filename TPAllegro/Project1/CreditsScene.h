#ifndef CREDITS_SCENE_H
#define CREDITS_SCENE_H
#include "Scene.h"

class CreditsScene :
	public Scene
{
private:
	ALLEGRO_FONT *titleFont,*creditsFont, *exitFont;
public:
	CreditsScene();
	~CreditsScene();
	virtual int Run(Window* window);
	virtual void Draw();
	virtual void Update();
};

#endif