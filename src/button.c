#include "raylib.h"
#include <string.h>
#include "../include/button.h"
#include "../include/menu.h"

// inicializa um botao com posicao tamanho da fonte texto e acao
// o option nos auxilia mostrando o estado do jogo que é ativado ao clicar

BUTTON InitButton(int posx, int posy, int font_size, char text[], int option){
    BUTTON b;

    b.posx = posx; // posicao x do botao
    b.posy = posy; // posicao y do botao
    b.font_size = font_size; // tamanho da fonte
    b.width = MeasureText(text, font_size); // largura do texto
    b.height = font_size; // altura
    b.color = YELLOW; // cor inicial
    strcpy(b.text, text); // faz a  copia do texto do botao
    b.option = option; // guarda qual estado do menu eh ativado
    b.hover = false; // indica se o cursor esta sobre o botao

    return b;
}

// neste bloco criamos os botoes que fazem parte da tela inicial do jogo

void LoadButtons(BUTTON lista_botoes[]){
    int x = 250, size = 70;
    lista_botoes[0] = InitButton(x, 150, size, "Novo Jogo", 1);
    lista_botoes[1] = InitButton(x, 300, size, "Carregar Jogo", 1);
    lista_botoes[2] = InitButton(x, 450, size, "Ranking", 1);
    lista_botoes[3] = InitButton(x, 600, size, "Sair", 4);
}

// aqui vem o desenho dos botoes do jogs (botoes esses criados no bloco anterior de codigo)

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

// aqui faz a verificacao se o mouse passou por cima ou clicou nos botoes
// quando o mouse esta por cima, ele troca a cor e marca hover como true
// se clica, ele altera o estado do jogo (game_estate)

void SelectedButton(BUTTON lista_botoes[]){
    Vector2 pos;
    Rectangle rect;
    pos = GetMousePosition();

    // area clicavel do botao -> com base no tamanho do texto e posicao

    for(int i = 0; i < 4; i++){
        rect = (Rectangle){lista_botoes[i].posx,
                           lista_botoes[i].posy,
                           lista_botoes[i].width,
                           lista_botoes[i].height};

     // caso o mouse esteja sobre o botao

        if(CheckCollisionPointRec(pos, rect)){
            UpdateButton(GOLD, &lista_botoes[i]);
            lista_botoes[i]. hover = true;
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                game_estate = lista_botoes[i].option;
        }
        else if(lista_botoes[i].hover){

                // se saiu de cima do botao, volta ao normal

            UpdateButton(YELLOW, &lista_botoes[i]);
            lista_botoes[i].hover = false;
        }
    }

}











