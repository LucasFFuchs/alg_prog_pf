#include "raylib.h"
#include "../include/menu.h"
#include "../include/button.h"

Color menu_color = {37, 150, 190, 255};
BUTTON lista_botoes[MAXBUTTON] = {0};

void HomeScreen(){
    int size = 100, posy = 300;

    BeginDrawing();
    ClearBackground(menu_color);
    DrawText("River Raid", SCREEN_WIDTH / 2 - MeasureText("River Raid", size) / 2, posy, size, YELLOW);
    DrawText("Pressione Enter para iniciar", SCREEN_WIDTH / 2 - MeasureText("Pressione Enter para iniciar", size - 55) / 2, posy + 110, size - 55, YELLOW);


    EndDrawing();
}



void InitMenu(){
    LoadButtons(lista_botoes);
}


void DrawMenu(){
    BeginDrawing();
    ClearBackground(menu_color);
    for(int i = 0; i < MAXBUTTON; i++)
        DrawButton(lista_botoes[i]);
    EndDrawing();
}

void UpdateMenu(){
    for(int i  = 0; i < MAXBUTTON; i++)
        SelectedButton(&lista_botoes[i], GOLD, YELLOW);
}
