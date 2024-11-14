#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cadastro.h"
#include "arvore.h"
#include "fila.h"

//Funcao menu, onde temos o print de todas as opcoes que o usuario podera escolher.
void menu()
{
    printf("MENU GERENCIAMENTO DE SAÚDE:\n");

    //Lista Dinamica Encadeada(cadastrar)
    printf("1  - Cadastrar Novo paciente:\n");
    printf("2  - Mostrar lista completa:\n");
    printf("3  - Consultar paciente cadastrado:\n");
    printf("4  - Atualizar dados do paciente:\n");
    printf("5  - Remover paciente da lista de cadastro:\n");

    //fila(Atendimento)
    printf("6  - Inserir paciente na fila.\n");
    printf("7  - Mostrar fila de atendimento.\n");
    printf("8  - Remover paciente da fila.\n");

    //Arvore binaria(Pesquisa)
    printf("9  - Mostrar ordenado por idade.\n");
    printf("10 - Mostrar ordenado por ano.\n");
    printf("11 - Mostrar ordenado por mes.\n");
    printf("12 - Mostrar ordenado por dia.\n");

    //Pilha
    printf("13 - Desfazer operacao.\n");

    //Operacao de carregar/salvar os registros.
    printf("14 - Carregar.\n");
    printf("15 - Salvar.\n");

    //Sobre
    printf("16 - Informacao dos desenvolvedores.\n");

    //Sai do programa
    printf("17 - Sair\n");
    printf("Digite o numero da acao que deseja realizar.\n");
}

//Funcao limpa_buffer usamos após solicitar alguma informacao para o usuario, com o proposito de nao pegar um espaco vazio.
void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}


void salvar_lista(Lista * lista) 
{
    FILE *arquivo = fopen("Arquivos/registrosArmazenados.txt", "wb");
    Elista * atual = lista->inicio;

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }

    fwrite(&(lista->quantidade), sizeof(int), 1, arquivo);

    while (atual != NULL) 
    {

        fwrite(atual->dados, sizeof(Registro), 1, arquivo);
        fwrite(atual->dados->Entrada, sizeof(Data), 1, arquivo);

        atual = atual->proximo;
    }

    fclose(arquivo);
}

void carregar_lista(Lista *lista, Arvore * arvore_idade, Arvore * arvore_dia, Arvore * arvore_mes, Arvore * arvore_ano) {
    FILE *arquivo = fopen("Arquivos/registrosArmazenados.txt", "rb"); 
    Queue * fila = cria_queue();

    int quantidade;

    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    fread(&quantidade, sizeof(int), 1, arquivo); 
    printf("\n %d REGISTROS CARREGADOS\n", quantidade);

    for (int i = 0; i < quantidade; i++) 
    {
        Registro * registro = inicia_registro();
        Data *data = inicia_data();  

        fread(registro, sizeof(Registro), 1, arquivo);
        fread(data, sizeof(Data), 1, arquivo);

        registro->Entrada = data;

        enqueue(fila, registro);
    }

    Celula * atual = fila->tail;
    while(atual != NULL)
    {
        inserir_lista_cadastro(lista, atual->registro);
        inserir_ordenado_idade(arvore_idade, atual->registro);
        inserir_ordenado_dia(arvore_dia, atual->registro);
        inserir_ordenado_mes(arvore_mes, atual->registro);
        inserir_ordenado_ano(arvore_ano, atual->registro);

        atual = atual ->anterior;
    }

    fclose(arquivo);
}

//Funcao confirma ira solicitar para que o usuario digite 1, essa funcao retorna o valor que o usuario digitou.
int confirma()
{
    int x;

    printf("Digite 1 para confirmar: ");
    scanf("%d", &x);
    system("cls");

    return x;

}

//Funcao aguarda retorno, fica em um loop chamando a funcao confirma, so ira sair quando o usuario realmente digitar o valor solicitado.
void aguarda_retorno()
{
    int x = 0;
    while(x != 1)
    {
        x = confirma();
    }
}

//Funcao que printa informacoes sobre os desenvolvedores, conforme solicitado durante o projeto.
void sobre(){
    system("cls");
    printf("INFORMACOES SOBRE OS DESENVOLVEDORES:\n");
    printf("Henrique Finatii RA:22.123.030-0\n");
    printf("Tiago Fagundes RA:22.123.017-0\n");
    printf("4 Ciclo\n");
    printf("Curso: Ciencia da Computacao\n");
    printf("Disciplina: Estrtura de dados\n");
    printf("Data: 11/11/2024\n\n");
    aguarda_retorno();
    
}