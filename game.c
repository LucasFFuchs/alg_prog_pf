#include "game.h"
#include "player.h"
#include "projectile.h"
#include "raylib.h"

#define SCREEN_WIDTH 24
#define SCREEN_HEIGHT 21
#define TAM 40

PLAYER jogador;
PROJECTILE pj;
PROJECTILE list_projectile[20];
Color background_color = { 45, 50, 184, 255 };



void InitGame(){
    InitWindow(SCREEN_WIDTH * TAM, SCREEN_HEIGHT * TAM, "River Raid");
    SetTargetFPS(60);

    InitPlayer(&jogador);



}

void DrawGame(){

    BeginDrawing();

    ClearBackground(background_color);
    DrawPlayer(jogador);

    if(IsKeyDown(KEY_SPACE))
        DrawProjectile(jogador, &pj);

    EndDrawing();
}

void UpdateGame(){
    UpdatePlayer(&jogador);
    UpdateProjectile(&pj);

}
