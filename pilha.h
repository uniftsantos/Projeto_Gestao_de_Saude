#ifndef PILHA_H
#define PILHA_H
#include "lista_cadastro.h"
#include "fila.h"

typedef struct Celula_pilha{
    struct Celula_pilha *proximo;
    int flag_opercao;
    Registro * registro;

} Celula_pilha;

typedef struct {
    Celula_pilha *topo;
    int qtde;
} Stack;

Celula_pilha * criar_celula(Registro* registro);
Registro *pop(Stack*pilha);
Stack * criar_pilha();

void push(Stack *pilha, Registro* registro, int flag);
void show(Stack * pilha);
void desafazer(Stack * pilha, Queue * fila);

#endif 