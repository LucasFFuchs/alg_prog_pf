#include "game.h"
#include "player.h"
#include "projectile.h"
#include "button.h"
#include "menu.h"
#include "raylib.h"
#include "mapa.h"
#include <stdio.h>


//Inicia variaveis
PLAYER jogador; //Variavel do player, nosso jogador
Color background_color = { 45, 50, 184, 255 }; //Variavel Color da cor de fundo(azul escuro)
Color pause_color = {80, 80, 90, 200}; //Variavel Color da cor do pause, cinza meio transparente
PROJECTILE list_projectile[MAXPROJECTILE] = {0}; //Inicia lista de projetis, com numero maximo
int pause = 0; //Inicia variavel pause como 0, desativada
int game_estate = -1; //inicia variavel do game_estate como -1, ou seja, na tela inicial

void MainCourse(){
    //Inicia Jogo
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "River Raid");
    SetTargetFPS(60);

    //Variaveis que serão usadas na lógica de mudança de game_estate
    int controller = 0;
    int sair = 0; //variavel sair começa como 0, inativa


    //Inicia loopíng principal do jogo, fecha quando o X é apertado, ou quando a variavel sair deixa de ser 0
    while(!WindowShouldClose() && !sair){

        //Compara o game_estate com os numeros, para mudar as telas
        switch (game_estate){
            //Quando game_estate = -1, Apresenta tela inicial
            case -1:HomeScreen();
                    if(IsKeyPressed(KEY_ENTER)) // Quando Enter é pressionado, game_estate vira 0
                        game_estate = 0;
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
    InitPlayer(&jogador);
    InitMaps();
    InitMapMatrix(lista_mapas[jogador.level - 1], &jogador);
}

void DrawPause(){
    //Quando o enter é pressionado, pause fica ativo se esta inativo, e fica inativo se esta ativo
    if(IsKeyPressed(KEY_ENTER))
        pause = !pause;
    //Desenha a caixa do Pause
    if(pause)
        DrawRectangle(50, 90, SCREEN_WIDTH - 100, SCREEN_HEIGHT - 160, pause_color);
}

void DrawGame(){
    //Começa a desenhar, poe cor de fundo como background_color

    BeginDrawing();
    ClearBackground(background_color);

    //Desenha Jogador, projeteis e o HUD, e chama a função DrawPause, para verificar se esta ativo ou nao
    DrawMap(lista_mapas[jogador.level - 1]);
    DrawPlayer(jogador);
    DrawProjectile();
    DrawEnemy();
    ShowHud(jogador);
    DrawPause();

    //Para de desenhar
    EndDrawing();
}

void UpdateGame(){
    //Se o jogo nao esta pausado, atualiza o jogo
    //Declara a variavel dt, variavel reponsavel por manter uma padronização de velocidade independente de FPS no jogo
    float dt;
    if(!pause){
        float dt = GetFrameTime();
        UpdatePlayer(&jogador, dt);
        UpdateProjectile(dt);
        UpdateEnemy();

    }
}
