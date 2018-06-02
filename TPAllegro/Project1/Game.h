#ifndef GAME_H
#define GAME_H
#define CANT_SALEROS 3
#define CANT_TORTUGAS 2

#include <stdio.h>
#include <iostream>
#include "Caracol.h"
#include "Sal.h"
#include "Collision.h"
#include "Tortuga.h"
#include <vector>

class Game
{
private:
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	bool redraw = true;
	bool gameOver = false;
	int SCREEN_W;
	int SCREEN_H;
	int FPS;
	Caracol* caracol;
	vector<Sal*> *saleros;
	vector<Tortuga*> *tortugas;
public:
	Game(int SCREEN_W, int SCREEN_H, int FPS);
	~Game();
	int Initialize();
	void Draw();
	void Update();
	int EventInit();
	int CreateWindow();
	int CreateTimer();
	bool IsGameOver();
};

#endif // !GAME_H