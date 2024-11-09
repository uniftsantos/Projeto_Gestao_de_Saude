#ifndef FILA_ATENDIMENTO_H
#define FILA_ATENDIMENTO_H
#include "lista_cadastro.h"

typedef struct Celula{
    Registro * registro;
    struct Celula *proximo;
    struct Celula * anterior;  

} Celula;

typedef struct {
    Celula* head;
    Celula* tail;
    int qtde;
} Queue;

Celula * cria_celula(Registro *registro);

Queue *cria_queue();

void enqueue(Queue * queue, Registro *registro);

void dequeue (Queue * queue);

void Show (Queue * queue);

#endif 