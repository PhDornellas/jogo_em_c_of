#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "keyboard.h"
#include "screen.h"

void verificacao_da_escolha(int opcao_user, int *n_empate, int *n_vitoria, int *n_derrota);

int main() {
    int cont_empate = 0, cont_vitoria = 0, cont_derrota = 0;

    while (1) {
        int opcao_user = escolha_opcao();

        verificacao_da_escolha(opcao_user, &cont_empate, &cont_vitoria, &cont_derrota);

        char opcao_sair = lerOpcaoContinuar();
        if (opcao_sair == 'N' || opcao_sair == 'n') {
            printf("Você teve um total de:\n%d VITÓRIAS\n%d DERROTAS\n%d EMPATES\n",
                   cont_vitoria, cont_derrota, cont_empate);
            break;
        }
    }

    return 0;
}

void verificacao_da_escolha(int opcao_user, int *n_empate, int *n_vitoria, int *n_derrota) {
    char *opcoes[] = {"PEDRA", "PAPEL", "TESOURA"};
    int opcao_computador = rand() % 3;

    screenGotoxy(5, 5);
    printf("Você escolheu: %s\n", opcoes[opcao_user]);
    printf("Computador escolheu: %s\n", opcoes[opcao_computador]);

    if (opcao_user == opcao_computador) {
        printf("Empate!\n");
        (*n_empate)++;
    } else if ((opcao_user == 0 && opcao_computador == 2) ||
               (opcao_user == 1 && opcao_computador == 0) ||
               (opcao_user == 2 && opcao_computador == 1)) {
        printf("Você venceu!\n");
        (*n_vitoria)++;
    } else {
        printf("Você perdeu!\n");
        (*n_derrota)++;
    }

    screenUpdate();
}
