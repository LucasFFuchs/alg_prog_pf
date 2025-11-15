#include "player.h"
#include "raylib.h"

void InitPlayer(PLAYER *p){
    p -> posy = 300;
    p -> posx = 400;
    p -> speed = 1;
    p -> fuel_quantity = 100;
    p -> teste = 'A';
}

void DrawPlayer(PLAYER p){
    DrawRectangle(p.posx, p.posy, 100, 30, BLUE);
    if(p.teste == 'A')
        DrawText("a" , p.posx + 50, p.posy + 50, 20, BLACK);
}

void UpdatePlayer(PLAYER *p){
    if(p -> posx < 500)
        if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
            p -> posx += 2;

    if(p -> posx > 100)
        if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
            p -> posx -= 2;

}
