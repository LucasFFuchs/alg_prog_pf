#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include "raylib.h"


typedef struct {
    int posx, posy;
    int font_size;
    int width, height;
    int option;
    char text[30];
    bool hover;
    Color color;
}BUTTON;

BUTTON InitButton(int posx, int posy, int font_size, char text[], int option);

void LoadButtons(BUTTON lista_botoes[]);

void DrawButton(BUTTON lista_botoes[]);

void UpdateButton(Color mudar_cor, BUTTON *b);

void SelectedButton(BUTTON lista_botoes[]);

#endif // BUTTON_H_INCLUDED
