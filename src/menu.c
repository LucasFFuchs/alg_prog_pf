#include "raylib.h"
#include "../include/menu.h"
#include "../include/button.h"


// -> o arquivo menu.c gerencia toda a parte de interface inicial do jogo.
// aqui nasce o primeiro contato do jogador com River Raid: a tela inicial
// e o menu de botoes.
// menu.c desenha o fundo, o titulo, os botoes e controla a selecao deles.
// ele nao possui logica de jogo, apenas a navegacao antes da gameplay.


// cor de fundo padrão usada nas telas de menu
Color menu_color = {37, 150, 190, 255};

// vetor que armazena os botoes que aparecem no menu principal
BUTTON lista_botoes[4] = {0};


// HomeScreen -> desenha a primeira tela exibida ao abrir o jogo
// eh apenas uma tela estaticas com titulo e instrucoes

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
    DrawButton(lista_botoes); // desenha todos os botoes do menu (novo jogo, sair, etc)

    EndDrawing();
}


// UpdateMenu -> atualiza o estado do menu
// controla qual botao esta selecionado pelo jogador
void UpdateMenu(){
    SelectedButton(lista_botoes);
}
