#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED
#define MAXMAPS 11
#include <stdio.h>

extern FILE *lista_mapas[MAXMAPS];

void InitMaps();

void DrawMap(FILE* arq_map);

void CloseMaps();
#endif // MAPA_H_INCLUDED
