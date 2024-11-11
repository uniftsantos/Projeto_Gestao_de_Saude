#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cadastro.h"
#include "biblioteca_geral.h"
#include "arvore.h"

//Funcao para inicializar a lista  que contem a Elista. 
Lista * inicicializa_lista_cadastro()
{
    Lista *lista_cadastro = malloc(sizeof(Lista));

    lista_cadastro->inicio = NULL;
    lista_cadastro->quantidade = 0;

    return lista_cadastro;
}

Registro * inicia_registro()
{
    Registro* registro = malloc(sizeof(Registro));
    registro->Entrada = inicia_data();

    return registro;
}

Data * inicia_data()
{
    Data *data = malloc(sizeof(Data));
    data->dia = 0;
    data->mes = 0;
    data->ano = 0;

    return data;
}

//Funcao onde incializamos a Elista, que contem as informacoes de registro do paciente e a data que ele foi.
Elista * inicicializa_elista_cadastro(Registro * paciente)
{
    Elista *elista = malloc(sizeof(Elista));

    elista->dados = paciente;
    elista->proximo = NULL;

    return elista;
}



void inserir_lista_cadastro(Lista *lista, Registro * registro)
{
    Elista * novaElista = inicicializa_elista_cadastro(registro);
    Elista * atualElista = lista->inicio;

    lista->inicio = novaElista;
    novaElista->proximo = atualElista;

    lista->quantidade++;
}

void mostrar_lista_cadastro (Lista * lista)
{
    system("cls");
    if(lista->quantidade == 0)
    {
        printf("Lista de cadastro vazia.\n");
    }
    else
    {
        Elista * atual = lista->inicio;

        printf("PACIENTES CADASTRADOS:\n\n");

        while (atual != NULL )
        {
            printf("Nome: %s\n", atual->dados->nome);
            printf("Idade: %d\n",atual->dados->idade);
            printf("Documento: %s\n", atual->dados->rg);
            printf("Data de Entrada: %.2d/%.2d/%d\n",atual->dados->Entrada->dia, atual->dados->Entrada->mes, atual->dados->Entrada->ano);
            printf("\n----------------------------------------------------\n");
            atual = atual->proximo;    
        }
        printf("\n");    
    }
   
   aguarda_retorno();
   system("cls");
}

void remover(Lista *lista, Registro * registro)
{
    Elista *atual = lista->inicio;
    Elista *anterior = NULL;

    if(atual->dados->rg == registro->rg)
    {

      if(lista->quantidade == 1)
      {
        //apagando quando temos apenas um cara.
        free(lista->inicio);
        lista->inicio = NULL;
      }
      else
      {
        //apagando o primeiro elemento da lista, independente do tamanho.
        lista->inicio = atual->proximo;
        free(atual);
      }
    }
 

    else
    { 
        while(atual->proximo != NULL && atual->dados->rg != registro->rg)
        {//percorre nossa lista;
            anterior = atual;
            atual = atual->proximo;
        }

        if(atual->proximo == NULL)
        {//removendo o ultimo elemento.
            free(atual);
            anterior->proximo = NULL;

        }

        else
        {
            anterior->proximo = atual->proximo;
            free(atual);
        }

    }
    lista->quantidade--;
}

Registro *encontra_paciente (Lista * lista, char rg[15])
{
    Elista * atual = lista->inicio;
    while(atual != NULL && strcmp(atual->dados->rg, rg) != 0)
    {
        atual = atual->proximo;
    }

    if(atual != NULL) 
        return atual->dados;
    
    return NULL;
}


void atualiza_cadastro(Lista * lista)
{   
    printf("Atualizar os dados do paciente:\n");

    char rg[15];
    int idade;
    int dia;
    int mes;
    int ano;
    char nome[100];

    printf("Digite o RG do paciente que voce deseja atualizar: \n");
    scanf("%s", &rg);
    limpa_buffer();

    Registro * r1 = encontra_paciente(lista, rg);

    if(r1 == NULL)
    {    
        printf("Paciente não cadastrado\n\n");
    }
    else
    {
        printf("Digite seu nome: ");
        scanf("%s", &nome);
        limpa_buffer();

        printf("\nDigite sua idade: ");
        scanf("%d", &idade);

        printf("\nDigite seu documento: ");
        scanf("%s", &rg);
        limpa_buffer();

        printf("\nDigite dia de entrada: ");
        scanf("%d", &dia);
        
        printf("Digite mes de entrada: ");
        scanf("%d", &mes);
        
        printf("Digite ano de entrada: ");
        scanf("%d", &ano);

        strcpy(r1->nome, nome);
        strcpy(r1->rg, rg);
        r1->idade = idade;
        r1->Entrada->ano = ano;
        r1->Entrada->mes = mes;
        r1->Entrada->dia = dia;
    }
}