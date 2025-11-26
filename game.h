#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "projectile.h"
#include "button.h"
#include "enemy.h"
#include <stdio.h>

#define MAXPROJECTILE 8
#define MAXENEMY 10
#define MAX_ENEMY_SPRTES 3

#define SCREEN_WIDTH 24 * 40
#define SCREEN_HEIGHT 22 * 40
#define TAM 40

extern int pause;
extern PROJECTILE list_projectile[MAXPROJECTILE];
extern ENEMY lista_enemy[MAXENEMY];
extern Texture2D lista_sprite_enemy[MAX_ENEMY_SPRTES];



void MainCourse();

void DrawPause();

void InitGame();

void DrawGame();

void UpdateGame();


#endif // GAME_H_INCLUDED
