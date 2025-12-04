#include "raylib.h"
#include "mapa.h"
#include "game.h"
#include <stdio.h>

FILE *lista_mapas[MAXMAPS] = {0};
TILE mapa_atual[LINHA][COLUNA];
int flag = 0;

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

void CloseMaps(){
    for(int i = 0; i < MAXMAPS; i++)
        fclose(lista_mapas[i]);
}

void InitMapMatrix(FILE *arq_map, PLAYER *p){
    char c;
    int linha = 0, coluna = 0;

    while ((c = fgetc(arq_map)) != EOF){
        if(c != '\n'){
            mapa_atual[linha][coluna].posx = coluna * TAM;
            mapa_atual[linha][coluna].posy = TAM * (linha + 2);
            mapa_atual[linha][coluna].tipo = c;

            if(c == 'A'){
                p -> posx = mapa_atual[linha][coluna].posx;
                p -> posy = mapa_atual[linha][coluna].posy;
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
}

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
                case 'A':   if(!flag)

                            break;

            }
        }
    }
    flag++;
}

