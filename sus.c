#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cadastro.h"

int main(){

    Lista *lista = inicicializa_lista_cadastro();
    while (1)
    {
        printf("MENU GERENCIAMENTO DE SAÚDE:\n");
        printf("1 - Cadastrar Novo paciente.\n");
        printf("2 - Fila de atendimento.\n");
        printf("3 - Pesquisa paciente.\n");
        printf("4 - Desfazer operação.\n");
        printf("5 - Carregar/Salvar.\n");
        printf("6 - Informacao dos desenvolvedores.\n");
        printf("7 - Sair\n");
        printf("Digite o numero da acao que deseja realizar.\n");

        int opcao;
        scanf("%d", &opcao);

        if(opcao == 1){
            Registro paciente;
            Data *data = inicia_data();
            char nome[100];
            char rg[15];
            int idade;
            int dia;
            int mes;
            int ano;

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

            // Atribuição aos campos da estrutura
            data->dia = dia;
            data->mes = mes;
            data->ano = ano;

            // Copia valores para a estrutura paciente
            strcpy(paciente.nome, nome);
            paciente.idade = idade;
            strcpy(paciente.rg, rg);
            paciente.Entrada = data;
            inserir_lista_cadastro(lista,paciente);
            mostrar_lista_cadastro(lista);
        }
        if(opcao ==7){            
            printf("Saindo do programa");
            break;
        }

    
    }
    
}