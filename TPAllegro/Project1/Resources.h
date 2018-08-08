#ifndef  RESOURCES_H
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
#define CANT_SALEROS 3
#define CANT_TORTUGAS 2
#define SCREEN_W 800
#define SCREEN_H 600
#define FPS 60
enum OBJECT_TAG { PLAYER, ENEMY, BULLET };

#endif // ! RESOURCES_H