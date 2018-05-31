#include<iostream>
#include<stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "Game.h"

using namespace std;

int main(int argc, char **argv) {
	srand(time(NULL));
	ALLEGRO_BITMAP *laser = NULL;
	Game* game = new Game(800, 600, 60);
	while (!game->IsGameOver()) 
	{
		game->Update();
		game->Draw();

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

		/*if (!canShoot) {
			laserX += 6 * laserDirX;
			laserY += 6 * laserDirY;
		}
		if (laserX > SCREEN_W || laserX < 0 || laserY < 0 || laserY > SCREEN_H) {
			canShoot = true;
		}*/

	}
	al_rest(0.1);
	delete game;
	return 0;
} 