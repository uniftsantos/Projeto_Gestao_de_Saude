#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"
#include "lista_cadastro.h"
#include "biblioteca_geral.h"

//Funcao para inicializar a lista  que contem a Elista. 
Lista * inicicializa_lista_cadastro()
{
    Lista *lista_cadastro = malloc(sizeof(Lista)); //aloca dinamicamente

    lista_cadastro->inicio = NULL; //ponterio inicio comeca em null
    lista_cadastro->quantidade = 0; //ponteiro para quantidade comeca com 0

    return lista_cadastro; //retorna uma Lista
}

//Funcao para iniciliziar nosso registro, que contem informacoes do paciente.
Registro * inicia_registro()
{
    Registro* registro = malloc(sizeof(Registro)); //aloca dinamicamente
    registro->Entrada = inicia_data(); //ponteiro para Entrada recebe a funcao que inicializa a data.

    return registro; //retorna um Registro
}

//Funcao para inicializar a Data de entrada do paciente.
Data * inicia_data()
{
    Data *data = malloc(sizeof(Data)); //aloca dinamicamente
    data->dia = 0; //ponteiro dia comeca com 0
    data->mes = 0; //ponteiro mes comeca com 0
    data->ano = 0; //ponteiro ano comeca com 0

    return data; //retorna uma Data
}

//Funcao onde incializamos a Elista, que contem as informacoes de registro do paciente e a data que ele foi.
Elista * inicicializa_elista_cadastro(Registro * paciente)
{
    Elista *elista = malloc(sizeof(Elista)); //aloca dinamicamente

    elista->dados = paciente; //ponteiro dados recebe o Registro
    elista->proximo = NULL; //ponteiro proximo comeca com null

    return elista; //Retorna uma Elista
}


//Funcao que insere o registro na lista de cadastro, e como solicitado sempre fazemos a insercao no inicio da lista. E aumentamos
// a quantidade de dados dentro da lista.
void inserir_lista_cadastro(Lista *lista, Registro * registro)
{
    Elista * novaElista = inicicializa_elista_cadastro(registro);
    Elista * atualElista = lista->inicio;

    lista->inicio = novaElista;
    novaElista->proximo = atualElista;

    lista->quantidade++;
}

//Funcao que percorre a nossa lista de cadastro e vai printando as informacoes do paciente.
void mostrar_lista_cadastro(Lista * lista)
{
    system("cls");//Limpa o terminal
    if(lista->quantidade == 0)//verifica se a lista cadastro esta vazia
    {
        printf("Lista de cadastro vazia.\n");
    }
    else
    {
        Elista * atual = lista->inicio;

        printf("PACIENTES CADASTRADOS:\n\n");

        while (atual != NULL )//percorre a Lista.
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
   //chamada da funcao que se encontra na "biblioteca_geral.c/h", esta comentado.
   aguarda_retorno();
   system("cls");//Limpa terminal
}

//Funcao que remove um registro solicitado pelo usuario.
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
        while(atual->proximo != NULL && atual->dados->rg != registro->rg)// loop para percorrer nossa lista.
        {
            anterior = atual;
            atual = atual->proximo;
        }

        if(atual->proximo == NULL)
        {//removendo o ultimo elemento.
            free(atual);
            anterior->proximo = NULL;

        }

        else
        {//removendo elemento no meio da lista.
            anterior->proximo = atual->proximo;
            free(atual);
        }

    }
    lista->quantidade--; //diminuindo a quantidade de elementos da nossa lista.
}

//Funcao resposavel por procurar se existe o rg solicitado pelo usuario na nossa lista cadastro, e caso encontre esse elemento
// ira retornar um Registro.
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

//Funcao de consultar o paciente na lista, sera solicitado ao usuario o RG do cara que ele quer consultar.
void consulta_paciente(Lista * lista)
{
    system("cls");
    char rg[15];

    printf("Digite o RG do paciente que deseja buscar: ");
    scanf("%s",&rg);
    limpa_buffer();

    Registro * r1 = encontra_paciente(lista, rg);

    if(r1 == NULL)
    {
        printf("\nPaciente nao cadastrado\n\n");
    }
    else
    {   
        printf("------------------------------\n");
        printf("Informacoes do paciente:\n\n");
        printf("RG: %s\n",r1->rg);
        printf("Nome: %s\n",r1->nome);
        printf("Idade: %d\n",r1->idade);
        printf("------------------------------\n");
    }
    aguarda_retorno();
}

//Funcao para atualizar o cadastro do paciente. para essa etapa iremos pedir todas as informacoes novamente ao usuario.
void atualiza_cadastro(Lista * lista)
{   
    system("cls");
    printf("Atualizar os dados do paciente:\n\n");

    char rg[15];
    int idade, dia, mes, ano;
    char nome[100];

    printf("Digite o RG do paciente que voce deseja atualizar: \n");
    scanf("%s", &rg);
    limpa_buffer();

    Registro * r1 = encontra_paciente(lista, rg);

    if(r1 == NULL)
    {    
        printf("Paciente nao cadastrado\n\n");
    }
    else
    {//Solicitando informacoes.
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
        //Passando os valores para a struct Registro.
        strcpy(r1->nome, nome);
        strcpy(r1->rg, rg);
        r1->idade = idade;
        r1->Entrada->ano = ano;
        r1->Entrada->mes = mes;
        r1->Entrada->dia = dia;

        printf("\nInformacoes atualizadas\n\n");
    }

    aguarda_retorno();
}