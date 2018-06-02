#include<iostream>
#include<stdio.h>
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	Game* game = new Game(800, 600, 60);
	while (!game->IsGameOver()) 
	{
		game->Update();
		game->Draw();
	}
	al_rest(0.5);
	delete game;
	return 0;
} 