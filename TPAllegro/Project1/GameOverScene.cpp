#include "GameOverScene.h"



GameOverScene::GameOverScene()
{
	titleFont = al_load_ttf_font("Asset/Font/consola.ttf", 72, 0);
	scoreFont = al_load_ttf_font("Asset/Font/consola.ttf", 36, 0);
	gameOverSound = al_load_sample("Asset/Sound/gameOver.wav");
}


GameOverScene::~GameOverScene()
{
}

int GameOverScene::Run(Window * window)
{
	SetRunning(true);
	SetWindow(window);
	al_play_sample(gameOverSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	while (IsRunning())
	{
		Update();
		Draw();
	}
	return MENU_SCENE;
}

void GameOverScene::Draw()
{
	if (GetWindow()->CanDraw())
	{
		GetWindow()->Draw();
		al_clear_to_color(al_map_rgb(20, 75, 0));
		al_draw_text(titleFont, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2 - 150, ALLEGRO_ALIGN_CENTRE, "GAME OVER!");
		al_draw_text(scoreFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H / 2, ALLEGRO_ALIGN_CENTRE, ("SCORE " + to_string(gameScore)).c_str());
		al_draw_text(scoreFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H - 150, ALLEGRO_ALIGN_CENTRE, "PRESS 'M' TO MAIN MENU");
		al_flip_display();
	}
}

void GameOverScene::Update()
{
	GetWindow()->EventManager();
	if (GetWindow()->GetEvent().type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		al_rest(0.2);
		SetRunning(false);
		GetWindow()->Close();
	}
	if (GetWindow()->GetEvent().type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (GetWindow()->GetEvent().keyboard.keycode == ALLEGRO_KEY_M)
		{
			al_rest(0.2);
			SetRunning(false);
		}
		else if (GetWindow()->GetEvent().keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			al_rest(0.2);
			SetRunning(false);
		}
	}
}
