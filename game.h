#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "projectile.h"
#define MAXPROJECTILE 5


extern PROJECTILE list_projectile[MAXPROJECTILE];


void InitGame();

void DrawGame();

void UpdateGame();




#endif // GAME_H_INCLUDED
