#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

void mostrar_resultados(int vitoria, int derrota, int empate) {
    screenClear();
    screenInit(1);

    screenGotoxy(30, 13);
    printf("Você teve um total de:");
    screenGotoxy(30, 15);
    printf("%d VITÓRIAS", vitoria);
    screenGotoxy(30, 17);
    printf("%d DERROTAS", derrota);
    screenGotoxy(30, 19);
    printf("%d EMPATE", empate);

    screenGotoxy(30, 21);
    printf("Pressione ENTER para sair...");
    getchar();
    getchar();
}

int escolha_opcao() {
    screenClear();
    screenInit(1);

    screenGotoxy(30, 13);
    printf("Escolha PEDRA[0], PAPEL[1] ou TESOURA[2]: ");
    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

void verificacao_da_escolha(int opcao_user, int *n_empate, int *n_vitoria, int *n_derrota) {
    screenClear();
    screenInit(1);

    char escolha_user[20];
    char escolha_computador[20];
    int opcao_computador;

    srand(time(NULL));
    opcao_computador = rand() % 3;

    const char *opcoes[] = {"PEDRA", "PAPEL", "TESOURA"};
    strcpy(escolha_user, opcoes[opcao_user]);
    strcpy(escolha_computador, opcoes[opcao_computador]);

    screenGotoxy(30, 13);
    if (opcao_user == opcao_computador) {
        printf("EMPATE! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        (*n_empate)++;
    } else if ((opcao_user == 0 && opcao_computador == 2) || 
               (opcao_user == 1 && opcao_computador == 0) || 
               (opcao_user == 2 && opcao_computador == 1)) {
        printf("Parabéns, você GANHOU! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        (*n_vitoria)++;
    } else {
        printf("Você PERDEU! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        (*n_derrota)++;
    }
}

int main() {
    screenInit(1);  
    keyboardInit();

    int cont_empate = 0, cont_vitoria = 0, cont_derrota = 0;
    char opcao_sair;

    do {
        int opcao_user = escolha_opcao();
        verificacao_da_escolha(opcao_user, &cont_empate, &cont_vitoria, &cont_derrota);

        screenGotoxy(30, 15);
        printf("Pressione ENTER para continuar...");
        getchar();
        getchar();

        screenClear();
        screenInit(1);

        screenGotoxy(30, 13);
        printf("Deseja continuar? Sim[S] Não[N]: ");
        scanf(" %c", &opcao_sair);

    } while (opcao_sair == 'S' || opcao_sair == 's');

    mostrar_resultados(cont_vitoria, cont_derrota, cont_empate);

    keyboardDestroy();
    screenDestroy();
    return 0;
}
