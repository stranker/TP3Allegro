#include "MenuScene.h"

MenuScene::MenuScene()
{
	titleFont = al_load_ttf_font("Asset/Font/consola.ttf", 72, 0);
	menuFont = al_load_ttf_font("Asset/Font/consola.ttf", 28, 0);
	titleSound = al_load_sample("Asset/Sound/titleSound.wav");
}

MenuScene::~MenuScene()
{
	delete caracol;
	al_destroy_font(menuFont);
	al_destroy_font(titleFont);
	al_destroy_sample(titleSound);
}

int MenuScene::Run()
{
	SetRunning(true);
	al_play_sample(titleSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	caracol = new Caracol(SCREEN_W / 2, SCREEN_H / 2);
	while (IsRunning())
	{
		Update();
		Draw();
	}
	return nextScene;
}

void MenuScene::Draw()
{
	if (CanDraw())
	{
		SetRedraw(false);
		al_clear_to_color(al_map_rgb(20, 75, 0));
		al_draw_text(titleFont, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2 - 150, ALLEGRO_ALIGN_CENTRE, "SNAILWORM SHIM");
		al_draw_text(menuFont, al_map_rgb(200, 0, 200), SCREEN_W / 2, SCREEN_H / 2 - 90, ALLEGRO_ALIGN_CENTRE, "REFURBISHED EDITION!");
		al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H - 200, ALLEGRO_ALIGN_CENTRE, "USE 'ARROWS' TO MOVE AND 'SPACE' TO FIRE!");
		al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H - 150, ALLEGRO_ALIGN_CENTRE, "PRESS 'ENTER' TO START GAME");
		al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H - 100, ALLEGRO_ALIGN_CENTRE, "PRESS 'C' TO CREDITS");
		al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H - 50, ALLEGRO_ALIGN_CENTRE, "PRESS 'ESC' TO EXIT");
		caracol->Draw();
		if (!caracol->GetCanShoot())
		{
			caracol->GetRayo()->Draw();
		}
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
		}
		else if (GetEvent().keyboard.keycode == ALLEGRO_KEY_C)
		{
			nextScene = 1;
			SetRunning(false);
		}
		else if (GetEvent().keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			nextScene = -1;
			SetRunning(false);
		}
	}
	caracol->Update(GetEvent());
	caracol->GetRayo()->Update();
}

