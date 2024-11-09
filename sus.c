#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cadastro.h"
#include "fila.h"
#include "biblioteca_geral.h"
#include "arvore.h"

int main(){

    Lista *lista = inicicializa_lista_cadastro(); //Lista de cadastro

    Queue * fila = cria_queue(); //Lista de atendimento
    Arvore * arvore = cria_arvore();

    while (1)
    {
        Registro * paciente = inicia_registro();
        Data *data = inicia_data();
        char nome[100];
        char rg[15];
        int idade;
        int dia;
        int mes;
        int ano;
        int opcao;

        printf("MENU GERENCIAMENTO DE SAÚDE:\n");
        printf("1 - Cadastrar Novo paciente.\n");
        printf("2 - Inserir paciente na fila.\n");
        printf("3 - Mostrar fila de atendimento.\n");
        printf("4 - Remover paciente da fila.\n");
        printf("5 - Insercao da arvora ordenada por idade.\n");

        printf("3 - Pesquisa paciente.\n");
        printf("4 - Desfazer operação.\n");
        printf("5 - Carregar/Salvar.\n");
        printf("6 - Informacao dos desenvolvedores.\n");
        printf("7 - Sair\n");
        printf("Digite o numero da acao que deseja realizar.\n");

        scanf("%d", &opcao);

        if(opcao == 1){
            

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
            paciente->Entrada->dia = dia;
            paciente->Entrada->mes = mes;
            paciente->Entrada->ano = ano;
            paciente->idade = idade;

            // Copia valores para a estrutura paciente
            strcpy(paciente->nome, nome);
            strcpy(paciente->rg, rg);

            inserir_lista_cadastro(lista, paciente);
            mostrar_lista_cadastro(lista);
        }

        else if(opcao == 2)
        {

            printf("Digite RG do paciente cadastrado para insercao de atendimento: ");
            scanf("%s",&rg);
            limpa_buffer();

            Registro * r1 = encontra_paciente(lista, rg);

            if(r1 == NULL)
            {
                printf("\nPaciente nao cadastrado\n");
            }
            else
            {
                enqueue(fila,r1);
                printf("\nPaciente cadastrado");
            }
        }

        else if (opcao ==3){
            printf("Fila de atendimento:\n");
            Show(fila);
        }

        else if (opcao ==4){
            printf("Paciente removido da fila de atendimento.\n");
            dequeue(fila);
        }

        else if (opcao ==5){
            printf("Digite RG do paciente cadastrado para insercao da arvore ordenada por idade: ");
            scanf("%s",&rg);
            limpa_buffer();

            Registro * r1 = encontra_paciente(lista, rg);

            if(r1== NULL){
                printf("\nPaciente nao cadastrado.\n");
            }
            else{
                inserir_ordenado_idade(arvore,r1);
                printf("\na\n\n");
                in_ordem(arvore->raiz);
            }


        }

        if(opcao ==7){            
            printf("Saindo do programa");
            break;
        }

    
    }
    
}