#include "lista_cadastro.h"
#include "pilha.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

//Funcao para inicializar a celula que contem o Registro;
Celula_pilha * criar_celula(Registro* registro)
{
    Celula_pilha *celula = malloc(sizeof(Celula_pilha)); //aloca dinamicamente

    celula->registro = registro; //ponteiro para o registro ira receber o parametro da funcao.
    celula->proximo = NULL; //ponterio para o proximo recebe null
    celula->flag_opercao = 0; //ponterio para o flag_opercao comeca com 0

    return celula; //retorna uma Celula_pilha
}

//Funcao para inicializar a nossa pilha que ira conter as Celulas
Stack * criar_pilha()
{
    Stack * pilha = malloc(sizeof(Stack)); //aloca dinamicamente

    pilha->topo = NULL; //ponteiro para o topo recebe null
    pilha ->qtde = 0; //ponteiro para qtd comeca com 0.

    return pilha; //retorna uma Stack
}

//Funcao push serve para inserir de todas as instrucoes feitas na fila, dentro da pilha. Usamos mais um parametro tambem para saber o 
//tipo de operacao que foi realizado na fila:
//insecao ou remocao, pois na hora de usar o "ctrl + z" precisamos diferenciar um do outro pois sao maneiras diferentes de desfazer 
// a ultima instrucao (1= insercao e 0 = remocao).

void push(Stack *pilha, Registro* registro, int flag)//Insercao sempre feita no topo
{
    Celula_pilha * novo = criar_celula(registro);
    novo->proximo = pilha->topo;
    novo->flag_opercao = flag;

    pilha->topo = novo; //ponteiro do topo apontando para o novo Registro
    pilha->qtde++; //aumentando a quantidade 
}

//Funcao pop ira remover o Registro que se esta na Pilha.
Registro *pop(Stack*pilha)
{
    if(pilha->qtde ==0)//verifica se a quantidade for 0.
    {
        printf("Stack underflow");
        return NULL;
    }

    Registro * registro = pilha->topo->registro; // pegando o Registro
    Celula_pilha * temp = pilha->topo; //armazena o valor que esta no topo.

    pilha->topo = pilha->topo->proximo; // ponteiro do topo recebe o elemento que esta 'abaixo' dele dentro da pilha.
    pilha->qtde--; //diminui a quantidade de elementos que estavam na pilha

    free(temp); //libera o valor na memoria
    return registro;
}

//Funcao Show, que ira percorrer nossa pilha e printa o rg dos elementos, usamos essa funcao para debug.
void show(Stack * pilha)
{
    Celula_pilha * atual = pilha->topo;
    printf("TOPO-> ");
    while(atual != NULL)
    {
        printf("%s ", atual->registro->rg);
        atual = atual->proximo;
    }
    printf("<- Base\n");
}

void desafazer(Stack * pilha, Queue * fila)
{
    if(pilha->qtde != 0)
    {
        if(pilha->topo->flag_opercao == 1)
        {
            Celula * temp = fila->tail;

            if(fila->qtde == 1)
            {
                fila->head = NULL;
                fila->tail = NULL;
            }
            else if(fila->qtde > 1)
            {
                temp->anterior->proximo = NULL;
                fila->tail = temp->anterior;
            }
            pop(pilha);
            free(temp);

            fila->qtde--;   
        }
        else
        {
            Celula * novo = cria_celula(pilha->topo->registro);
            Celula * temp = fila->head;
                
            fila->head = novo;
            fila->head->proximo = temp;
            temp->anterior = novo;
            fila->qtde++;

            pop(pilha);
        }
    }
    
}