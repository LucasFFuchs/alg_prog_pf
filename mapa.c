#include "raylib.h"
#include "mapa.h"
#include "game.h"
#include <stdio.h>

FILE *lista_mapas[11] = {0};

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

void DrawMap(FILE *arq_map){
    char c;
    int x, y;
    Color terrain_color = {96, 158, 49, 255};

    rewind(arq_map);
    x = 0; y = 80;
    while ((c = fgetc(arq_map)) != EOF){
        if(c == 'T'){
            DrawRectangle(x, y, TAM, TAM, terrain_color);
            x += TAM;
        }else if(c == ' '){
            x += TAM;
        }else if(c == 'X' || c == 'N'){
            DrawRectangle(x, y, TAM, TAM, ORANGE);
            x += TAM;
        }else if(c == 'A'){
            DrawRectangle(x, y, TAM, TAM, YELLOW);
            x += TAM;
        }else if(c == '\n'){
            y += TAM;
            x = 0;
        }
    }
}
