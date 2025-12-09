#include "raylib.h"
#include "../include/projectile.h"
#include "../include/game.h"

// -> o arquivo projectile.c gerencia o sistema de projeteis do jogador.
// aqui nasce o tiro disparado pelo player, incluindo posicao, movimento
// e desenho na tela.

// projectile.c carrega o sprite dos projeteis, ativa novos tiros quando
// o jogador atira, atualiza o movimento deles e desativa quando saem da tela.

// ele eh essencial para o combate do jogo e trabalha junto com o modulo player.


void InitProjectileConstant(){
    for(int i = 0; i < MAXPROJECTILE; i++){
        list_projectile[i].sprite = LoadTexture("images/projectile.png");
        list_projectile[i].speed = 400;
    }

}

// InitProjectile -> ativa um novo projetil na posicao do jogador
// x e y representam a posicao atual da nave do player
// procura o primeiro espaco livre no vetor list_projectile

void InitProjectile(float x, float y){
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active == false){
            list_projectile[i].is_active = true;

            list_projectile[i].posy = y - 30;   // projeteis nascem um pouco acima do player (y - 30)

            list_projectile[i].posx = x + 20 - (list_projectile[i].sprite).width/2;  // centraliza o tiro no meio da nave

            // atualiza hitbox baseado na posicao inicial
            list_projectile[i].hitbox.x = list_projectile[i].posx;
            list_projectile[i].hitbox.y = list_projectile[i].posy;
            list_projectile[i].hitbox.width = list_projectile[i].sprite.width;
            list_projectile[i].hitbox.height = list_projectile[i].sprite.height;
            break; // apos criar um tiro, sair do loop
        }
    }
}

// DrawProjectile -> desenha todos os projeteis ativos na tela
void DrawProjectile(){
    for(int i = 0; i < MAXPROJECTILE; i++)
        if(list_projectile[i].is_active){
            Vector2 pos = { list_projectile[i].posx, list_projectile[i].posy };
            DrawTextureEx(list_projectile[i].sprite, pos, 0, 1, WHITE);
        };
}


// UpdateProjectile -> atualiza o movimento dos tiros a cada frame
// dt = delta time (tempo entre frames), usado para movimento suave
//
// o projetil se move para cima: posy -= speed * dt
// se o tiro ultrapassa o topo da tela, eh desativado

void UpdateProjectile(float dt){
    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active){
            list_projectile[i].posy -= list_projectile[i].speed  * dt;  // move o projetil verticalmente para cima
            list_projectile[i].hitbox.y = list_projectile[i].posy; // atualiza hitbox junto com a posicao
        }

          // desativa tiro que saiu da tela
        if(list_projectile[i].posy <= 80 ){
            list_projectile[i].is_active = false;
        }
    }


}

