#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "raylib.h"

typedef struct {
    float posx, posy;
    int pontos;
    bool is_active;
    Texture2D sprite;

}ENEMY;


#endif // ENEMY_H_INCLUDED
