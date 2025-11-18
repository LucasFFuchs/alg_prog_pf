#include "raylib.h"
#include "projectile.h"


void DrawProjectile(PLAYER p, PROJECTILE *pj){
    pj -> speed = 400;
    pj -> sprite = LoadTexture("images/projectile.png");
    pj -> posy = p.posy - 30;
    pj -> posx = p.posx + 20 - (pj -> sprite).width/2;

    Vector2 pos = { pj -> posx, pj -> posy };
    DrawTextureEx(pj -> sprite, pos, 0, 1, WHITE);
}

void UpdateProjectile(PROJECTILE *pj){
    float dt = GetFrameTime();
    pj -> posy += pj -> speed  * dt;

}

void(PROJETILE list[], ){
    for(int i = 0; i < 20 ; i++){
        if (list[i].is_active == false){
            list[i]
        }
    }
}
