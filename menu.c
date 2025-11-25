#include "raylib.h"
#include "menu.h"
#include "button.h"

Color menu_color = {37, 150, 190, 255};
BUTTON lista_botoes[4] = {0};


void InitMenu(){
    LoadButtons(lista_botoes);
}


void DrawMenu(){
    BeginDrawing();
    ClearBackground(menu_color);
    DrawButton(lista_botoes);

    EndDrawing();
}

void UpdateMenu(){
    SelectedButton(lista_botoes);
}
