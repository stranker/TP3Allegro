#include<iostream>
#include<stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

using namespace std;

enum KEYS{UP,DOWN,LEFT,RIGHT};

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP  *player = NULL;
	ALLEGRO_BITMAP *enemy = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	int playerX = 200;
	int playerY = 200;
	int enemyX = 400;
	int enemyY = 400;
	bool keys[4] = { false, false, false, false };
	bool running = true;
	

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

	display = al_create_display(800, 600);
	

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}

	player = al_load_bitmap("player.png");
	enemy = al_load_bitmap("sal.png");
	al_set_target_bitmap(player);
	al_set_target_bitmap(enemy);
	al_set_target_backbuffer(display);
	
	
	if (!player) {
		al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		return 0;
	}
	event_queue = al_create_event_queue();
	al_install_keyboard();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));

	while (running) {
		al_clear_to_color(al_map_rgb(50, 75, 0));
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_ESCAPE:
				running = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				running = false;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			running = false;

		playerY -= keys[UP] * 10;
		playerY += keys[DOWN] * 10;
		playerX -= keys[LEFT] * 10;
		playerX += keys[RIGHT] *10;

		al_draw_bitmap(enemy, enemyX, enemyY,0);
		al_draw_bitmap(player, playerX, playerY, 0);
		al_flip_display();
	}

	
	al_rest(0.1);

	al_destroy_display(display);
	al_destroy_bitmap(player);
	al_destroy_bitmap(enemy);

	return 0;
}