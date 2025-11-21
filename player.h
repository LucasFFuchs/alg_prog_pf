#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "raylib.h"

typedef struct {
    float posx, posy;
    float speed;

    Texture2D sprite;

}PLAYER;

void InitPlayer(PLAYER *p);

void DrawPlayer(PLAYER p);

void UpdatePlayer(PLAYER *P);




#endif // PLAYER_H_INCLUDED
