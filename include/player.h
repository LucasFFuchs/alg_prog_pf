#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "raylib.h"

#define INITIAL_SPEED_Y 120
#define INITIAL_SPEED_X 400

typedef struct {
    float posx, posy;
    float speed_x, speed_y;
    float fuel_quantity;
    int lives, points, level;

    Rectangle hitbox;
    Texture2D sprite;

}PLAYER;

void InitPlayer(PLAYER *p, PLAYER *backup);

void ShowHud(PLAYER p);

void DrawPlayer(PLAYER p);

void UpdatePlayer(PLAYER *P, float dt);




#endif // PLAYER_H_INCLUDED
