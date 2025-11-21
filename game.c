#include "game.h"
#include "player.h"
#include "projectile.h"
#include "stats.h"
#include "raylib.h"


#define TAM 40



PLAYER jogador;
PROJECTILE pj;
Color background_color = { 45, 50, 184, 255 };
Color pause_color = {80, 80, 90, 200};
PROJECTILE list_projectile[MAXPROJECTILE] = {0};
int pause = 0;
STATS s;


void InitGame(){


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "River Raid");
    SetTargetFPS(60);

    InitPlayer(&jogador);
    InitStats(&s);



}

void DrawGame(){

    BeginDrawing();


    ClearBackground(background_color);

    DrawPlayer(jogador);
    DrawProjectile();
    ShowHud(s);

    if(pause)
        DrawRectangle(50, 90, SCREEN_WIDTH - 100, SCREEN_HEIGHT - 160, pause_color);


    EndDrawing();
}

void UpdateGame(){
    if(!pause){
        UpdatePlayer(&jogador);
        UpdateProjectile();

    }
}

