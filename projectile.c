#include "raylib.h"
#include "projectile.h"
#include "game.h"

void InitProjectile(float x, float y){
    PROJECTILE pj;
    pj.is_active = true;
    pj.speed = 400;
    pj.sprite = LoadTexture("images/projectile.png");
    pj.posy = y - 30;
    pj.posx = x + 20 - (pj.sprite).width/2;
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active == false){
            list_projectile[i] = pj;
            break;
        }
    }
}

void DrawProjectile(){
    for(int i = 0; i < MAXPROJECTILE; i++)
        if(list_projectile[i].is_active){
            Vector2 pos = { list_projectile[i].posx, list_projectile[i].posy };
            DrawTextureEx(list_projectile[i].sprite, pos, 0, 1, WHITE);
        };
}

void UpdateProjectile(float dt){
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active){
            list_projectile[i].posy -= list_projectile[i].speed  * dt;
        }
        if(list_projectile[i].posy <= 80 ){
            list_projectile[i].is_active = false;
        }
    }


}

