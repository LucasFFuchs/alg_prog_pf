#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#define MAXMAPS 11
#include <stdio.h>
#include "player.h"

#define LINHA 20
#define COLUNA 24

typedef struct{
    int posx, posy;
    char tipo;
}TILE;

extern FILE *lista_mapas[MAXMAPS];
extern TILE mapa_atual[20][24];



void InitMaps();

void InitMapMatrix(FILE *arq_map, PLAYER *p);

void DrawMap();

void CloseMaps();
#endif // MAPA_H_INCLUDED
