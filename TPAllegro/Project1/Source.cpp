#include<iostream>
#include<stdio.h>
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	Game* game = new Game(800, 600, 60);
	while (!game->IsOpen())
	{
		game->Update();
		game->Draw();
	}
	al_rest(0.5);
	delete game;
	return 0;
	/*
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// CIERRA LA VENTANA
			if ((event.type == Event::Closed) || (event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))
				window.close();
		}
		if (screen >= 0)
		{
			screen = screens[screen]->Run(window);
		}
	}

	return 0;
	*/
} 