#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cadastro.h"


void limpa_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

//Funcao para inicializar a lista  que contem a Elista. 
Lista * inicicializa_lista_cadastro()
{
    Lista *lista_cadastro = malloc(sizeof(Lista));
    lista_cadastro->inicio = NULL;
    lista_cadastro->qtde = 0;
    return lista_cadastro;
}

Registro * inicia_registro()
{
    Registro* registro = malloc(sizeof(registro));
    registro->Entrada = inicia_data();
}

//Funcao onde incializamos a Elista, que contem as informacoes de registro do paciente e a data que ele foi.
Elista * inicicializa_elista_cadastro(Registro * paciente)
{
    Elista *elista = malloc(sizeof(Elista));
    elista->dados = paciente;
    elista->proximo = NULL;
    return elista;
}

Data * inicia_data()
{
    Data *data = malloc(sizeof(Data));
    data->dia = 0;
    data->mes = 0;
    data->ano = 0;

    return data;
}

void inserir_lista_cadastro(Lista *lista, Registro * registro)
{
    Elista * novaElista = inicicializa_elista_cadastro(registro);
    Elista * atualElista = lista->inicio;

    lista->inicio = novaElista;
    novaElista->proximo = atualElista;

    lista->qtde ++;
}

void mostrar_lista_cadastro (Lista * lista)
{
    Elista * atual = lista->inicio;
    printf("PACIENTES CADASTRADOS:\n");
    while (atual != NULL )
    {
        printf("Nome: %s\n", atual->dados->nome);
        printf("Idade: %d\n",atual->dados->idade);
        printf("Documento: %s\n", atual->dados->rg);
        printf("Data de Entrada: %d/%.2d/%d",atual->dados->Entrada->dia, atual->dados->Entrada->mes, atual->dados->Entrada->ano);
        printf("\n----------------------------------------------------\n");
        atual = atual->proximo;
        
    }
    printf("\n");    
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
