#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Scene.h"
#include "Caracol.h"
#include "Sal.h"
#include "Collision.h"
#include "Tortuga.h"
#include "Hormiguero.h"

class GameScene :
	public Scene
{
private:
	ALLEGRO_FONT *titleFont, *menuFont;
	Caracol* caracol;
	vector<Sal*> *saleros;
	vector<Tortuga*> *tortugas;
	vector<Sprite*> *lives;
	Hormiguero* hormiguero;
	ALLEGRO_SAMPLE *music = NULL;
	bool gameOver = false;
public:
	GameScene();
	~GameScene();
	void Initialize();
	virtual int Run(Window* window);
	virtual void Draw();
	virtual void Update();
	bool IsGameOver() const;
	void ResetGame();
};

#endif