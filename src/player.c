#include "raylib.h"
#include "../include/player.h"
#include "../include/projectile.h"
#include "../include/game.h"
#include "../include/mapa.h"


// -> o arquivo Player.c gerencia completamente o jogador do jogo
// ele define como o aviao se comporta, como se move e como reage ao mundo
// Player.c eh responsavel por carregar sprites, atualizar movimentos,
// gerenciar pontuacao, nivel, vidas e gasolina
// tambem desenha o HUD com informacoes importantes e controla os tiros do jogador
// em resumo: este arquivo contem toda a logica central do personagem principal


//Declaração da lista a ser armazenadas os sprites do aviao
Texture2D sprite_list[3];


void InitPlayer(PLAYER *p){
    //Inicia a estrutura do nosso jogador com suas variaveis padroes

    p -> speed_x = 390;
    p -> speed_y = 100;

    p -> points = 0;
    p -> level = 1;
    p -> fuel_quantity = 100;
    p -> lives = 3;

    //Inicia o aviao com a sprite dele parado
    p -> sprite = LoadTexture("images/aviao2.png");

    //Adicionando os sprites do aviao na lista na ordem certa
    sprite_list[0] = LoadTexture("images/aviao1.png");
    sprite_list[1] = LoadTexture("images/aviao2.png");
    sprite_list[2] = LoadTexture("images/aviao3.png");
}


void ShowHud(PLAYER p){
    //Desenha o HUD em cima com 80 pixels de altura e apresenta as variaveis points, level, lives e fuel_quantity do player
    DrawRectangle(0, 0, SCREEN_WIDTH, 80, GRAY);
    DrawText(TextFormat("Pontos: %d", p.points), 30, 25, 35, BLACK);
    DrawText(TextFormat("Nivel: %d", p.level), 260, 25, 35, BLACK);
    DrawText(TextFormat("Vidas: %d", p.lives), 440, 25, 35, BLACK);
    DrawText(TextFormat("Gasolina: %d", p.fuel_quantity), 650, 25, 35, BLACK);
}



void DrawPlayer(PLAYER p){
    //Cria variavel com as posições do player
    Vector2 pos = { p.posx, p.posy };

    //Desenha o sprite do player
    DrawTextureEx(p.sprite, pos, 0, 1, WHITE);
}

void UpdatePlayer(PLAYER *p, float dt){
    float old_x, old_y;

    int input_user = (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
                   - (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A));

    p->sprite = sprite_list[1 + input_user];

    p->hitbox.height = p->sprite.height;
    p->hitbox.width  = p->sprite.width;


    // MOVIMENTO HORIZONTAL

    old_x = p->posx;

    p -> posx += p-> speed_x * input_user * dt;
    p -> hitbox.x = p -> posx;

    if(CheckTerrainPlayer(1, old_x, p -> posy))     // 1 = colisão horizontal
        p -> posx = old_x;


    // MOVIMENTO VERTICAL (descida automática)
    old_y = p -> posy;

    p -> posy -= p -> speed_y * dt;
    p -> hitbox.y = p -> posy;

    if(CheckTerrainPlayer(2, p -> posx, old_y))     // 2 = colisão vertical
        p -> posy = old_y + 1;


    // TIRO
    if(IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_K)){
        InitProjectile(p->posx, p->posy);
    }
}

