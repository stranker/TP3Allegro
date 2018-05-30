#include<iostream>
#include<stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "Caracol.h"

using namespace std;

enum KEYS { UP, DOWN, LEFT, RIGHT };


bool AABB(const float x1, const float y1, const float w1, const float h1, const float x2, const float y2, const float w2, const float h2)
{
	return ((x1 < x2 + w2) && (x2 < x1 + w1) && (y1 < y2 + h2) && (y2 < y1 + h1));
}

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *enemy = NULL;
	ALLEGRO_BITMAP *enemy2 = NULL;
	ALLEGRO_BITMAP *laser = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	Caracol* caracol;
	int enemyX = 400;
	int enemyY = 400;
	int enemyX2 = 300;
	int enemyY2 = 10;
	const int enemyW = 60;
	const int enemyH = 96;
	int laserX;
	int laserY;
	const int laserW = 40;
	const int laserH = 8;
	const int FPS = 60;
	const int SCREEN_W = 800;
	const int SCREEN_H = 600;
	bool redraw = true;
	bool gameOver = false;
	int laserDirX;
	int laserDirY;


	if (!al_init()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);


	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	caracol = new Caracol(10, 10);
	enemy = al_load_bitmap("sal.png");
	enemy2 = al_load_bitmap("sal.png");
	laser = al_load_bitmap("laser.png");
	al_set_target_bitmap(caracol->GetSprite());
	al_set_target_bitmap(enemy);
	al_set_target_bitmap(laser);
	al_set_target_backbuffer(display);

	event_queue = al_create_event_queue();
	al_install_keyboard();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_clear_to_color(al_map_rgb(50, 75, 0));
	al_flip_display();
	al_start_timer(timer);

	while (!gameOver) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			gameOver = true;
		}

		caracol->Update(ev, SCREEN_W, SCREEN_H);

		enemyX -= 2;
		if (enemyX < -enemyW)
		{
			enemyY = 1 + rand() % (SCREEN_H - enemyH);
			enemyX = SCREEN_W;
		}

		enemyY2 += 2;
		if (enemyY2 > SCREEN_H)
		{
			enemyX2 = 1 + rand() % (SCREEN_W - enemyW);
			enemyY2 = 0;
		}

		if (AABB(caracol->GetPosX(), caracol->GetPosY(), caracol->CollisionW(), caracol->CollisionH(), enemyX, enemyY, enemyW, enemyH))
			gameOver = true;
		if (AABB(caracol->GetPosX(), caracol->GetPosY(), caracol->CollisionW(), caracol->CollisionH(), enemyX2, enemyY2, enemyW, enemyH))
			gameOver = true;
		/*if (AABB(laserX, laserY, laserW, laserH, enemyX, enemyY, enemyW, enemyH))
		{
			canShoot = true;
			enemyX = SCREEN_W;
			enemyY = 1 + rand() % (SCREEN_H - enemyH);
		}
		if (AABB(laserX, laserY, laserW, laserH, enemyX2, enemyY2, enemyW, enemyH))
		{
			canShoot = true;
			enemyX2 = 1 + rand() % (SCREEN_W - enemyW);
			enemyY2 = 0;
		}*/



		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(50, 75, 0));
			caracol->Draw();
			al_draw_bitmap(enemy, enemyX, enemyY, 0);
			al_draw_bitmap(enemy2, enemyX2, enemyY2, 0);
			/*if (!canShoot)
				al_draw_bitmap(laser, laserX, laserY, 0);*/
			al_flip_display();
		}

		/*if (!canShoot) {
			laserX += 6 * laserDirX;
			laserY += 6 * laserDirY;
		}
		if (laserX > SCREEN_W || laserX < 0 || laserY < 0 || laserY > SCREEN_H) {
			canShoot = true;
		}*/

	}


	al_rest(0.1);

	al_destroy_display(display);
	al_destroy_bitmap(enemy);
	al_destroy_bitmap(enemy2);
	al_destroy_bitmap(laser);
	al_destroy_timer(timer);

	return 0;
} 