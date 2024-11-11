#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

Vertice *cria_vertice(Registro * registro){
	Vertice* novo = malloc(sizeof(Vertice));
	novo->dir = NULL;
	novo->esq = NULL;
    novo->pai = NULL;

	novo->registro = registro;
	
	return novo;
}

Arvore *cria_arvore(){
	Arvore* arvore = malloc(sizeof(Arvore));
	arvore->raiz = NULL;
	arvore->qtde = 0;

	return arvore;
}

void visitar (Vertice * vertice){
    printf("Nome: %s\n", vertice->registro->nome);
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


Vertice *encontra_posicao(Arvore *arvore, Registro * registro, int orientacao)
{
    Vertice *atual = arvore->raiz;
    Vertice *anterior = NULL;

    while(atual != NULL){

        if(orientacao == 1)
        {
            if(registro->idade <= atual->registro->idade)
            {   
                anterior = atual;
                atual = atual->esq;
            }
            else
            {
                anterior = atual;
                atual = atual->dir;
            }
        }
        else if(orientacao == 2)
        {
            if(registro->Entrada->ano <= atual->registro->Entrada->ano)
            {   
                anterior = atual;
                atual = atual->esq;
            }
            else
            {
                anterior = atual;
                atual = atual->dir;
            }
        }
        else if(orientacao == 3)
        {
            if(registro->Entrada->mes <= atual->registro->Entrada->mes)
            {   
                anterior = atual;
                atual = atual->esq;
            }
            else
            {
                anterior = atual;
                atual = atual->dir;
            }
        }else if(orientacao == 4)
        {
            if(registro->Entrada->dia <= atual->registro->Entrada->dia)
            {   
                anterior = atual;
                atual = atual->esq;
            }
            else
            {
                anterior = atual;
                atual = atual->dir;
            }
        }
    }


    return anterior;
}

void inserir_ordenado_idade(Arvore *arvore, Registro *registro){
    Vertice *novo = cria_vertice(registro);

    if(arvore->qtde == 0)
    {
        arvore->raiz = novo;  
        novo->pai = NULL;      
    }
    else
    {
        Vertice *vertice = encontra_posicao(arvore, registro, 1);

        if(novo->registro->idade <= vertice->registro->idade)
        {
            vertice->esq = novo;
            novo->pai = vertice;
        }
        else
        {
            vertice->dir = novo;
            novo->pai = vertice;
        }

    }

    arvore->qtde++;
}

void inserir_ordenado_ano (Arvore * arvore, Registro *registro){
    Vertice * novo = cria_vertice(registro);
    if(arvore->raiz == NULL){
        arvore->raiz = novo;
    }
    else{
        Vertice * atual = arvore->raiz;
        Vertice * anterior = NULL;
        
        Vertice *vertice = encontra_posicao(arvore, registro, 2);

        if(novo->registro->Entrada->ano <= vertice->registro->Entrada->ano)
        {
            vertice->esq = novo;
            novo->pai = vertice;
        }
        else
        {
            vertice->dir = novo;
            novo->pai = vertice;
        }

    }
    arvore->qtde++;
}

void inserir_ordenado_mes (Arvore * arvore, Registro *registro){
    Vertice * novo = cria_vertice(registro);
    if(arvore->raiz == NULL)
    {
        arvore->raiz = novo;
    }
    else{
        Vertice * atual = arvore->raiz;
        Vertice * anterior = NULL;

        Vertice *vertice = encontra_posicao(arvore, registro, 3);

        if(novo->registro->Entrada->mes <= vertice->registro->Entrada->mes)
        {
            vertice->esq = novo;
            novo->pai = vertice;
        }
        else
        {
            vertice->dir = novo;
            novo->pai = vertice;
        }

    }
    arvore->qtde++;
}

void inserir_ordenado_dia (Arvore * arvore, Registro *registro){
    Vertice * novo = cria_vertice(registro);
    if(arvore->raiz == NULL){
        arvore->raiz = novo;
    }
    else{
        Vertice * atual = arvore->raiz;
        Vertice * anterior = NULL;

        Vertice *vertice = encontra_posicao(arvore, registro, 4);

        if(novo->registro->Entrada->dia <= vertice->registro->Entrada->dia)
        {
            vertice->esq = novo;
            novo->pai = vertice;
        }
        else
        {
            vertice->dir = novo;
            novo->pai = vertice;
        }

    }
    arvore->qtde++;
}