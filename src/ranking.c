#include "../include/ranking.h"
#include "../include/utils.h"
#include "../include/menu.h"
#include "raylib.h"
#include <stdio.h>
#include <string.h>

RANKING lista_ranking[MAX_JOGOS_SALVOS] = {0};
int letter_cont;
char inputText[MAX_LETRAS_NOME] = {0};
int arq_cont = 0;
int flag_arq;


// Conta quantos registros existem no arquivo
int NumberOfGames() {
    FILE *arq = fopen("highscore.bin", "rb");
    if (!arq) return 0;

    fseek(arq, 0, SEEK_END);
    int size = ftell(arq);
    fclose(arq);

    return size / sizeof(RANKING);
}

// Lê o arquivo inteiro e carrega no vetor lista_ranking
void LoadList() {
    FILE *arq = fopen("highscore.bin", "rb");
    if (!arq) {
        // cria arquivo se não existir
        arq = fopen("highscore.bin", "wb");
        fclose(arq);
        return;
    }

    int total = NumberOfGames();
    if (total > MAX_JOGOS_SALVOS)
        total = MAX_JOGOS_SALVOS;

    fread(lista_ranking, sizeof(RANKING), total, arq);
    fclose(arq);
}

// Retorna o índice onde um score deve ser inserido (0–9)
int PositionInRanking(int points) {
    for (int i = 0; i < MAX_JOGOS_SALVOS; i++) {
        if (points > lista_ranking[i].points)
            return i;
    }
    return MAX_JOGOS_SALVOS; // não entra no ranking
}

// Atualiza a lista local com a nova entrada (inserção ordenada)
void UpdateRankingList(RANKING r) {
    int pos = PositionInRanking(r.points);
    if (pos >= MAX_JOGOS_SALVOS) return; // score insuficiente

    // desloca para baixo
    for (int i = MAX_JOGOS_SALVOS - 1; i > pos; i--) {
        lista_ranking[i] = lista_ranking[i - 1];
    }

    // insere na posição correta
    lista_ranking[pos] = r;
}

// Verifica se há espaço (sempre até 10)
bool SpaceInRanking(int points) {
    LoadList();
    return PositionInRanking(points) < MAX_JOGOS_SALVOS;
}

// Grava o ranking inteiro no arquivo
void WriteScore(RANKING r) {
    LoadList();             // carrega a lista atual
    UpdateRankingList(r);   // insere novo registro

    FILE *arq = fopen("highscore.bin", "wb");
    if (!arq) {
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    fwrite(lista_ranking, sizeof(RANKING), MAX_JOGOS_SALVOS, arq);
    fclose(arq);
}


// Tela de ranking
void DrawRanking() {
    BeginDrawing();
    ClearBackground(BLACK);

    if (arq_cont == 0) {
        LoadList();
        arq_cont++;
    }

    DisplayScore();


    EndDrawing();
}

// Tela para digitar nome após ganhar o jogo
void DrawWriteName() {
    BeginDrawing();
    ClearBackground(BLACK);

    jogou = 1;

    if (arq_cont == 0) {
        flag_arq = SpaceInRanking(jogador.points);
        arq_cont++;
        letter_cont = 0;
    }

    if (flag_arq) {

        int key = GetCharPressed();

        while (key > 0) {
            if (letter_cont < MAX_LETRAS_NOME - 1) {
                inputText[letter_cont] = (char)key;
                letter_cont++;
                inputText[letter_cont] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE) && letter_cont > 0) {
            letter_cont--;
            inputText[letter_cont] = '\0';
        }

        if (IsKeyPressed(KEY_ENTER) && letter_cont > 0) {
            // cria struct com dados completos
            RANKING r;
            strcpy(r.nome, inputText);
            r.points = jogador.points;
            r.restart = restart_cont;

            WriteScore(r);      // salva corretamente
            game_estate = 2;
            arq_cont = 0;
            inputText[0] = '\0';
            letter_cont = 0;
        }

        DrawText("Digite seu nome:", 150, 140, 80, WHITE);
        DrawText(inputText, 40, 250, 50, WHITE);
    }

    else {
        DrawBox("Pontuacao insuficiente", "Voltar ao menu", 70, 150, RED, ORANGE, -1);
    }

    EndDrawing();
}

// Exibe o ranking na tela
void DisplayScore() {
    BUTTON b = InitButton(SCREEN_WIDTH/2 - MeasureText("Voltar ao menu", 50)/2, 30, 50, "Voltar ao menu", -1, YELLOW);
    SelectedButton(&b, GOLD, YELLOW);
    DrawButton(b);

    DrawText("    Nome            Pontos    Reiniciou", 120, 100, 45, ORANGE);
    for (int i = 0; i < MAX_JOGOS_SALVOS; i++) {
        if (lista_ranking[i].nome[0] == '\0')
            continue;
        DrawText(TextFormat("%s", lista_ranking[i].nome), 80, 160+ 65 * i, 25, YELLOW);
        DrawText(TextFormat("%d", lista_ranking[i].points), 570, 160+ 65 * i, 40, YELLOW);
        DrawText(TextFormat("%d", lista_ranking[i].restart), 820, 160+ 65 * i, 40, YELLOW);
    }
}
