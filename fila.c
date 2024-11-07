#include "lista_cadastro.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Celula{
    int valor;
    struct Celula *proximo;
    struct Celula * anterior;  

} Celula;



typedef struct {
    Elista* head;
    Elista* tail;
    int qtde;

} Queue;

Celula * cria_celula(int valor){
    Celula *celula = malloc(sizeof(Celula));
    celula ->anterior = NULL;
    celula ->proximo = NULL;
    celula -> valor = valor;

    return celula;
}

Queue *cria_queue(){
    Queue * queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue ->tail = NULL;
    queue -> qtde =0;

    return queue;
}

void enqueue(Queue * queue, int valor){
    Celula *novo = cria_celula(valor);
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

int dequeue (Queue * queue){
    if(queue->qtde == 0){
        return -1;
    }

    int valor = queue ->head ->valor;
    Celula *temp = queue ->head;
    queue -> head = queue ->head -> proximo;

    if(queue->qtde == 1){//fila unitaria
    
        //int valor = queue ->head -> valor;
        //Celula *temp = queue ->head;
        //queue ->head = NULL;
        queue ->tail = NULL;
        // queue ->qtde --;
        // free(temp);
        // return valor; 
    }
    else{
        //int valor = queue ->head ->valor;
        //Celula * temp = queue ->head;
        //queue -> head = queue ->head->proximo;
        queue-> head-> anterior = NULL;
        // queue ->qtde --;
        // free(temp);
        // return valor;
    }
    queue ->qtde --;
    free(temp);
    return valor;
        

}

void Show (Queue * queue){
    Celula * atual = queue ->head;
    while(atual != NULL){
        printf("%d ", atual ->valor);
        atual = atual ->proximo;
    }
    printf("\n");
}

void Show_invertido(Queue * queue){
    Celula * atual = queue -> tail;
    while(atual != NULL){
        printf("%d ", atual ->valor);
        atual = atual ->anterior;
    }
    printf("\n");
}

int main(){
    Queue * queue = cria_queue();
    for (int i = 89; i>0; i = i - 7){
        enqueue(queue,i);
        Show(queue);
        Show_invertido(queue);
    }

    for(int i=0; i< 15; i++){
        printf("Removido: %d\n",dequeue(queue));
        Show(queue);
        Show_invertido(queue);
    }
}