#include "lista_cadastro.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

//Funcao para inicilizar a Celula.
Celula * cria_celula(Registro * registro){
    Celula *celula = malloc(sizeof(Celula));

    celula ->anterior = NULL;
    celula ->proximo = NULL;
    celula -> registro = registro;

    return celula;
}

//Funcao para inicializar a Queue que ira armezanar as Celula.
Queue *cria_queue(){
    Queue * queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue ->tail = NULL;
    queue -> qtde =0;

    return queue;
}

//Funcao de enfilerar o Registros na nossa fila.
void enqueue(Queue * queue, Registro * registro){
    Celula *novo = cria_celula(registro);
    if(queue->qtde == 0){//Quando nao temos nenhum elemento na fila, iremos colocar o registro no comeco da fila(head=posicao de remocao).
        queue ->head = novo;      
    }
    else{//Quando ja temos um elemento na fila.
        queue ->tail -> proximo = novo;
        novo ->anterior = queue->tail;

    }
    queue ->tail = novo; //recebe o novo elemento.
    queue ->qtde ++;//aumentando a quantidade.
}

//Funcao de desenfilerar os pacientes que se encontram na fila.
void dequeue (Queue * queue){
    if(queue->qtde == 0)//Verifica se existem elementos na fila.
    {
        printf("Não tem nada para tirar");
    }
    else
    {
        Registro * registro = queue->head ->registro;
        Celula *temp = queue ->head;
        queue->head = queue->head->proximo;

        if(queue->qtde == 1)//quando a fila é unitaria
        {
            queue->tail = NULL;//ponteiro para tail recebe NULL
        }
        else
        {
            queue-> head-> anterior = NULL;
        }
        queue ->qtde --; //diminui a quantidade de elementos.
        free(temp);//libera memoria
        printf("RG %s fora da fila\n", registro->rg);//printa o cara que saiu da fila.
    }
}

//Funcao que percorre a nossa fila e vai printando o paciente.
void Show (Queue * queue){
    Celula * atual = queue ->head; //pega o comeco da fila 
    while(atual != NULL){
        printf("Paciente: %s == portador do rg %s \n",atual->registro->nome, atual->registro->rg);
        atual = atual ->proximo;
    }
    printf("\n");
}

//Funcao que percorre a nossa fila ao contrario.
void Show_invertido(Queue * queue){
    Celula * atual = queue -> tail;//comeca no final da fila.
    while(atual != NULL)
    {
        atual = atual ->anterior;
    }
    printf("\n");
}