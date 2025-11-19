#include "game.h"
#include "player.h"
#include "projectile.h"
#include "raylib.h"

#define SCREEN_WIDTH 24
#define SCREEN_HEIGHT 21
#define TAM 40



PLAYER jogador;
PROJECTILE pj;
Color background_color = { 45, 50, 184, 255 };
PROJECTILE list_projectile[MAXPROJECTILE] = {0};


void InitGame(){

    InitWindow(SCREEN_WIDTH * TAM, SCREEN_HEIGHT * TAM, "River Raid");
    SetTargetFPS(60);

    InitPlayer(&jogador);



}

void DrawGame(){

    BeginDrawing();
    ClearBackground(background_color);

    DrawPlayer(jogador);
    DrawProjectile();

    EndDrawing();
}

void UpdateGame(){
    UpdatePlayer(&jogador);
    UpdateProjectile();
}

