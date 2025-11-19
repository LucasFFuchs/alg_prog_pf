#include "raylib.h"
#include "projectile.h"
#include "game.h"

void InitProjectile(PROJECTILE *pj, PROJECTILE list_projectile[], PLAYER p){
    int flag = 0;
    pj -> is_active = true;
    pj -> speed = 400;
    pj -> sprite = LoadTexture("images/projectile.png");
    pj -> posy = p.posy - 30;
    pj -> posx = p.posx + 20 - (pj -> sprite).width/2;
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active == false && flag == 0){
            list_projectile[i] = *pj;
            flag++;
        }
    }
}

void RemoveProjectile(PROJECTILE list_projectile[]){
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].posy <= -list_projectile[i].sprite.height){
            list_projectile[i].is_active = false;
        }

    }
}

void DrawProjectile(PROJECTILE *pj){
    Vector2 pos = { pj -> posx, pj -> posy };
    DrawTextureEx(pj -> sprite, pos, 0, 1, WHITE);
}

void UpdateProjectile(PROJECTILE *pj){
    float dt = GetFrameTime();
    pj -> posy -= pj -> speed  * dt;

}

