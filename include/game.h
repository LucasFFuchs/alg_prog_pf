#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "../include/projectile.h"
#include "../include/button.h"
#include "../include/enemy.h"
#include "../include/mapa.h"
#include "../include/fuel.h"
#include "utils.h"
#include <stdio.h>

#define MAXPROJECTILE 8
#define MAXENEMY 10
#define MAX_ENEMY_SPRITES 3
#define MAXFUEL 2

#define LINHA 20
#define COLUNA 24
#define HUD_HEIGHT 80

#define SCREEN_WIDTH COLUNA * 40
#define SCREEN_HEIGHT (LINHA + (HUD_HEIGHT/40)) * 40
#define TAM 40

#define SPEED_Y_INCREMENT 5

extern int pause, game_over, game_win;
extern PLAYER jogador, backup;
extern PROJECTILE list_projectile[MAXPROJECTILE];
extern ENEMY lista_enemy[MAXENEMY];
extern Texture2D lista_sprite_enemy[MAX_ENEMY_SPRITES];
extern FUEL lista_fuel[MAXFUEL];
extern int restart_cont;
extern int jogou;



void RunGame();

void InitGame();
void DrawGame();
void UpdateGame();

void CheckAllCollision();
int CheckTerrainPlayer(int tipoMov, float old_x, float old_y);

#endif // GAME_H_INCLUDED
