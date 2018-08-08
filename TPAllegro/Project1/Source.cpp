#include<iostream>
#include<stdio.h>
#include "GameScene.h"
#include "MenuScene.h"
#include "CreditsScene.h"

using namespace std;

int globalScore = 0;

int main(int argc, char **argv) {
	srand(time(NULL));
	MenuScene* menu = new MenuScene();
	CreditsScene* credits = new CreditsScene();
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
} 