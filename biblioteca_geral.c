#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cadastro.h"

void menu()
{
    printf("MENU GERENCIAMENTO DE SAÚDE:\n");

    //Lista Dinamica Encadeada(cadastrar)
    printf("1 - Cadastrar Novo paciente:\n");
    printf("2 - Mostrar lista completa:\n");
    printf("3 - Consultar paciente cadastrado:\n");
    printf("4 - Atualizar dados do paciente:\n");
    printf("5 - Remover paciente da lista de cadastro:\n");

    //fila(Atendimento)
    printf("6 - Inserir paciente na fila.\n");
    printf("7 - Mostrar fila de atendimento.\n");
    printf("8 - Remover paciente da fila.\n");

    //Arvore binaria(Pesquisa)
    printf("9  - Insercao da arvora ordenada por idade.\n");
    printf("10 - Insercao da arvore ordenada por ano.\n");
    printf("11 - Insercao da arvore ordenada por mes.\n");
    printf("12 - Insercao da arvore ordenada por dia.\n");

    printf("10 - Pesquisa paciente.\n");
    printf("11 - Desfazer operação.\n");
    printf("12 - Carregar/Salvar.\n");
    printf("13 - Informacao dos desenvolvedores.\n");
    printf("14 - Sair\n");
    printf("Digite o numero da acao que deseja realizar.\n");
}
void limpa_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}