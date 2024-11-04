#include <stdio.h>
#include "screen.h"

void screenGotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x); // Exemplo usando ANSI escape codes
}

void screenSetColor(int foreground, int background) {
    // Definir a cor conforme necessário
}

void screenUpdate() {
    fflush(stdout); // Garante que a tela é atualizada
}
