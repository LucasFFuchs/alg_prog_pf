#include "raylib.h"
#include "projectile.h"
#include "game.h"
void InitProjectileConstant(){
    for(int i = 0; i < MAXPROJECTILE; i++){
        list_projectile[i].sprite = LoadTexture("images/projectile.png");
        list_projectile[i].speed = 400;
    }

}
void InitProjectile(float x, float y){
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active == false){
            list_projectile[i].is_active = true;
            list_projectile[i].posy = y - 30;
            list_projectile[i].posx = x + 20 - (list_projectile[i].sprite).width/2;

            list_projectile[i].hitbox.x = list_projectile[i].posx;
            list_projectile[i].hitbox.y = list_projectile[i].posy;
            list_projectile[i].hitbox.width = list_projectile[i].sprite.width;
            list_projectile[i].hitbox.height = list_projectile[i].sprite.height;
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
            list_projectile[i].hitbox.y = list_projectile[i].posy;
        }
        if(list_projectile[i].posy <= 80 ){
            list_projectile[i].is_active = false;
        }
    }


}

