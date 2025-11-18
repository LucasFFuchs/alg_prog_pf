#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include "player.h"

typedef struct {
    bool is_active;
    float posx, posy;
    float speed;
    Texture2D sprite;
}PROJECTILE;

void DrawProjectile(PLAYER p, PROJECTILE *pj);

void UpdateProjectile(PROJECTILE *pj);


#endif // PROJECTILE_H_INCLUDED
