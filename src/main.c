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

void logo_entrada(){

    screenGotoxy(20, 2);
    screenSetColor(WHITE,LIGHTBLUE);   
    printf(" ___         _   _   _");
    screenGotoxy(20, 3);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| __ )  __ _| |_| |_| | ___    \n");
    screenGotoxy(20, 4);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("|  _ \\ / _` | __| __| |/ _ \\   \n");
    screenGotoxy(20, 5);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| |_) | (_| | |_| |_| |  __/   \n");
    screenGotoxy(20, 6);
    screenSetColor(WHITE,LIGHTBLUE); 
    printf("|____/ \\__,_|\\__|\\__|_|\\___    \n");                                                        
    

    screenGotoxy(27, 8);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("    _     ___    \n");
    screenGotoxy(27, 9);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("  / _ \\  |  __|  \n");
    screenGotoxy(27, 10);
    screenSetColor(WHITE,LIGHTBLUE);
    printf(" | | | | | |_    \n");
    screenGotoxy(27, 11);
    screenSetColor(WHITE,LIGHTBLUE);
    printf(" | | | | |  _|   \n");
    screenGotoxy(27, 12);
    screenSetColor(WHITE,LIGHTBLUE);
    printf(" | |_| | | |     \n");
    screenGotoxy(27, 13);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("  \\ _ /  |_|     \n");

    screenGotoxy(20, 14);
    screenSetColor(WHITE,LIGHTBLUE);
    printf(" _      _   _   ____   _  __   \n");
    screenGotoxy(20, 15);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| |    | | | | / ___| | |/ / \n");
    screenGotoxy(20, 16);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| |    | | | || |     | ' /      \n");
    screenGotoxy(20, 17);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| |___ | |_| || |___  | . \\     \n");
    screenGotoxy(20, 18);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("|_____| \\___/  \\____| |_|\\_\\    \n");



    screenGotoxy(45, 21);
    screenSetColor(CYAN, WHITE);
    printf("Bem-vindo ao BATTLE OF LUCK!\n\n");
    screenGotoxy(45, 22);
    screenSetColor(CYAN,WHITE);
    printf("Pressione ENTER para continuar...");
    getchar();

}

int escolha_opcao() {
    screenClear();
    screenInit(1);


    screenGotoxy(33, 8);
    screenSetColor(CYAN, WHITE);
    printf("Escolha PEDRA[0], PAPEL[1] ou TESOURA[2]: \n");
    screenGotoxy(27,10);
    screenSetColor(DARKGRAY,WHITE);
    printf("Digite sua escolha e pressione Enter para continuar:\n");
    
    screenGotoxy(3, 2);
    screenSetColor(WHITE,LIGHTBLUE);   
    printf(" ___         _   _   _");
    screenGotoxy(3, 3);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| __ )  __ _| |_| |_| | ___    \n");
    screenGotoxy(3, 4);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("|  _ \\ / _` | __| __| |/ _ \\   \n");
    screenGotoxy(3, 5);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| |_) | (_| | |_| |_| |  __/   \n");
    screenGotoxy(3, 6);
    screenSetColor(WHITE,LIGHTBLUE); 
    printf("|____/ \\__,_|\\__|\\__|_|\\___    \n");                                                        
    

    screenGotoxy(8, 7);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("    _     ___    \n");
    screenGotoxy(8, 8);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("  / _ \\  |  __|  \n");
    screenGotoxy(8, 9);
    screenSetColor(WHITE,LIGHTBLUE);
    printf(" | | | | | |_    \n");
    screenGotoxy(8, 10);
    screenSetColor(WHITE,LIGHTBLUE);
    printf(" | | | | |  _|   \n");
    screenGotoxy(8, 11);
    screenSetColor(WHITE,LIGHTBLUE);
    printf(" | |_| | | |     \n");
    screenGotoxy(8, 12);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("  \\ _ /  |_|     \n");

    screenGotoxy(3, 13);
    screenSetColor(WHITE,LIGHTBLUE);
    printf(" _      _   _   ____   _  __   \n");
    screenGotoxy(3, 14);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| |    | | | | / ___| | |/ / \n");
    screenGotoxy(3, 15);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| |    | | | || |     | ' /      \n");
    screenGotoxy(3, 16);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("| |___ | |_| || |___  | . \\     \n");
    screenGotoxy(3, 17);
    screenSetColor(WHITE,LIGHTBLUE);
    printf("|_____| \\___/  \\____| |_|\\_\\    \n");

    

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
        screenSetColor(YELLOW, WHITE);
        printf("EMPATE! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        stats->empates++;
    } else if ((opcao_user == 0 && opcao_computador == 2) || 
               (opcao_user == 1 && opcao_computador == 0) || 
               (opcao_user == 2 && opcao_computador == 1)) {
        screenSetColor(GREEN, WHITE);
        printf("Você GANHOU! O computador escolheu %s e você escolheu %s\n", escolha_computador, escolha_user);
        stats->vitorias++;
    } else {
        screenSetColor(RED, WHITE);
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

    logo_entrada();

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

