#ifndef FILA_ATENDIMENTO_H
#define FILA_ATENDIMENTO_H

typedef struct Celula{
    int valor;
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