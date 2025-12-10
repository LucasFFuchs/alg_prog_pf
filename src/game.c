#include "raylib.h"
#include <stdio.h>
#include "../include/game.h"
#include "../include/player.h"
#include "../include/projectile.h"
#include "../include/button.h"
#include "../include/menu.h"
#include "../include/mapa.h"

//Inicia variaveis
PLAYER jogador, backup; //Variavel do player, nosso jogador
Color background_color = { 45, 50, 184, 255 }; //Variavel Color da cor de fundo(azul escuro)

PROJECTILE list_projectile[MAXPROJECTILE] = {0}; //Inicia lista de projetis, com numero maximo
int pause, game_over, game_win;//Declara variaveis para controlar jogo
int game_estate = -1; //inicia variavel do game_estate como -1, ou seja, na tela inicial


void RunGame(){
    //Inicia Jogo
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "River Raid");
    SetTargetFPS(60);

    //Variaveis que serão usadas na lógica de mudança de game_estate
    int controller = 0;
    int sair = 0; //variavel sair começa como 0, inativa


    //Inicia loopíng principal do jogo, fecha quando o X é apertado, ou quando a variavel sair deixa de ser 0
    while(!WindowShouldClose() && !sair){

        //Compara o game_estate com os numeros, para mudar as telas
        switch(game_estate){
            //Quando game_estate = -1, Apresenta tela inicial
            case -1:HomeScreen();
                    if(IsKeyPressed(KEY_ENTER)){ // Quando Enter é pressionado, game_estate vira 0
                        game_estate = 0;
                        game_over = 0; //Inicializa variaveis essenciais para o jogo funcionar
                        game_win = 0;
                        pause = 0;
                    }
                    break;
            //Quando game_estate = 0, apresenta o menu
            case 0:if(!controller){ //Quando variavel controller é 0, Inicia Menu, será rodado apenas uma vez pois controller sera adicionado 1
                        InitMenu();
                        controller++;
                    }
                    //Atualiza Menu, depois o desenha
                    UpdateMenu();
                    DrawMenu();

                    break;
            //Quando game_estate = 1, começa o jogo
            case 1: if(controller){//Mesma logica de cima, mas com o game, e checa se controller é 1, a primeira vez vai ser, entao controller vira 0 de novo
                        InitGame();
                        InitProjectileConstant();
                        InitSpriteEnemy();
                        InitFuelSprite();
                        controller--;
                    }
                    DrawGame();
                    UpdateGame();
                    break;
            case 4:
            //Quando game_estate = 4, sai do jogo, muda a variavel de controle sair
                sair = 1;
                break;
        }


    }
    //Encerra jogo
    CloseWindow();
    CloseMaps();

}

void InitGame(){
    InitPlayer(&jogador, &backup);
    InitMaps();
    InitLevel();
}

void DrawGame(){
    //Começa a desenhar, poe cor de fundo como background_color

    BeginDrawing();
    ClearBackground(background_color);

    //Desenha Jogador, projeteis e o HUD, e chama a função DrawPause, para verificar se esta ativo ou nao

    DrawMap();
    DrawFuel();
    DrawPlayer(jogador);
    DrawProjectile();
    DrawEnemy();
    ShowHud(jogador);
    DrawPause();
    DrawGameOver();
    NextLevel();

    //Para de desenhar
    EndDrawing();
}

void UpdateGame(){
    //Se o jogo nao esta pausado, atualiza o jogo
    //Declara a variavel dt, variavel reponsavel por manter uma padronização de velocidade independente de FPS no jogo
    float dt;
    if(!pause && !game_over && !game_win){
        float dt = GetFrameTime();

        UpdatePlayer(&jogador, dt);
        UpdateProjectile(dt);
        UpdateEnemy();

        CheckAllCollision();

    }
}

void CheckAllCollision(){
    for(int i = 0; i < MAXENEMY; i++){
        if(lista_enemy[i].is_active){
            for(int j = 0; j < MAXPROJECTILE; j++){
                if(list_projectile[j].is_active){
                    if(CheckCollisionRecs(lista_enemy[i].hitbox, list_projectile[j].hitbox)){
                        jogador.points += lista_enemy[i].points;
                        lista_enemy[i].is_active = false;
                        list_projectile[j].is_active = false;
                    }
                }
            }
            if(CheckCollisionRecs(lista_enemy[i].hitbox, jogador.hitbox)){
                jogador.lives--;
                lista_enemy[i].is_active = false;
            }

        }
    }

    for(int i = 0; i < MAXPROJECTILE; i++){
        if(list_projectile[i].is_active){
            for(int linha = 0; linha < LINHA; linha++){
                for(int coluna = 0; coluna < COLUNA; coluna++){
                    if(mapa_atual[linha][coluna].tipo == 'T'){
                        if(CheckCollisionRecs(list_projectile[i].hitbox, mapa_atual[linha][coluna].hitbox))
                            list_projectile[i].is_active = false;
                    }
                }
            }
            for(int j = 0; j < MAXFUEL; j++){
                if(lista_fuel[j].is_active){
                    if(CheckCollisionRecs(list_projectile[i].hitbox, lista_fuel[j].hitbox)){
                        list_projectile[i].is_active = false;
                        lista_fuel[j].is_active = false;
                        jogador.points += 20;
                    }
                }
            }
        }
    }
}

int CheckTerrainPlayer(int tipoMov, float old_x, float old_y){
    for(int i = 0; i < LINHA; i++){
        for(int j = 0; j < COLUNA; j++){

            TILE t = mapa_atual[i][j];

            if(t.tipo == 'T'){
                if(CheckCollisionRecs(jogador.hitbox, t.hitbox)){

                    // Movimento horizontal
                    if(tipoMov == 1){
                        // Vindo pela esquerda
                        if(old_x + jogador.hitbox.width <= t.hitbox.x)
                            return 1;

                        // Vindo pela direita
                        if(old_x >= t.hitbox.x + t.hitbox.width)
                            return 1;
                    }

                    // Movimento vertical
                    if(tipoMov == 2){

                        // Vindo de baixo (subindo)
                        if(old_y >= t.hitbox.y + t.hitbox.height)
                            return 1;
                    }
                }
            }
        }
    }
    return 0;
}
