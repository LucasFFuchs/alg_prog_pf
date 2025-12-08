#include "raylib.h"
#include <string.h>
#include "../include/button.h"
#include "../include/menu.h"

BUTTON InitButton(int posx, int posy, int font_size, char text[], int option){
    BUTTON b;

    b.posx = posx;
    b.posy = posy;
    b.font_size = font_size;
    b.width = MeasureText(text, font_size);
    b.height = font_size;
    b.color = YELLOW;
    strcpy(b.text, text);
    b.option = option;
    b.hover = false;

    return b;
}

void LoadButtons(BUTTON lista_botoes[]){
    int x = 250, size = 70;
    lista_botoes[0] = InitButton(x, 150, size, "Novo Jogo", 1);
    lista_botoes[1] = InitButton(x, 300, size, "Carregar Jogo", 1);
    lista_botoes[2] = InitButton(x, 450, size, "Ranking", 1);
    lista_botoes[3] = InitButton(x, 600, size, "Sair", 4);
}

void DrawButton(BUTTON lista_botoes[]){
    BUTTON b;
    for(int i = 0; i < 4; i++){
        b = lista_botoes[i];
        DrawText(TextFormat("%s", b.text), b.posx, b.posy, b.font_size, b.color);
    }

}

void UpdateButton(Color mudar_cor, BUTTON *b){
    b -> color = mudar_cor;
}

void SelectedButton(BUTTON lista_botoes[]){
    Vector2 pos;
    Rectangle rect;
    pos = GetMousePosition();

    for(int i = 0; i < 4; i++){
        rect = (Rectangle){lista_botoes[i].posx,
                           lista_botoes[i].posy,
                           lista_botoes[i].width,
                           lista_botoes[i].height};

        if(CheckCollisionPointRec(pos, rect)){
            UpdateButton(GOLD, &lista_botoes[i]);
            lista_botoes[i]. hover = true;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                game_estate = lista_botoes[i].option;
        }
        else if(lista_botoes[i].hover){
            UpdateButton(YELLOW, &lista_botoes[i]);
            lista_botoes[i].hover = false;
        }
    }

}











