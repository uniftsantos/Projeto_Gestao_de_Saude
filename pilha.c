#include "lista_cadastro.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Celula * criar_celula(Registro* registro){
    Celula *celula = malloc(sizeof(Celula));
    celula->registro = registro;
    celula->proximo = NULL;
    return celula;
}

Stack * criar_pilha(){
    Stack * pilha = malloc(sizeof(Stack));
    pilha->topo = NULL;
    pilha ->qtde =0;
    return pilha;
}

void push(Stack *pilha, Registro* registro){
    Celula * novo = criar_celula(registro);
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->qtde ++;
}

Registro *pop(Stack*pilha){
    if(pilha->qtde ==0){
        printf("Stack underflow");
        return NULL;
    }

    Registro* registro = pilha->topo->registro;
    Celula * temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    pilha->qtde --;
    free(temp);
    return registro;

}

void show(Stack * pilha){
    Celula * atual = pilha->topo;
    printf("TOPO-> ");
    while(atual != NULL){
        printf("%d ", atual->registro->rg);
        atual = atual->proximo;
    }
    printf("<- Base\n");
}

