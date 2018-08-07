#include "MenuScene.h"


MenuScene::MenuScene(int _SCREEN_W, int _SCREEN_H, int _FPS) : Scene(_SCREEN_W,_SCREEN_H,_FPS)
{
}

int MenuScene::Run()
{
	titleFont = al_load_ttf_font("Asset/Font/consola.ttf", 72, 0);
	menuFont = al_load_ttf_font("Asset/Font/consola.ttf", 28, 0);
	titleSound = al_load_sample("Asset/Sound/titleSound.wav");
	while (IsRunning())
	{
		Update();
		Draw();
	}
	return 0;
}

void MenuScene::Draw()
{
	if (CanDraw())
	{
		SetRedraw(false);
		al_clear_to_color(al_map_rgb(50, 75, 0));
		al_flip_display();
	}
}

void MenuScene::Update()
{
	EventManager();
	if (GetEvent().type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (GetEvent().keyboard.keycode == ALLEGRO_KEY_ENTER)
		{
			al_set_timer_count(GetTimer(), 0);
			al_rest(0.2);
			al_play_sample(titleSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
		}
	}
}

