#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

Vertice *cria_vertice(Registro * registro){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
	novo->registro = registro;
	
	return novo;
}

void visitar (Vertice * vertice){
    printf("nome: %s\n", vertice->registro->nome);
    printf("RG: %s\n", vertice->registro->rg);
}

void in_ordem(Vertice *raiz){
    if(raiz != NULL){
        in_ordem(raiz->esq);
        visitar(raiz);
        in_ordem(raiz->dir);
    }
}

void pre_ordem(Vertice *raiz){
    if(raiz != NULL){
        visitar(raiz);
        pre_ordem(raiz->esq);
        pre_ordem(raiz->dir);
    }
}

void pos_ordem(Vertice *raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        visitar(raiz);
    }
}



Arvore *cria_arvore(){
	Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	return arvore;
}



void inserir_ordenado_idade (Arvore * arvore, Registro *registro){
    Vertice * novo = cria_vertice(registro);
    if(arvore->raiz == NULL){
        arvore->raiz = novo;
    }
    else{
        Vertice * atual = arvore->raiz;
        Vertice * anterior = NULL;

        while (atual != NULL){
            if(novo->registro->idade <= atual->registro->idade){
                anterior = atual;
                atual = atual->esq;
            }
            else{
                anterior = atual;
                atual = atual->dir;
            }  
        }
    }
    arvore->qtde++;
}



