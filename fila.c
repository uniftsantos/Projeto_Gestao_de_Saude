#include "lista_cadastro.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>


Celula * cria_celula(Registro * registro){
    Celula *celula = malloc(sizeof(Celula));

    celula ->anterior = NULL;
    celula ->proximo = NULL;
    celula -> registro = registro;

    return celula;
}

Queue *cria_queue(){
    Queue * queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue ->tail = NULL;
    queue -> qtde =0;

    return queue;
}

void enqueue(Queue * queue, Registro * registro){
    Celula *novo = cria_celula(registro);
    if(queue->qtde == 0){
        queue ->head = novo;      
    }
    else{
        queue ->tail -> proximo = novo;
        novo ->anterior = queue->tail;

    }
    queue ->tail = novo;
    queue ->qtde ++;
}

void dequeue (Queue * queue){
    if(queue->qtde == 0)
    {
        printf("Não tem nada para tirar");
    }
    else
    {
        Registro * registro = queue->head ->registro;
        Celula *temp = queue ->head;
        queue->head = queue->head->proximo;

        if(queue->qtde == 1)
        {
            queue->tail = NULL;
        }
        else
        {
            queue-> head-> anterior = NULL;
        }
        queue ->qtde --;
        free(temp);
        printf("RG %s fora da fila\n", registro->rg);
    }
}

void Show (Queue * queue){
    Celula * atual = queue ->head;
    while(atual != NULL){
        printf("Paciente: %s == portador do rg %s \n",atual->registro->nome, atual->registro->rg);
        atual = atual ->proximo;
    }
    printf("\n");
}