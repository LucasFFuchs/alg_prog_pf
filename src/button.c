#include "raylib.h"
#include <string.h>
#include "../include/button.h"
#include "../include/menu.h"

// inicializa um botao com posicao, tamanho da fonte, texto, acao e cor
// o option nos auxilia mostrando o estado do jogo que é ativado ao clicar
BUTTON InitButton(int posx, int posy, int font_size, char text[], int option, Color cor){
    BUTTON b;

    b.posx = posx; // posicao x do botao
    b.posy = posy; // posicao y do botao
    b.font_size = font_size;// tamanho da fonte
    b.width = MeasureText(text, font_size);// largura do texto
    b.height = font_size;// altura
    b.color = cor;// cor inicial
    strcpy(b.text, text);// faz a  copia do texto do botao
    b.option = option;// guarda qual estado do menu eh ativado
    b.hover = false;// indica se o cursor esta sobre o botao

    return b;
}

// nesta funcao criamos os botoes que fazem parte da tela inicial do jogo
void LoadButtons(BUTTON lista_botoes[]){
    int x = 200, size = 110;
    lista_botoes[0] = InitButton(x, 150, size, "Novo Jogo", 1, YELLOW);
    lista_botoes[1] = InitButton(x, 350, size, "Ranking", 2, YELLOW);
    lista_botoes[2] = InitButton(x, 550, size, "Sair", 4, YELLOW);
}

// aqui vem o desenho dos botoes do jogs (botoes esses criados no bloco anterior de codigo)
void DrawButton(BUTTON b){
    DrawText(TextFormat("%s", b.text), b.posx, b.posy, b.font_size, b.color);
}

void UpdateButton(Color mudar_cor, BUTTON *b){//Muda a cor do botao, para ficar mais legal, apenas muda quando mouse esta em cima do botao
    b -> color = mudar_cor;
}

// aqui faz a verificacao se o mouse passou por cima ou clicou nos botoes
// quando o mouse esta por cima, ele troca a cor e marca hover como true
// se clica, ele altera o estado do jogo (game_estate)
bool SelectedButton(BUTTON *b, Color cor, Color cor_antiga){
    bool retorno = false;
    Vector2 pos;
    Rectangle rect;
    pos = GetMousePosition();

    // area clicavel do botao -> com base no tamanho do texto e posicao
    rect = (Rectangle){b -> posx,
                       b -> posy,
                       b -> width,
                       b -> height};

    // caso o mouse esteja sobre o botao
    if(CheckCollisionPointRec(pos, rect)){
        UpdateButton(cor, b);
        b -> hover = true;
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            retorno = true;
            game_estate = b  -> option;
        }
    }
    else if(b -> hover){
        // se saiu de cima do botao, volta a cor inicial
        UpdateButton(cor_antiga, b);
        b -> hover = false;
    }
    return retorno;
}











