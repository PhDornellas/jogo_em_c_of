#include <stdio.h>
#include "keyboard.h"

int escolha_opcao() {
    int opcao;
    printf("Escolha PEDRA[0], PAPEL[1] OU TESOURA[2]: ");
    scanf("%d", &opcao);
    return opcao;
}

char lerOpcaoContinuar() {
    char opcao;
    printf("\nDeseja continuar? Sim[S] Não[N]: ");
    scanf(" %c", &opcao);
    return opcao;
}
