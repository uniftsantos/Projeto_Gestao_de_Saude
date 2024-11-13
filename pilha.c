#include "lista_cadastro.h"
#include "pilha.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Celula_pilha * criar_celula(Registro* registro)
{
    Celula_pilha *celula = malloc(sizeof(Celula_pilha));
    celula->registro = registro;
    celula->proximo = NULL;
    celula->flag_opercao = 0;
    return celula;
}

Stack * criar_pilha()
{
    Stack * pilha = malloc(sizeof(Stack));
    pilha->topo = NULL;
    pilha ->qtde =0;
    return pilha;
}

void push(Stack *pilha, Registro* registro, int flag)
{
    Celula_pilha * novo = criar_celula(registro);
    novo->proximo = pilha->topo;
    novo->flag_opercao = flag;

    pilha->topo = novo;
    pilha->qtde++;
}

Registro *pop(Stack*pilha)
{
    if(pilha->qtde ==0){
        printf("Stack underflow");
        return NULL;
    }

    Registro* registro = pilha->topo->registro;
    Celula_pilha * temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    pilha->qtde --;
    free(temp);
    return registro;

}

void show(Stack * pilha)
{
    Celula_pilha * atual = pilha->topo;
    printf("TOPO-> ");
    while(atual != NULL){
        printf("%s ", atual->registro->rg);
        atual = atual->proximo;
    }
    printf("<- Base\n");
}

void desafazer(Stack * pilha, Queue * fila)
{
    if(pilha->topo->flag_opercao == 1)
    {
        Celula * temp = fila->tail;

        if(fila->qtde == 1)
        {
            fila->head = NULL;
            fila->tail = NULL;
        }
        else if(fila->qtde > 1)
        {
            temp->anterior->proximo = NULL;
            fila->tail = temp->anterior;
        }

        pop(pilha);
        free(temp);

        fila->qtde--; 
    }
    else
    {
        Celula * temp = fila->head;
        
        fila->head->registro = pilha->topo->registro;
        fila->head->proximo = temp;
    }
}