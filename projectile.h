#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include "player.h"

typedef struct {
    bool is_active;
    float posx, posy;
    float speed;

    Rectangle hitbox;
    Texture2D sprite;
}PROJECTILE;

void InitProjectileConstant();

void InitProjectile(float x, float y);

void DrawProjectile();

void UpdateProjectile(float dt);


#endif // PROJECTILE_H_INCLUDED
