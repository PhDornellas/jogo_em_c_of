#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

// Definição da struct para armazenar estatísticas
typedef struct {
    int vitorias;
    int derrotas;
    int empates;
} Estatisticas;

int escolha_opcao() {
    screenClear();
    screenInit(1);


    screenGotoxy(22, 5);
    printf("Escolha PEDRA[0], PAPEL[1] ou TESOURA[2]: ");
    
    screenGotoxy(3, 8);
    printf("   Pedra                Papel               Tesoura ");
    screenGotoxy(3, 9);
    printf("   _____                ___________                    o     o");
    screenGotoxy(3, 10);
    printf(" /                     |           |                       /");
    screenGotoxy(3, 11);
    printf("|         |            |  ------   |                     /");
    screenGotoxy(3, 12);
    printf(" ______/               |  ------   |                      X");
    screenGotoxy(3, 13);
    printf("                       |  ------   |                     /  ");
    screenGotoxy(3, 14);
    printf("                       |___________|                    /    ");


    int opcao;
    scanf("%d", &opcao);

    return opcao;
}

void verificacao_da_escolha(int opcao_user, Estatisticas *stats) {
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
        stats->empates++;
    } else if ((opcao_user == 0 && opcao_computador == 2) || 
               (opcao_user == 1 && opcao_computador == 0) || 
               (opcao_user == 2 && opcao_computador == 1)) {
        printf("Você GANHOU! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        stats->vitorias++;
    } else {
        printf("Você PERDEU! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        stats->derrotas++;
    }

    
}

void mostrar_resultados(Estatisticas *stats) {
    screenClear();
    screenInit(1);

    screenGotoxy(22, 8);
    printf("Você teve um total de:");
    screenGotoxy(22, 10);
    printf("%d VITÓRIAS", stats->vitorias);
    screenGotoxy(22, 12);
    printf("%d DERROTAS", stats->derrotas);
    screenGotoxy(22, 14);
    printf("%d EMPATES", stats->empates);

    screenGotoxy(22, 16);
    printf("Pressione ENTER para sair...");
    getchar();

    
}

int main() {
    screenInit(1);
    keyboardInit();

    Estatisticas *stats = malloc(sizeof(Estatisticas));
    if (stats == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        return 1;
    }
    stats->vitorias = 0;
    stats->derrotas = 0;
    stats->empates = 0;

    

    screenGotoxy(20, 3);
    printf("| __ )  __ _| |_| |_| | ___    \n");
    screenGotoxy(20, 4);
    printf("|  _ \\ / _` | __| __| |/ _ \\   \n");
    screenGotoxy(20, 5);
    printf("| |_) | (_| | |_| |_| |  __/   \n");
    screenGotoxy(20, 6); 
    printf("|____/ \\__,_|\\__|\\__|_|\\___    \n");                                                        
    screenGotoxy(20, 7);
    printf("\n");

    screenGotoxy(27, 8);
    printf("    _     ___    \n");
    screenGotoxy(27, 9);
    printf("  / _ \\  |  __|  \n");
    screenGotoxy(27, 10);
    printf(" | | | | | |_    \n");
    screenGotoxy(27, 11);
    printf(" | | | | |  _|   \n");
    screenGotoxy(27, 12);
    printf(" | |_| | | |     \n");
    screenGotoxy(27, 13);
    printf("  \\ _ /  |_|     \n");

    screenGotoxy(20, 14);
    printf(" _      _   _   ____   _  __  _   _ \n");
    screenGotoxy(20, 15);
    printf("| |    | | | | / ___| | |/ / | | | |\n");
    screenGotoxy(20, 16);
    printf("| |    | | | || |     | ' /   \\   /\n");
    screenGotoxy(20, 17);
    printf("| |___ | |_| || |___  | . \\    | | \n");
    screenGotoxy(20, 18);
    printf("|_____| \\___/  \\____| |_|\\_\\   |_| \n");



    screenGotoxy(45, 21);
    printf("Bem-vindo ao BATTLE OF LUCK!\n\n");
    screenGotoxy(45, 22);
    printf("Pressione ENTER para continuar...");
    getchar();

    char opcao_sair;
    do {
        int opcao_user = escolha_opcao();
        verificacao_da_escolha(opcao_user, stats);

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

    mostrar_resultados(stats);

    
    free(stats);

    keyboardDestroy();
    screenDestroy();


    return 0;
}

