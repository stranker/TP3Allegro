#include<iostream>
#include<stdio.h>
#include "Game.h"
#include "MenuScene.h"
#include "CreditsScene.h"

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	MenuScene* menu = new MenuScene(800,600, 60);
	CreditsScene* credits = new CreditsScene(800, 600, 60);
	vector<Scene*> scenes;
	int currentScene = 0;
	scenes.push_back(menu);
	scenes.push_back(credits);
	while (currentScene >= 0)
	{
		currentScene = scenes[currentScene]->Run();
	}
	al_rest(0.5);
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