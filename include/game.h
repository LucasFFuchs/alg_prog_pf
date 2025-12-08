#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "projectile.h"
#include "button.h"
#include "enemy.h"
#include "mapa.h"
#include <stdio.h>

#define MAXPROJECTILE 8
#define MAXENEMY 10
#define MAX_ENEMY_SPRTES 3

#define LINHA 20
#define COLUNA 24

#define SCREEN_WIDTH COLUNA * 40
#define SCREEN_HEIGHT (LINHA + 2) * 40
#define TAM 40

extern int pause;
extern PROJECTILE list_projectile[MAXPROJECTILE];
extern ENEMY lista_enemy[MAXENEMY];
extern Texture2D lista_sprite_enemy[MAX_ENEMY_SPRTES];



void RunGame();

void DrawPause();

void InitGame();

void DrawGame();

void UpdateGame();

void CheckAllCollision();

int CheckTerrainPlayer(int tipoMov, float old_x, float old_y);

/*int CheckTerrainPlayerDirection(TILE t);*/

#endif // GAME_H_INCLUDED
