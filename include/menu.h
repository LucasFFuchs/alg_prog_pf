#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "game.h"
#define MAXBUTTON 3

extern int game_estate;
extern BUTTON lista_botoes[MAXBUTTON];

void HomeScreen();

void InitMenu();

void DrawMenu();

void UpdateMenu();

#endif // MENU_H_INCLUDED
