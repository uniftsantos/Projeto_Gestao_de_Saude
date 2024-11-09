#ifndef FILA_ATENDIMENTO_H
#define FILA_ATENDIMENTO_H
#include "lista_cadastro.h"

typedef struct Celula{
    Registro registro;
    struct Celula *proximo;
    struct Celula * anterior;  

} Celula;

typedef struct {
    Celula* head;
    Celula* tail;
    int qtde;
} Queue;

Celula * cria_celula(int valor);

Queue *cria_queue();

void enqueue(Queue * queue, int valor);

int dequeue (Queue * queue);

void Show (Queue * queue);

void Show_invertido(Queue * queue);

#endif 