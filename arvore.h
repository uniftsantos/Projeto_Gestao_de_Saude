#ifndef ARVORE_H
#define ARVORE_H
#include "lista_cadastro.h"

typedef struct Vertice{
	Registro * registro;
	struct Vertice* esq;
	struct Vertice* dir;
} Vertice;


typedef struct Arvore{
	Vertice* raiz;
	int qtde;
} Arvore;



void visitar (Vertice * vertice);

void in_ordem(Vertice *raiz);

void pre_ordem(Vertice *raiz);

void pos_ordem(Vertice *raiz);

Vertice *cria_vertice(Registro *registro);

Arvore *cria_arvore();

void inserir_ordenado_idade (Arvore * arvore, Registro *registro);

#endif