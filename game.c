#include "game.h"
#include "player.h"
#include "raylib.h"

#define SCREEN_WIDTH 24
#define SCREEN_HEIGHT 21
#define TAM 40

PLAYER jogador;


void InicializaTudo(){
    InitWindow(SCREEN_WIDTH * TAM, SCREEN_HEIGHT * TAM, "River Raid");
    SetTargetFPS(60);

    InitPlayer(&jogador);
}

void DesenhaTudo(){
    BeginDrawing();

    ClearBackground(RAYWHITE);

    UpdatePlayer(&jogador);
    DrawPlayer(jogador);


    EndDrawing();
}
