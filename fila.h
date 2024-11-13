#ifndef FILA_ATENDIMENTO_H
#define FILA_ATENDIMENTO_H
#include "lista_cadastro.h"

//Criando a estrtura da nossa Celula, que ira armazenar a struct Registro.
typedef struct Celula{
    Registro * registro;
    struct Celula *proximo;
    struct Celula * anterior;  

} Celula;

//Criando a estrutura da nossa Queue que armazenara a nossa Celula.
typedef struct {
    Celula* head;//posicao de remocao 
    Celula* tail;//posicao de insercao
    int qtde; //quantidade de elementos
} Queue;

//Declarando as funcoes que seram usadas na fila.c

Celula * cria_celula(Registro *registro);

Queue *cria_queue();

void enqueue(Queue * queue, Registro *registro);

void dequeue (Queue * queue);

void Show (Queue * queue);
void Show_invertido(Queue * queue);

#endif 