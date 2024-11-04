#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer.h"

static time_t start_time;
static int duration = 0;

void timerInit() {
    start_time = time(NULL);
}

void timerDestroy() {
    // Se houver recursos a serem desalocados, faça isso aqui
}

int timerTimeOver() {
    // Verifica se o tempo se esgotou
    if (duration > 0) {
        time_t current_time = time(NULL);
        return (current_time - start_time) >= duration;
    }
    return 0;
}

void timerDelay(int seconds) {
    // Define a duração do temporizador
    duration = seconds;
    timerInit(); // Reinicializa o temporizador
    while (!timerTimeOver()) {
        // Loop até que o tempo se esgote
    }
}