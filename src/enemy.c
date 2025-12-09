#include "raylib.h"
#include "../include/enemy.h"
#include "../include/game.h"


// -> o arquivo enemy.c gerencia o sistema de inimigos do jogo
// aqui nasce o "desafio" do jogo -> os inimigos que devemos eliminar
// enemy.c carrega sprites e faz a animacao dos helicopteros


   // ENEMY lista_enemy... eh o vetor global que armazena tds inimigos ativos ou nn
   // MAXENEMY eh definido no header enemy.h.

ENEMY lista_enemy[MAXENEMY] = {0};

// essa eh a lista com sprites usado pelos enemys
// os inimigos (alguns) alternam entre sprites para criar uma animacao simples

Texture2D lista_sprite_enemy[MAX_ENEMY_SPRTES] = {0};

// abaixo eh possivel ver um contador que usamos pra trocar o sprite da animacao dos helicopteros

int cont = 0;

// funçao que carrega na memoria as imagens usadas pelos inimigos


void InitSpriteEnemy(){
    lista_sprite_enemy[0] = LoadTexture("images/navio.png");
    lista_sprite_enemy[1] = LoadTexture("images/heli1.png");
    lista_sprite_enemy[2] = LoadTexture("images/heli2.png");
}

void InitEnemy(float x, float y, char t){
    for (int i = 0; i < MAXENEMY; i++){

            // o for serve pra procurar o primeiro slot inativo pra criar um novo inimigo

        if(!lista_enemy[i].is_active){
            lista_enemy[i].is_active = true;
            lista_enemy[i].posx = x;
            lista_enemy[i].posy = y;
            lista_enemy[i].tipo = t;
            lista_enemy[i].speed = 200;
            if(t == 'N'){
                // define os pontos e sprite inicial baseado no tipo

                lista_enemy[i].list_index = 0;
                lista_enemy[i].points = 30;
            }
            else{
                lista_enemy[i].points = 60;
                lista_enemy[i].list_index = 1;
            }
            lista_enemy[i].sprite = lista_sprite_enemy[lista_enemy[i].list_index];

            lista_enemy[i].hitbox.x = lista_enemy[i].posx;
            lista_enemy[i].hitbox.y = lista_enemy[i].posy;
            lista_enemy[i].hitbox.height = lista_enemy[i].sprite.height;
            lista_enemy[i].hitbox.width = lista_enemy[i].sprite.width;

            break; // se criou um inimigo -> break -> saimos do loop com sucesso
        }
    }
}

// uma vez criado o inimigo, podemos desenhar ele na tela. segue a funcao para isto logo abaixo

void DrawEnemy(){
    for(int i = 0; i < MAXENEMY; i++){
        if(lista_enemy[i].is_active){
            Vector2 pos = { lista_enemy[i].posx, lista_enemy[i].posy};
            DrawTextureEx(lista_enemy[i].sprite, pos, 0, 1, WHITE);
        }

    }

}

// passo final de enemy.c -> uma vez criado o inimigo e desenhado no mapa, precisamos atualizar o inimigo
// os helicopteros ('X') variam entre 2 sprites pra simular uma animacao
// a troca ocorre a cada 2 frames e esta relacionado ao contador "cont"

void UpdateEnemy(){
    cont++;
    if(cont >= 2){
        for(int i = 0; i < MAXENEMY; i++){

                // aqui estabelece que a atualizacao eh apenas para inimigos ativos e do tipo helicoptero
            if(lista_enemy[i].is_active && lista_enemy[i].tipo == 'X'){

                // alterna os dois sprites do inimigo
                if(lista_enemy[i].list_index == 1)
                    lista_enemy[i].list_index = 2;
                else
                    lista_enemy[i].list_index = 1;

        // por fim, atualiza o sprite atual
                lista_enemy[i].sprite = lista_sprite_enemy[lista_enemy[i].list_index];
                cont = 0;
            }
        }
    }
}
