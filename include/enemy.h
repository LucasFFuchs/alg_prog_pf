#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED
#include "raylib.h"

typedef struct {
    float posx, posy;
    int points, speed, list_index;
    bool is_active;
    char tipo;

    Rectangle hitbox;
    Texture2D sprite;

}ENEMY;
void InitSpriteEnemy();

void InitEnemy(float x, float y, char t);

void DrawEnemy();

void UpdateEnemy();

#endif // ENEMY_H_INCLUDED
