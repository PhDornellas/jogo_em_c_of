#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"


int escolha_opcao() {
    screenClear();
    screenInit(1);

    screenGotoxy(22, 12);
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

    screenGotoxy(9, 10);
    if (opcao_user == opcao_computador) {
        printf("EMPATE! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        (*n_empate)++;
    } else if ((opcao_user == 0 && opcao_computador == 2) || 
               (opcao_user == 1 && opcao_computador == 0) || 
               (opcao_user == 2 && opcao_computador == 1)) {
        printf("Você GANHOU! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        (*n_vitoria)++;
    } else {
        printf("Você PERDEU! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        (*n_derrota)++;
    }
}


void mostrar_resultados(int vitoria, int derrota, int empate) {
    screenClear();
    screenInit(1);

    screenGotoxy(22, 8);
    printf("Você teve um total de:");
    screenGotoxy(22, 10);
    printf("%d VITÓRIAS", vitoria);
    screenGotoxy(22, 12);
    printf("%d DERROTAS", derrota);
    screenGotoxy(22, 14);
    printf("%d EMPATE", empate);

    screenGotoxy(22, 16);
    printf("Pressione ENTER para sair...");
    getchar();

}


int main() {

    screenInit(1);
    keyboardInit();

    screenGotoxy (3,8);
    printf(" ____        _   _   _        __     __  _    _   _  __  __  _____  _  __ \n");
    screenGotoxy (3,9);
    printf("| __ )  __ _| |_| |_| | ___   \\ \\   / / | |  | | | | \\ \\/ / | ____|| |/ / \n");
    screenGotoxy (3,10);
    printf("|  _ \\ / _` | __| __| |/ _ \\   \\ \\ / /  | |  | | | |  \\  /  |  _|  | ' /  \n");
    screenGotoxy(3,11);
    printf("| |_) | (_| | |_| |_| |  __/    \\ V /   | |__| |_| |  /  \\  | |___ | . \\  \n");
    screenGotoxy(3,12); ("|____/ \\__,_|\\__|\\__|_|\\___|     \\_/     \\____/(_)_| /_/\\_\\ |_____||_|\\_\\\n");
    printf("                                                                          \n");
    screenGotoxy(3,13);
    printf("\n");


    // Mensagem de boas-vindas ou introdução do jogo
    screenGotoxy(3,14);
    printf("Bem-vindo ao BATTLE OF LUCK!\n\n");
    getchar();

    screenClear();
    screenInit(1);       

    int cont_empate = 0, cont_vitoria = 0, cont_derrota = 0;
    char opcao_sair;

    do {
    int opcao_user = escolha_opcao();
    verificacao_da_escolha(opcao_user, &cont_empate, &cont_vitoria, &cont_derrota);

    screenGotoxy(22, 12);
    printf("Pressione ENTER para continuar...");
    getchar();
    getchar();

    screenClear();
    screenInit(1);

    screenGotoxy(22, 12);
    printf("Deseja continuar? Sim[S] Não[N]: ");
    scanf(" %c", &opcao_sair);

    } while (opcao_sair == 'S' || opcao_sair == 's');

    mostrar_resultados(cont_vitoria, cont_derrota, cont_empate);

    keyboardDestroy();
    screenDestroy();

    return 0;
}
