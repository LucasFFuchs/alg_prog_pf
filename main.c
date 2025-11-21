#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "game.h"
#include "raylib.h"

extern PLAYER jogador;


int main()
{
    InitGame();

    while (!WindowShouldClose()) {
        DrawGame();
        UpdateGame();

    }

    UnloadTexture(jogador.sprite);

    CloseWindow();
}
