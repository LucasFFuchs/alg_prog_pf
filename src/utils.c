#include "../include/utils.h"
Color pause_color = {80, 80, 90, 200}; //Variavel Color da cor do pause, cinza meio transparente

void DrawPause(){
    BUTTON b;
    //Quando o enter é pressionado, pause fica ativo se esta inativo, e fica inativo se esta ativo
    if(IsKeyPressed(KEY_ENTER) && !game_over && !game_win)
        pause = !pause;
        int posx, posy, tamanho_fonte;
        if(pause){ //Cria botao para reiniciar nivel
            tamanho_fonte = 80;
            posx = SCREEN_WIDTH/2 - (MeasureText("Reiniciar Nivel", tamanho_fonte) / 2);
            posy = SCREEN_HEIGHT/2 - 100;
            b = InitButton(posx, posy, tamanho_fonte, "Reiniciar Nivel", 1, YELLOW);
        }
    //Desenha a caixa do Pause
    if(pause){//Desenha botao de reiniciar nivel e caixa do pause
        DrawRectangle(posx - 30, posy - 20, MeasureText("Reiniciar Nivel", tamanho_fonte) + 60, tamanho_fonte + 30, pause_color);
        if(SelectedButton(&b, GOLD, YELLOW)){//Se botao for clicado, reseta nivel
            restart_cont++;
            ResetLevel();
        }
        DrawButton(b);
    }
}


bool GameOver(){//Checa se jogador nao tem mais vidas ou combustivel
    bool retorno = false;
    if(jogador.lives <= 0 || jogador.fuel_quantity <= 0)
        retorno = true;
    return retorno;
}

void DrawGameOver(){//Desenha caixa, texto de game over e botao para voltar ao menu
    if(GameOver()){
        int tamanho_fonte = 100;
        game_over = 1;
        BUTTON b;

        DrawBox("GAME OVER", "Voltar ao menu", tamanho_fonte, 150, RED, ORANGE, -1);

    }
}


void DrawGameWin(){//Desenha caixa, texto de game win e botao para registrar nome na tabela
    BUTTON b;
    int tamanho_fonte = 100;
    game_win = 1;

    DrawBox("Voce venceu!", "Registrar nome", tamanho_fonte, 300, BLUE, SKYBLUE, 3);
    b = InitButton(SCREEN_WIDTH /2 - MeasureText("Voltar ao menu", tamanho_fonte - 30) / 2, SCREEN_HEIGHT / 2 + 50, tamanho_fonte - 30,"Voltar ao menu" , -1, BLUE);

    SelectedButton(&b, SKYBLUE, BLUE);
    DrawButton(b);




}

void InitLevel(){//Carrega o mapa da lista de mapas no indice nivel - 1
    InitMapMatrix(lista_mapas[jogador.level - 1], &jogador, &backup);
}

bool NextLevel(){//Quando jogador passa do fim do mapa, passa de nivel
    if(jogador.posy < HUD_HEIGHT - jogador.sprite.height){
        if(jogador.level == 10)//Se esta no nivel dez, da game win
            DrawGameWin();
        else{
            jogador.level++; // aumenta nivel do jogador, aumenta velocidade do jogador e consumo de gasolina
            jogador.speed_y += SPEED_Y_INCREMENT;
            fuel_loss++;
            for(int i = 0; i < MAXENEMY; i++){ //desativa inimigos e postos de gasolina
                lista_enemy[i].is_active = false;
            }
            for(int i = 0; i < MAXFUEL; i++){
                lista_fuel[i].is_active = false;
            }

            InitLevel(); //Roda o proximo mapa
        }
    }
}

void ResetLevel(){ // Jogador backup, que esta com as informações do inicio do nivel se transforma jogador
    jogador = backup;
    InitLevel();
    for(int i = 0; i <  MAXPROJECTILE; i++){ //Desativa projeteis e inimigos, para carregarem de novo
        if(list_projectile[i].is_active)
            list_projectile[i].is_active = false;
    }
    for(int i = 0; i <  MAXENEMY; i++){
        if(lista_enemy[i].is_active)
            lista_enemy[i].is_active = false;
    }
    pause = !pause; //Tira do menu do pause
}


void DrawBox(char texto[30], char texto_botao[30], int tamanho_fonte, int incremento_y, Color cor, Color cor_hover, int game_estate){
    int posx, posy; //Cria caixa ao redor do texto e embaixo do texto cria um botao que ao ser clicado, muda game_estate
    BUTTON b;

    posx = SCREEN_WIDTH / 2 - (MeasureText(TextFormat("%s", texto), tamanho_fonte) / 2);
    posy = SCREEN_HEIGHT / 2 - tamanho_fonte - 100;

    int toleranciax = 40;
    int toleranciay = 30;


    DrawRectangle(posx - toleranciax, posy - toleranciay, MeasureText(TextFormat("%s", texto), tamanho_fonte) + toleranciax * 2, tamanho_fonte + toleranciay * 2 + incremento_y, pause_color);
    DrawText(TextFormat("%s", texto), posx, posy, tamanho_fonte, cor);

    posx = SCREEN_WIDTH/2 - (MeasureText(TextFormat("%s", texto_botao), tamanho_fonte - 30) / 2);
    posy = SCREEN_HEIGHT/2 - 200;

    b = InitButton(posx, posy + tamanho_fonte + 40, tamanho_fonte - 30, TextFormat("%s", texto_botao), game_estate, cor);

    if( SelectedButton(&b, cor_hover, cor) && game_estate == -1){ //Se voltar ao menu, desativa todas entidades para nao dar conflito ao carregar de novo
        for(int i = 0; i <  MAXPROJECTILE; i++){
            if(list_projectile[i].is_active)
                list_projectile[i].is_active = false;
        }
        for(int i = 0; i <  MAXENEMY; i++){
            if(lista_enemy[i].is_active)
                lista_enemy[i].is_active = false;
        }
        for(int i = 0; i <  MAXFUEL; i++){
            if(lista_fuel[i].is_active)
                lista_fuel[i].is_active = false;
        }
    }
    DrawButton(b);
}
