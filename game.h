#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "projectile.h"
#include "button.h"

#define MAXPROJECTILE 8
#define SCREEN_WIDTH 24 * 40
#define SCREEN_HEIGHT 22 * 40

extern int pause;
extern PROJECTILE list_projectile[MAXPROJECTILE];
//extern BUTTON lista_botoes[4];

void MainCourse();

void DrawPause();

void InitGame();

void DrawGame();

void UpdateGame();


#endif // GAME_H_INCLUDED
