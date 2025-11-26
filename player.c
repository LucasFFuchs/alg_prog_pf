#include "player.h"
#include "raylib.h"
#include "projectile.h"
#include "game.h"

//Declaração da lista a ser armazenadas os sprites do aviao
Texture2D sprite_list[3];


void InitPlayer(PLAYER *p){
    //Inicia a estrutura do nosso jogador com suas variaveis padroes
    p -> posy = 800;
    p -> posx = 400;
    p -> speed = 390;

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

    //Declara a variavel que controla se o player esta indo para direita ou esquerda -> -1 para esquerda, 0 parado, 1 para direita
    int input_user = (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
                   - (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A));

    //A partir do input_user, o usa para determinar qual sprite usar, aviao1, se estiver indo para direita, aviao2, se estiver parado, aviao3 se estiver indo para esquerda
    p -> sprite = sprite_list[1 + input_user];

    //Move o player para direita ou esquerda(na mesma velocidade, independente do FPS), dependendo se o input_user é positivo ou negativo
    p -> posx += p -> speed * input_user * dt;


    //Quando espaço ou K é apertado, inicia um projetil com a função InitProjectile nas posições do player
    if(IsKeyPressed(KEY_SPACE ) || IsKeyPressed(KEY_K)){
        InitProjectile(p -> posx, p -> posy);
    }
    if(p -> posx < -(p -> sprite).width)
        p -> posx = SCREEN_WIDTH;
    if(p -> posx > SCREEN_WIDTH)
        p -> posx = -(p -> sprite).width;
}

