#include "raylib.h"
#include "../include/fuel.h"
#include "../include/game.h"

FUEL lista_fuel[MAXFUEL] = {0};
int fuel_loss = 10;
int fuel_gain = 30;

void InitFuelSprite(){
    Texture2D sprite = LoadTexture("images/fuel.png");
    for(int i = 0; i < MAXFUEL; i++)
        lista_fuel[i].sprite = sprite;
}

void InitFuel(int x, int y){
    for(int i = 0; i < MAXFUEL; i++){
        if(!lista_fuel[i].is_active){
            lista_fuel[i].is_active = true;
            lista_fuel[i].posx = x;
            lista_fuel[i].posy = y;
            lista_fuel[i].give_fuel = true;

            lista_fuel[i].hitbox.x = lista_fuel[i].posx;
            lista_fuel[i].hitbox.y = lista_fuel[i].posy;
            lista_fuel[i].hitbox.width = lista_fuel[i].sprite.width;
            lista_fuel[i].hitbox.height = lista_fuel[i].sprite.height;
            break;
        }
    }
}

void DrawFuel(){
    for(int i = 0; i < MAXFUEL; i++){
        if(lista_fuel[i].is_active){
            Vector2 pos = { lista_fuel[i].posx, lista_fuel[i].posy};
            DrawTextureEx(lista_fuel[i].sprite, pos, 0, 1, WHITE);
        }
    }
}

void UpdateFuel(PLAYER *p, float old_y){
    float deltay;

    if(p -> posy > HUD_HEIGHT && p -> posy < SCREEN_HEIGHT)
        deltay = old_y - p -> posy;
        p -> fuel_quantity -= deltay / ((SCREEN_HEIGHT - HUD_HEIGHT) / fuel_loss) ;

    for(int i = 0; i < MAXFUEL; i++){
        if(lista_fuel[i].is_active && lista_fuel[i].give_fuel){
            if(CheckCollisionRecs(lista_fuel[i].hitbox, p -> hitbox)){
                if(IsKeyPressed(KEY_LEFT_SHIFT)){
                    if(p -> fuel_quantity >= 100 - fuel_gain)
                        p -> fuel_quantity = 100;
                    else
                        p -> fuel_quantity += fuel_gain;
                    lista_fuel[i].give_fuel = false;
                }
            }
        }
    }
}

