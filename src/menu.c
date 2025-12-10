#include "raylib.h"
#include "../include/menu.h"
#include "../include/button.h"

// cor de fundo padrão usada nas telas de menu
Color menu_color = {37, 150, 190, 255};
BUTTON lista_botoes[MAXBUTTON] = {0};

void HomeScreen(){
    int size = 100, posy = 300;

     // desenha o titulo "River Raid" centralizado
    BeginDrawing();
    ClearBackground(menu_color);
    DrawText("River Raid", SCREEN_WIDTH / 2 - MeasureText("River Raid", size) / 2, posy, size, YELLOW);
    // desenha instrucoes para comecar o jogo
    DrawText("Pressione Enter para iniciar", SCREEN_WIDTH / 2 - MeasureText("Pressione Enter para iniciar", size - 55) / 2, posy + 110, size - 55, YELLOW);


    EndDrawing();
}


// InitMenu -> inicializa os botoes chamando a funcao de button.c
// aqui so delegamos a responsabilidade para outro modulo
void InitMenu(){
    LoadButtons(lista_botoes);
}

 // DrawMenu -> desenha o menu principal com fundo + botoes
void DrawMenu(){
    BeginDrawing();
    ClearBackground(menu_color);
    for(int i = 0; i < MAXBUTTON; i++)
        DrawButton(lista_botoes[i]); // desenha todos os botoes do menu (novo jogo, sair, etc)
    EndDrawing();
}

// UpdateMenu -> atualiza o estado do menu
// controla qual botao esta selecionado pelo jogador
void UpdateMenu(){
    for(int i  = 0; i < MAXBUTTON; i++)
        SelectedButton(&lista_botoes[i], GOLD, YELLOW);
}
