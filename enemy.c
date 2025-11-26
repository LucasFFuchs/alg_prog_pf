#include "enemy.h"
#include "game.h"
#include "raylib.h"

ENEMY lista_enemy = {0};

void InitEnemy(float x, float y, char t){
    ENEMY e;
    for (int i = 0, i < MAXENEMY, i++){
        if(lista_enemy[i].is_active == false)
            e.is_active = true;
            e.posx = x;
            e.posy = y;
            e.tipo = t;
            e.speed = 200
            if(t == 'N'){
                e.sprite LoadTexture("images/navio.png");
                e.points = 30;
            }
            else{
                e.points = 60;
                e.sprite = LoadTexture("images/heli1.png");
            }
            lista_enemy[i] = e;
    }
}

DrawEnemy(){
    for(int i = 0; i < MAXENEMY; i++){
        if(lista_enemy[i].is_active){
            Vector2 pos = { lista_enemy[i].posx, lista_enemy[i].posy};
            DrawTextureEx(lista_enemy.sprite, pos, 0, 1, WHITE);
        }

    }

}
