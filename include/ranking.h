#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED
#include "raylib.h"
#define MAX_LETRAS_NOME 30
#define MAX_JOGOS_SALVOS 10

typedef struct {
    char nome[MAX_LETRAS_NOME];
    int points, restart;
}RANKING;

extern RANKING lista_ranking[MAX_JOGOS_SALVOS];
extern int arq_cont;

void DrawRanking();

void LoadList();

int NumberOfGames();

bool SpaceInRanking(int points);

int PositionInRanking(int points);

void UpdateRankingList();

void WriteScore();

void DrawWriteName();

void DisplayScore();

void CreateArquivo();

#endif // RANKING_H_INCLUDED
