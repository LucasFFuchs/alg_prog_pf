#include "raylib.h"
#include <stdio.h>
#include "../include/mapa.h"
#include "../include/game.h"


FILE *lista_mapas[MAXMAPS] = {0};
TILE mapa_atual[LINHA][COLUNA];
int flag;


// InitMaps() -> inicializa todos os arquivos de mapa abrindo cada .txt correspondente.
// cada mapa eh guardado dentro de lista_mapas[].
void InitMaps(){
    lista_mapas[0] = fopen("mapas/fase1.txt", "r");
    lista_mapas[1] = fopen("mapas/fase2.txt", "r");
    lista_mapas[2] = fopen("mapas/fase3.txt", "r");
    lista_mapas[3] = fopen("mapas/fase4.txt", "r");
    lista_mapas[4] = fopen("mapas/fase5.txt", "r");
    lista_mapas[5] = fopen("mapas/fase6.txt", "r");
    lista_mapas[6] = fopen("mapas/fase7.txt", "r");
    lista_mapas[7] = fopen("mapas/fase8.txt", "r");
    lista_mapas[8] = fopen("mapas/fase9.txt", "r");
    lista_mapas[9] = fopen("mapas/fase10.txt", "r");
    lista_mapas[10] = fopen("mapas/corredor.txt", "r");
}

// se InitMaps() inicializa os arquivos, CloseMaps() fecha todos os arquivos de mapa abertos anteriormente
// sera chamado normalmente ao encerrar o jogo
void CloseMaps(){
    for(int i = 0; i < MAXMAPS; i++)
        fclose(lista_mapas[i]);
}

// le um arquivo de mapa (arq_map) e preenche a matriz mapa_atual[][].
//
// cada caractere do arquivo vira um TILE com:
//  - posiçao em pixels (posx, posy)
//  - tipo do tile (T, X, N, A, etc.)
//  - hitbox correspondente
//
// Se o tile for 'A', significa posicao inicial do jogador, entao:
//  - a posicao do PLAYER eh definida aqui
//  - a hitbox do jogador tambem eh atualizada
void InitMapMatrix(FILE *arq_map, PLAYER *p, PLAYER *backup){
    char c;
    int linha = 0, coluna = 0;

    while ((c = fgetc(arq_map)) != EOF){
        if(c != '\n' && c != '\r'){
            // Define posição do tile em pixels
            mapa_atual[linha][coluna].posx = coluna * TAM;
            mapa_atual[linha][coluna].posy = TAM * (linha + (HUD_HEIGHT/TAM));
            mapa_atual[linha][coluna].tipo = c;

             // Define hitbox do tile
            mapa_atual[linha][coluna].hitbox.x = mapa_atual[linha][coluna].posx;
            mapa_atual[linha][coluna].hitbox.y = mapa_atual[linha][coluna].posy;
            mapa_atual[linha][coluna].hitbox.width = TAM;
            mapa_atual[linha][coluna].hitbox.height = TAM;

             // Tile do jogador ('A')
            if(c == 'A'){
                p -> posx = mapa_atual[linha][coluna].posx;
                p -> posy = mapa_atual[linha][coluna].posy;

                // Hitbox do jogador tem tamanho do sprite
                p -> hitbox.y = p -> posy;
                p -> hitbox.x = p -> posx;
                p -> hitbox.height = (p -> sprite).height;
                p -> hitbox.width = (p -> sprite).width;

                *backup = *p;
            }

            if(coluna < COLUNA - 1)
                coluna++;
            else{
                coluna = 0;
                linha++;
            }
        }

    }
    rewind(arq_map);
    flag = 0;

    for(int linha = 0; linha < LINHA; linha++){
        for(int coluna = 0; coluna < COLUNA; coluna++)
            printf("%c", mapa_atual[linha][coluna].tipo);
        printf("\n");
    }
}

// DrawMap() desenha o mapa atual na tela.
//
// pra cada tile, decide o que fazer baseado no tipo:
//   'T' → terreno (retangulo verde)
//   'X', 'N' → inimigos (mas so inicializa na primeira vez)
//   'A' → posicao inicial do jogador (nenhuma acao visual)
//
// Obs: InitEnemy() so roda quando flag == 0.
// Depois aumenta flag, impedindo recriações.


void DrawMap(){
    TILE t;
    Color terrain_color = {96, 158, 49, 255};

    for(int linha = 0; linha < LINHA; linha++){
        for(int coluna = 0; coluna < COLUNA; coluna++){
            t = mapa_atual[linha][coluna];
            switch(t.tipo){
                case 'T':   DrawRectangle(t.posx, t.posy, TAM, TAM, terrain_color);
                            break;
                case 'X':

                case 'N':   if(!flag)
                                InitEnemy(t.posx, t.posy, t.tipo);
                            break;
                case 'G':   if(!flag)
                                InitFuel(t.posx, t.posy);
                            break;
            }
        }
    }
    flag++;// Impede que inimigos e postos de gasolina sejam criados varias vezes
}

