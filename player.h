#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "raylib.h"

typedef struct {
    float posx, posy;
    float speed;
    int lives, points, level, fuel_quantity;

    Texture2D sprite;

}PLAYER;

void InitPlayer(PLAYER *p);

void ShowHud(PLAYER p);

void DrawPlayer(PLAYER p);

void UpdatePlayer(PLAYER *P, float dt);




#endif // PLAYER_H_INCLUDED
