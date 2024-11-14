#ifndef ARVORE_H
#define ARVORE_H
#include "lista_cadastro.h"

//Criando a estrtura do Vertice, que irá armazenar a estutura Registro.
typedef struct Vertice
{
	Registro * registro;
	struct Vertice* esquerdo;
	struct Vertice* direito;
	struct Vertice* pai;
} Vertice;

//Criando a estrutura da Arvore que irá conter o Vertice.
typedef struct Arvore
{
	Vertice* raiz;
	int quantidade;
} Arvore;

//Declarando as funcoes usadas na "arovre.c"
Arvore *cria_arvore();

Vertice *cria_vertice(Registro *registro);

void visitar (Vertice * vertice);
void in_ordem  (Vertice *raiz);
void inserir_ordenado_idade (Arvore * arvore, Registro *registro);
void inserir_ordenado_ano   (Arvore * arvore, Registro *registro);
void inserir_ordenado_mes   (Arvore * arvore, Registro *registro);
void inserir_ordenado_dia   (Arvore * arvore, Registro *registro);

#endif