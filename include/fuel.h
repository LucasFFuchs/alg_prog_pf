#ifndef FUEL_H_INCLUDED
#define FUEL_H_INCLUDED
#include "raylib.h"
#include "player.h"

#define MAP_HEIGHT SCREEN_HEIGHT - HUD_HEIGHT

extern int fuel_loss;
extern int fuel_gain;

typedef struct {
    int posx, posy;
    float segundos;
    bool is_active;
    bool give_fuel;

    Rectangle hitbox;
    Texture2D sprite;
}FUEL;

void InitFuelSprite();

void InitFuel(int x, int y);

void DrawFuel();

void UpdateFuel(PLAYER *p, float old_y);


#endif // FUEL_H_INCLUDED
