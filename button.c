#include <string.h>
#include "raylib.h"
#include "button.h"

BUTTON InitButton(int posx, int posy, int font_size, char text[]){
    BUTTON b;

    b.posx = posx;
    b.posy = posy;
    b.font_size = font_size;
    b.width = MeasureText(text, font_size);
    b.height = font_size;
    b.color = "YELLOW";
    strcpy(b.text, text);

    return b;
}

void LoadButtons(BUTTON lista_botoes[]){
    lista_botoes[1] = InitButton(400, 200, 40, "Novo Jogo");
    lista_botoes[2] = InitButton(400, 400, 40, "Carregar Jogo");
    lista_botoes[3] = InitButton(400, 600, 40, "Ranking");
    lista_botoes[4] = InitButton(400, 800, 40, "Sair");
}

void DrawButton(BUTTON lista_botoes[]){
    BUTTON b;
    for(int i = 0; i < 4; i++){
        b = lista_botoes[i];
        DrawText(TextFomat("%s", b.text), b.posx, b.posy, b.font_size, YELLOW);
    }

}

void UpdateButton(Color cor, BUTTON *b){
    b -> color = cor;
}

int SelectedButton(BUTTON lista_botoes[]){
    Vector2 pos;
    Rectangle rect;
    BUTTON b;
    pos = GetMousePosition();

    for(int i = 0; i < 4; i++){
        b = lista_botoes[i];
        rect = {b.posx, b.posy, b.width, b.height};

        if(CheckCollisionPointRec(pos, rect)){
            UpdateColor(&b, GREEN);
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))

        }

    }

}











