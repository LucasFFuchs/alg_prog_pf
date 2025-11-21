#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "projectile.h"
#define MAXPROJECTILE 8
#define SCREEN_WIDTH 24 * 40
#define SCREEN_HEIGHT 22 * 40

extern int pause;
extern PROJECTILE list_projectile[MAXPROJECTILE];


void InitGame();

void DrawGame();

void UpdateGame();

void ShowHud();



#endif // GAME_H_INCLUDED
