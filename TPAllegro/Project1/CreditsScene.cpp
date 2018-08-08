#include "CreditsScene.h"

CreditsScene::CreditsScene(int _SCREEN_W, int _SCREEN_H, int _FPS) : Scene(_SCREEN_W, _SCREEN_H, _FPS)
{
	titleFont = al_load_ttf_font("Asset/Font/consola.ttf", 72, 0);
	creditsFont = al_load_ttf_font("Asset/Font/consola.ttf", 36, 0);
	exitFont = al_load_ttf_font("Asset/Font/consola.ttf", 28, 0);
}


CreditsScene::~CreditsScene()
{
	al_destroy_font(creditsFont);
	al_destroy_font(titleFont);
	al_destroy_font(exitFont);
}

int CreditsScene::Run()
{
	SetRunning(true);

	while (IsRunning())
	{
		Update();
		Draw();
	}
	return 0;
}

void CreditsScene::Draw()
{
	if (CanDraw())
	{
		SetRedraw(false);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(titleFont, al_map_rgb(255, 255, 255), GetScreenW() / 2, 50, ALLEGRO_ALIGN_CENTRE, "CREDITS");
		al_draw_text(creditsFont, al_map_rgb(10, 0, 255), GetScreenW() / 2, 130, ALLEGRO_ALIGN_CENTRE, "Programmer:");
		al_draw_text(exitFont, al_map_rgb(10, 0, 255), GetScreenW() / 2, 180, ALLEGRO_ALIGN_CENTRE, "Nicolas Lopez");
		al_draw_text(exitFont, al_map_rgb(10, 0, 255), GetScreenW() / 2, 230, ALLEGRO_ALIGN_CENTRE, "Daniel H Natarelli");
		al_draw_text(creditsFont, al_map_rgb(10, 0, 255), GetScreenW() / 2, 280, ALLEGRO_ALIGN_CENTRE, "2D Special Artists:");
		al_draw_text(exitFont, al_map_rgb(10, 0, 255), GetScreenW() / 2, 330, ALLEGRO_ALIGN_CENTRE, "Nicolas Lopez");
		al_draw_text(exitFont, al_map_rgb(10, 0, 255), GetScreenW() / 2, 380, ALLEGRO_ALIGN_CENTRE, "Daniel H Natarelli");
		al_draw_text(exitFont, al_map_rgb(200, 0, 200), GetScreenW() / 2, GetScreenH() - 130, ALLEGRO_ALIGN_CENTRE, "If you see this game in another page just BUY it.");
		al_draw_text(exitFont, al_map_rgb(255, 255, 255), GetScreenW() / 2, GetScreenH() - 90, ALLEGRO_ALIGN_CENTRE, "PRESS 'R' TO RETURN");
		al_flip_display();
	}
}

void CreditsScene::Update()
{
	EventManager();
	if (GetEvent().type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (GetEvent().keyboard.keycode == ALLEGRO_KEY_R)
		{
			SetRunning(false);
		}
	}
}
