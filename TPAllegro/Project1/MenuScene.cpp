#include "MenuScene.h"


int MenuScene::Run(Game & game)
{
	titleFont = al_load_ttf_font("Asset/Font/consola.ttf", 72, 0);
	menuFont = al_load_ttf_font("Asset/Font/consola.ttf", 28, 0);
	titleSound = al_load_sample("Asset/Sound/titleSound.wav");
	while (game.IsOpen())
	{
		
	}
	return 0;
}
