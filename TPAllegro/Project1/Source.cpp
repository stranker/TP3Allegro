#include<iostream>
#include<stdio.h>
#include "Game.h"
#include "MenuScene.h"
#include "CreditsScene.h"

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	//Game* game = new Game(800, 600, 60);
	MenuScene* menu = new MenuScene(800,600, 60);
	CreditsScene* credits = new CreditsScene(800, 600, 60);
	//menu->Run();
	credits->Run();
	al_rest(0.5);
	//delete game;
	delete menu;
	delete credits;
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