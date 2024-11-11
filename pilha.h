#ifndef PILHA_H
#define PILHA_H
#include "lista_cadastro.h"


typedef struct Celula{
    struct Celula *proximo;
    Registro * registro;
} Celula;

typedef struct {
    Celula *topo;
    int qtde;
} Stack;


Celula * criar_celula(Registro* registro);
Stack * criar_pilha();
void push(Stack *pilha, Registro* registro);
Registro *pop(Stack*pilha);


#endif 