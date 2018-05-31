#include<iostream>
#include<stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	ALLEGRO_BITMAP *laser = NULL;
	Game* game = new Game(800, 600, 60);
	while (!game->IsGameOver()) 
	{
		game->Update();
		game->Draw();
	}
	al_rest(0.1);
	delete game;
	return 0;
} 