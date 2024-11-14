#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

//Funcao responsavel por inicializar a nossa struct Vertice.
Vertice *cria_vertice(Registro * registro)
{
	Vertice* novo = malloc(sizeof(Vertice)); //aloca dinamicamente

	novo->direito = NULL; //ponteiro para fiho_direito comeca null
	novo->esquerdo = NULL; //ponterio para filho_esquerdo comeca null
    novo->pai = NULL; //ponteiro pai recebe null

	novo->registro = registro; //ponteiro do registro recebe o paremetro da funcao
	
	return novo;
}

//Funcao responsavel por inicializar a nossa struct Arvore.
Arvore *cria_arvore()
{
	Arvore* arvore = malloc(sizeof(Arvore)); //aloca dinamicamente

	arvore->raiz = NULL; //ponteiro para raiz comeca null
	arvore->quantidade = 0; //ponteiro para quantidade comeca em 0

	return arvore;
}

//Funcao responsavel por printar as informacoes que estao no Registro.
void visitar (Vertice * vertice)
{
    printf("Nome: %s\n", vertice->registro->nome);
    printf("RG: %s\n", vertice->registro->rg);
    printf("Idade: %d\n",vertice->registro->idade);
    printf("Data de Entrada: %.2d/%.2d/%d\n\n",vertice->registro->Entrada->dia,vertice->registro->Entrada->mes, vertice->registro->Entrada->ano);
}

//Funcao responsavel por percorrer nossa arvore em ordem crescente.(funcao recursiva, dentro dela chamos a funcao visitar).
void in_ordem(Vertice *raiz)
{
    if(raiz != NULL)
    {
        in_ordem(raiz->esquerdo);
        visitar(raiz);
        in_ordem(raiz->direito);
    }
}



//Função que encontra a posição de inserção de um novo registro na arvore.
Vertice *encontra_posicao(Arvore *arvore, Registro * registro, int orientacao)
{
    Vertice *atual = arvore->raiz;
    Vertice *anterior = NULL;

    while(atual != NULL){//loop para percorrer a arvore.

        
        if(orientacao == 1) //se for 1 compara pela idade.
        {
            if(registro->idade <= atual->registro->idade)//move para o filho esquerdo se a idade for menor ou igual
            {   
                anterior = atual;
                atual = atual->esquerdo;
            }
            else
            {//move para o filho direito.
                anterior = atual;
                atual = atual->direito;
            }
        }
        else if(orientacao == 2) //se for 2 compara pelo ano.
        {
            if(registro->Entrada->ano <= atual->registro->Entrada->ano)//move para o filho esquerdo se o ano for menor ou igual
            {   
                anterior = atual;
                atual = atual->esquerdo;
            }
            else
            {//move para o filho direito.
                anterior = atual;
                atual = atual->direito;
            }
        }
        else if(orientacao == 3)//se for 3 compara pelo mês.
        {
            if(registro->Entrada->mes <= atual->registro->Entrada->mes)//move para o filho esquerdo se o mes for menor ou igual
            {   
                anterior = atual;
                atual = atual->esquerdo;
            }
            else
            {//move para o filho direito.
                anterior = atual;
                atual = atual->direito;
            }
        }else if(orientacao == 4)//se for 4 compara pelo dia.
        {
            if(registro->Entrada->dia <= atual->registro->Entrada->dia)//move para o filho esquerdo se o dia for menor ou igual
            {   
                anterior = atual;
                atual = atual->esquerdo;
            }
            else
            {//move para o filho direito.
                anterior = atual;
                atual = atual->direito;
            }
        }
    }
    return anterior;
}

//Funcao de insercao ordenada pela idade: se a proxima idade a ser inserida for menor que a idade que se encontra no 'pai', 
//sera inserido na esquerda caso contrario, sera inserido na direita e aumentamos a quantidade de elementos na arvore.
void inserir_ordenado_idade(Arvore *arvore, Registro *registro)
{
    Vertice *novo = cria_vertice(registro);

    if(arvore->quantidade == 0)
    {
        arvore->raiz = novo;  
        novo->pai = NULL;      
    }
    else
    {
        Vertice *vertice = encontra_posicao(arvore, registro, 1);//chamando a funcao que encontra a posicao de insercao

        if(novo->registro->idade <= vertice->registro->idade)
        {
            vertice->esquerdo = novo;
            novo->pai = vertice;
        }
        else
        {
            vertice->direito = novo;
            novo->pai = vertice;
        }

    }
    arvore->quantidade++;
}

//Funcao de insercao ordenada pelo ano: se o proximo ano a ser inserido for menor que o ano que se encontra no 'pai', 
//sera inserido na esquerda caso contrario, sera inserido na direita e aumentamos a quantidade de elementos na arvore.
void inserir_ordenado_ano (Arvore * arvore, Registro *registro)
{
    Vertice * novo = cria_vertice(registro);

    if(arvore->raiz == NULL)
    {
        arvore->raiz = novo;
    }
    else
    {        
        Vertice *vertice = encontra_posicao(arvore, registro, 2);//chamando a funcao que encontra a posicao de insercao

        if(novo->registro->Entrada->ano <= vertice->registro->Entrada->ano)
        {
            vertice->esquerdo = novo;
            novo->pai = vertice;
        }
        else
        {
            vertice->direito = novo;
            novo->pai = vertice;
        }

    }
    arvore->quantidade++;
}

//Funcao de insercao ordenada pelo mes: se o proximo mes a ser inserido for menor que o mes que se encontra no 'pai', 
//sera inserido na esquerda caso contrario, sera inserido na direita e aumentamos a quantidade de elementos na arvore.
void inserir_ordenado_mes (Arvore * arvore, Registro *registro)
{
    Vertice * novo = cria_vertice(registro);

    if(arvore->raiz == NULL)
    {
        arvore->raiz = novo;
    }
    else
    {
        Vertice *vertice = encontra_posicao(arvore, registro, 3);//chamando a funcao que encontra a posicao de insercao

        if(novo->registro->Entrada->mes <= vertice->registro->Entrada->mes)
        {
            vertice->esquerdo = novo;
            novo->pai = vertice;
        }
        else
        {
            vertice->direito = novo;
            novo->pai = vertice;
        }

    }
    arvore->quantidade++;
}

//Funcao de insercao ordenada pelo dia: se o proximo dia a ser inserido for menor que o dia que se encontra no 'pai', 
//sera inserido na esquerda caso contrario, sera inserido na direita e aumentamos a quantidade de elementos na arvore.
void inserir_ordenado_dia (Arvore * arvore, Registro *registro)
{
    Vertice * novo = cria_vertice(registro);

    if(arvore->raiz == NULL){
        arvore->raiz = novo;
    }
    else
    {
        Vertice *vertice = encontra_posicao(arvore, registro, 4);//chamando a funcao que encontra a posicao de insercao

        if(novo->registro->Entrada->dia <= vertice->registro->Entrada->dia)
        {
            vertice->esquerdo = novo;
            novo->pai = vertice;
        }
        else
        {
            vertice->direito = novo;
            novo->pai = vertice;
        }

    }
    arvore->quantidade++;
}