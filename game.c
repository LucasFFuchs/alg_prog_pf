#include "game.h"
#include "player.h"
#include "projectile.h"
#include "button.h"
#include "menu.h"
#include "raylib.h"
#include <stdio.h>


#define TAM 40



PLAYER jogador;
PROJECTILE pj;
Color background_color = { 45, 50, 184, 255 };
Color pause_color = {80, 80, 90, 200};
PROJECTILE list_projectile[MAXPROJECTILE] = {0};
int pause = 0;
int game_estate = 0;

void MainCourse(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "River Raid");
    SetTargetFPS(60);

    int controller;
    int past_state;
    int sair = 0;

    while(!WindowShouldClose() && !sair){
        switch (game_estate){
            case 0: controller = 0;
                    if(!controller){
                        InitMenu();
                        controller++;
                        past_state =  game_estate;
                    }

                    DrawMenu();
                    UpdateMenu();
                    break;

            case 1: if(!past_state){
                        InitGame();
                        past_state =  game_estate;
                    }
                    DrawGame();
                    UpdateGame();
                    break;
            case 4:
                sair = 1;
                break;
        }


    }
    CloseWindow();

}


void InitGame(){
    InitPlayer(&jogador);

}

void DrawPause(){
    if(IsKeyPressed(KEY_ENTER))
        pause = !pause;
    if(pause)
        DrawRectangle(50, 90, SCREEN_WIDTH - 100, SCREEN_HEIGHT - 160, pause_color);
}

void DrawGame(){

    BeginDrawing();
    ClearBackground(background_color);

    DrawPlayer(jogador);
    DrawProjectile();
    ShowHud(jogador);
    DrawPause();

    EndDrawing();
}

void UpdateGame(){
    if(!pause){
        UpdatePlayer(&jogador);
        UpdateProjectile();

    }
}
