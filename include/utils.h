#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include "button.h"
#include "game.h"
#include "mapa.h"
#include "raylib.h"

extern Color pause_color;

void DrawPause();
bool GameOver();
void DrawGameOver();
void DrawGameWin();

void DrawBox(char texto[30], char texto_botao[30], int tamanho_fonte, int incremento_y, Color cor, Color cor_hover, int game_estate);

void InitLevel();
bool NextLevel();
void ResetLevel();


#endif // UTILS_H_INCLUDED
