#ifndef GAMEOVER_SCENE_H
#define GAMEOVER_SCENE_H
#include "Scene.h"

class GameOverScene :
	public Scene
{
private:
	ALLEGRO_FONT * titleFont, *scoreFont;
	ALLEGRO_SAMPLE *gameOverSound = NULL;
public:
	GameOverScene();
	~GameOverScene();
	virtual int Run(Window* window);
	virtual void Draw();
	virtual void Update();
};

#endif