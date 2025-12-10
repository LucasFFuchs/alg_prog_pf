#include "raylib.h"
#include <string.h>
#include "../include/button.h"
#include "../include/menu.h"

BUTTON InitButton(int posx, int posy, int font_size, char text[], int option, Color cor){
    BUTTON b;

    b.posx = posx;
    b.posy = posy;
    b.font_size = font_size;
    b.width = MeasureText(text, font_size);
    b.height = font_size;
    b.color = cor;
    strcpy(b.text, text);
    b.option = option;
    b.hover = false;

    return b;
}

void LoadButtons(BUTTON lista_botoes[]){
    int x = 250, size = 70;
    lista_botoes[0] = InitButton(x, 150, size, "Novo Jogo", 1, YELLOW);
    lista_botoes[1] = InitButton(x, 300, size, "Carregar Jogo", 1, YELLOW);
    lista_botoes[2] = InitButton(x, 450, size, "Ranking", 1, YELLOW);
    lista_botoes[3] = InitButton(x, 600, size, "Sair", 4, YELLOW);
}

void DrawButton(BUTTON b){
    DrawText(TextFormat("%s", b.text), b.posx, b.posy, b.font_size, b.color);
}

void UpdateButton(Color mudar_cor, BUTTON *b){
    b -> color = mudar_cor;
}

bool SelectedButton(BUTTON *b, Color cor, Color cor_antiga){
    bool retorno = false;
    Vector2 pos;
    Rectangle rect;
    pos = GetMousePosition();


    rect = (Rectangle){b -> posx,
                       b -> posy,
                       b -> width,
                       b -> height};

    if(CheckCollisionPointRec(pos, rect)){
        UpdateButton(cor, b);
        b -> hover = true;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            retorno = true;
            game_estate = b  -> option;
        }
    }
    else if(b -> hover){
        UpdateButton(cor_antiga, b);
        b -> hover = false;
    }
    return retorno;
}











