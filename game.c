#include "game.h"
#include "player.h"
#include "projectile.h"
#include "raylib.h"

#define SCREEN_WIDTH 24
#define SCREEN_HEIGHT 21
#define TAM 40

PLAYER jogador;
PROJECTILE pj;
PROJECTILE list_projectile[MAXPROJECTILE] = {0};
Color background_color = { 45, 50, 184, 255 };



void InitGame(){

    InitWindow(SCREEN_WIDTH * TAM, SCREEN_HEIGHT * TAM, "River Raid");
    SetTargetFPS(60);

    InitPlayer(&jogador);



}

void DrawGame(){

    BeginDrawing();
    ClearBackground(background_color);

    if((IsKeyPressed(KEY_SPACE))){
        InitProjectile(&pj, list_projectile, jogador);
    }

    DrawPlayer(jogador);
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active == true){
            DrawProjectile(&list_projectile[i]);
        }

    }


    EndDrawing();
}

void UpdateGame(){
    UpdatePlayer(&jogador);
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active == true)
            UpdateProjectile(&list_projectile[i]);
    }
    RemoveProjectile(list_projectile);
}

