#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "raylib.h"

typedef struct {
    float posx, posy;
    int points, speed;
    bool is_active;
    char tipo;

    Texture2D sprite;

}ENEMY;

void InitEnemy();

void DrawEnemy();

void UpdateEnemy();

#endif // ENEMY_H_INCLUDED
