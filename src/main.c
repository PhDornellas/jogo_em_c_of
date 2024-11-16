#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "funcoes.h"



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

    logo_entrada();
    explicacao_jogo();

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

