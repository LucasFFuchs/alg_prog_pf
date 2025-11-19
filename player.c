#include "player.h"
#include "raylib.h"
#include "projectile.h"

//Declaração da lista a ser armazenadas os sprites do aviao
Texture2D sprite_list[3];


void InitPlayer(PLAYER *p){
    //Inicia a estrutura do nosso jogador com suas variaveis padroes
    p -> posy = 800;
    p -> posx = 400;
    p -> speed = 250;
    p -> fuel_quantity = 100;

    //Inicia o aviao com a sprite dele parado
    p -> sprite = LoadTexture("images/aviao2.png");

    //Adicionando os sprites do aviao na lista na ordem certa
    sprite_list[0] = LoadTexture("images/aviao1.png");
    sprite_list[1] = LoadTexture("images/aviao2.png");
    sprite_list[2] = LoadTexture("images/aviao3.png");
}

void DrawPlayer(PLAYER p){
    Vector2 pos = { p.posx, p.posy };

    DrawTextureEx(p.sprite, pos, 0, 1, WHITE);

}

void UpdatePlayer(PLAYER *p){
    //Declara a variavel dt, variavel reponsavel por manter uma padronização de velocidade independente de FPS no jogo
    float dt = GetFrameTime();


    //Declara a variavel que controla se o player esta indo para direita ou esquerda -> -1 para esquerda, 0 parado, 1 para direita
    int input_user = (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
                   - (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A));

    //A partir do input_user, o usa para determinar qual sprite usar, aviao1, se estiver indo para direita, aviao2, se estiver parado, aviao3 se estiver indo para esquerda
    p -> sprite = sprite_list[1 + input_user];

    //Move o player para direita ou esquerda(na mesma velocidade, independente do FPS), dependendo se o input_user é positivo ou negativo
    p -> posx += p -> speed * input_user * dt;

    if((IsKeyPressed(KEY_SPACE))){
        InitProjectile(p -> posx, p -> posy);
    }

}

