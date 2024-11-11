#ifndef ARVORE_H
#define ARVORE_H
#include "lista_cadastro.h"

typedef struct Vertice{
	Registro * registro;
	struct Vertice* esq;
	struct Vertice* dir;
	struct Vertice* pai;
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
void inserir_ordenado_ano (Arvore * arvore, Registro *registro);
void inserir_ordenado_mes (Arvore * arvore, Registro *registro);
void inserir_ordenado_dia (Arvore * arvore, Registro *registro);

#endif