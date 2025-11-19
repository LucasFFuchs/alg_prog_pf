#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include "player.h"



typedef struct {
    bool is_active;
    float posx, posy;
    float speed;
    Texture2D sprite;
}PROJECTILE;

void InitProjectile(PROJECTILE *pj,PROJECTILE list_projectile[], PLAYER p);

void RemoveProjectile(PROJECTILE list_projectile[]);

void DrawProjectile(PROJECTILE *pj);

void UpdateProjectile(PROJECTILE *pj);


#endif // PROJECTILE_H_INCLUDED
