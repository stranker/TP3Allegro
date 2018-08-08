#include<iostream>
#include<stdio.h>
#include "Window.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "CreditsScene.h"

using namespace std;

int	gameScore = 0;

int main(int argc, char **argv) {
	srand(time(NULL));
	Window* window = new Window();
	MenuScene* menuScene = new MenuScene();
	GameScene* gameScene = new GameScene();
	CreditsScene* creditsScene = new CreditsScene();
	vector<Scene*> scenes;
	int currentScene = 0;
	scenes.push_back(menuScene);
	scenes.push_back(creditsScene);
	scenes.push_back(gameScene);
	while (currentScene >= 0)
	{
		currentScene = scenes[currentScene]->Run(window);
	}
	al_rest(0.5);
	delete menuScene;
	delete creditsScene;
	delete gameScene;
	delete window;
	return 0;
} 


