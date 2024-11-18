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
    

    logo_entrada();
    explicacao_jogo();

    int vitoria_geral = 0;
    int derrota_geral = 0;
    char opcao_sair;
    

    do {
        int round = 1;
        stats->vitorias = 0;
        stats->derrotas = 0;
        stats->empates = 0;
        do
        {
            int opcao_user = escolha_opcao(round);
            round = round +1;
            verificacao_da_escolha(opcao_user, stats);

            screenGotoxy(22, 12);
            printf("Pressione ENTER para continuar...");
            getchar();
            getchar();

            screenClear();
            screenInit(1);

        } while (stats->vitorias < 3 && stats->derrotas < 3);

        mostrar_resultados(stats);
        if(stats->vitorias == 3){
            vitoria_geral= vitoria_geral + 1;
        }

        else if (stats->derrotas == 3){
            derrota_geral = derrota_geral + 1;
        }
        
        
        screenClear();
        screenInit(1);
        screenGotoxy(22, 12);
        printf("Deseja Jogar outra ? Sim[S] Não[N]: ");
        scanf(" %c", &opcao_sair);

    } while (opcao_sair == 'S' || opcao_sair == 's');

    mostrar_resultado_geral(vitoria_geral, derrota_geral);

    
    free(stats);

    keyboardDestroy();
    screenDestroy();


    return 0;
}

