#include "raylib.h"
#include "stats.h"
#include "game.h"

void InitStats(STATS *s){
    s -> points = 0;
    s -> level = 1;
    s -> fuel_quantity = 100;
    s -> lives = 3;
}

void ShowHud(STATS s){
    DrawRectangle(0, 0, SCREEN_WIDTH, 80, GRAY);
    DrawText(TextFormat("Pontos: %d", s.points), 30, 25, 35, BLACK);
    DrawText(TextFormat("Nivel: %d", s.level), 260, 25, 35, BLACK);
    DrawText(TextFormat("Vidas: %d", s.lives), 440, 25, 35, BLACK);
    DrawText(TextFormat("Gasolina: %d", s.fuel_quantity), 650, 25, 35, BLACK);


}
