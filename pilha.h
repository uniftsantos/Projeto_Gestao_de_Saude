#ifndef PILHA_H
#define PILHA_H
#include "lista_cadastro.h"


typedef struct Celula_pilha{
    struct Celula_pilha *proximo;
    Registro * registro;
} Celula_pilha;

typedef struct {
    Celula_pilha *topo;
    int qtde;
} Stack;


Celula_pilha * criar_celula(Registro* registro);
Stack * criar_pilha();
void push(Stack *pilha, Registro* registro);
Registro *pop(Stack*pilha);
void show(Stack * pilha);


#endif 