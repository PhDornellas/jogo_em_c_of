#ifndef TIMER_H
#define TIMER_H

void timerInit();       // Inicializa o temporizador
void timerDestroy();    // Desaloca recursos do temporizador
int timerTimeOver();    // Verifica se o tempo se esgotou
void timerDelay(int seconds); // Pausa a execução por um determinado número de segundos

#endif