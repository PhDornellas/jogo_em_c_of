#ifndef FUNCOES_H
#define FUNCOES_H

#include "screen.h"
#include "keyboard.h"
#include "timer.h"

typedef struct
{
    int vitorias;
    int derrotas;
    int empates;
} Estatisticas;

void logo_entrada();
void logo_Apresentacao();
void explicacao_jogo();
int escolha_opcao();
void verificacao_da_escolha(int opcao_user, Estatisticas *stats);
void mostrar_resultados(Estatisticas *stats);

#endif // FUNCOES_H
