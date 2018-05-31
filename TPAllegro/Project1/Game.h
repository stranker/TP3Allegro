#ifndef GAME_H
#define GAME_H
#define CANT_SALEROS 3

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include "Caracol.h"
#include "Sal.h"
#include "Collision.h"
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