#ifndef RESOURCES_H
#define RESOURCES_H

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// GAME VARS
// WINDOW
#define SCREEN_W 800
#define SCREEN_H 600
#define FPS 60
// SNAIL
#define MAX_LIFE 3
// ENEMY COUNT
#define CANT_SALEROS 3
#define CANT_TORTUGAS 2
// SCENE MANAGER
#define MENU_SCENE 0
#define CREDITS_SCENE 1
#define GAME_SCENE 2
#define GAME_OVER_SCENE 3
// ENEMY SCORES
#define SCORE_TORTUGA 200
#define SCORE_HORMIGA 100
#define SCORE_SAL 75
// TAGS
enum OBJECT_TAG { PLAYER, ENEMY, BULLET };

extern int gameScore;

#endif // ! RESOURCES_H