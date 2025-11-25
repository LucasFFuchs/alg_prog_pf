#include <string.h>
#include "raylib.h"
#include "button.h"
#include "menu.h"

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
        DrawText(TextFormat("%s", b.text), b.posx, b.posy, b.font_size, YELLOW);
    }

}

void UpdateButton(Color cor, BUTTON *b){
    b -> color = cor;
}

void SelectedButton(BUTTON lista_botoes[]){
    Vector2 pos;
    Rectangle rect;
    BUTTON b;
    pos = GetMousePosition();

    for(int i = 0; i < 4; i++){
        rect = (Rectangle){lista_botoes[i].posx,
                           lista_botoes[i].posy,
                           lista_botoes[i].width,
                           lista_botoes[i].height};

        if(CheckCollisionPointRec(pos, rect)){
            UpdateButton(GREEN, &lista_botoes[i]);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                game_estate = lista_botoes[i].option;
        }

    }

}











