#include "CreditsScene.h"

CreditsScene::CreditsScene()
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

int CreditsScene::Run(Window* window)
{
	SetRunning(true);
	SetWindow(window);
	while (IsRunning())
	{
		Update();
		Draw();
	}
	return MENU_SCENE;
}

void CreditsScene::Draw()
{
	if (GetWindow()->CanDraw())
	{
		GetWindow()->Draw();
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(titleFont, al_map_rgb(255, 255, 255), SCREEN_W / 2, 50, ALLEGRO_ALIGN_CENTRE, "CREDITS");
		al_draw_text(creditsFont, al_map_rgb(10, 0, 255), SCREEN_W / 2, 130, ALLEGRO_ALIGN_CENTRE, "Programmer:");
		al_draw_text(exitFont, al_map_rgb(10, 0, 255), SCREEN_W / 2, 180, ALLEGRO_ALIGN_CENTRE, "Nicolas Lopez");
		al_draw_text(exitFont, al_map_rgb(10, 0, 255), SCREEN_W / 2, 230, ALLEGRO_ALIGN_CENTRE, "Daniel H Natarelli");
		al_draw_text(creditsFont, al_map_rgb(10, 0, 255), SCREEN_W / 2, 280, ALLEGRO_ALIGN_CENTRE, "2D Special Artists:");
		al_draw_text(exitFont, al_map_rgb(10, 0, 255), SCREEN_W / 2, 330, ALLEGRO_ALIGN_CENTRE, "Nicolas Lopez");
		al_draw_text(exitFont, al_map_rgb(10, 0, 255), SCREEN_W / 2, 380, ALLEGRO_ALIGN_CENTRE, "Daniel H Natarelli");
		al_draw_text(exitFont, al_map_rgb(255, 0, 255), SCREEN_W / 2, 430, ALLEGRO_ALIGN_CENTRE, "Game made with Allegro library!");
		al_draw_text(exitFont, al_map_rgb(200, 0, 200), SCREEN_W / 2, SCREEN_H - 130, ALLEGRO_ALIGN_CENTRE, "If you see this game in another page just BUY it.");
		al_draw_text(exitFont, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H - 90, ALLEGRO_ALIGN_CENTRE, "PRESS 'R' TO RETURN");
		al_flip_display();
	}
}

void CreditsScene::Update()
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
		if (GetWindow()->GetEvent().keyboard.keycode == ALLEGRO_KEY_R)
		{
			SetRunning(false);
		}
	}
}
