#include "enemy.h"
#include "game.h"
#include "raylib.h"

#include <stdio.h>

ENEMY lista_enemy[MAXENEMY] = {0};
Texture2D lista_sprite_enemy[MAX_ENEMY_SPRTES] = {0};
int cont = 0;

void InitSpriteEnemy(){
    lista_sprite_enemy[0] = LoadTexture("images/navio.png");
    lista_sprite_enemy[1] = LoadTexture("images/heli1.png");
    lista_sprite_enemy[2] = LoadTexture("images/heli2.png");
}

void InitEnemy(float x, float y, char t){
    for (int i = 0; i < MAXENEMY; i++){
        if(!lista_enemy[i].is_active){
            lista_enemy[i].is_active = true;
            lista_enemy[i].posx = x;
            lista_enemy[i].posy = y;
            lista_enemy[i].tipo = t;
            lista_enemy[i].speed = 200;
            if(t == 'N'){
                lista_enemy[i].list_index = 0;
                lista_enemy[i].points = 30;
            }
            else{
                lista_enemy[i].points = 60;
                lista_enemy[i].list_index = 1;
            }
            lista_enemy[i].sprite = lista_sprite_enemy[lista_enemy[i].list_index];
            break;
        }
    }
}

void DrawEnemy(){
    for(int i = 0; i < MAXENEMY; i++){
        if(lista_enemy[i].is_active){
            Vector2 pos = { lista_enemy[i].posx, lista_enemy[i].posy};
            DrawTextureEx(lista_enemy[i].sprite, pos, 0, 1, WHITE);
        }

    }

}
void UpdateEnemy(){
    cont++;
    if(cont >= 2){
        for(int i = 0; i < MAXENEMY; i++){
            if(lista_enemy[i].is_active && lista_enemy[i].tipo == 'X'){
                if(lista_enemy[i].list_index == 1)
                    lista_enemy[i].list_index = 2;
                else
                    lista_enemy[i].list_index = 1;
                lista_enemy[i].sprite = lista_sprite_enemy[lista_enemy[i].list_index];
                cont = 0;
            }
        }
    }
}
