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
        printf("9 - Insercao da arvora ordenada por idade.\n");

        printf("10 - Pesquisa paciente.\n");
        printf("11 - Desfazer operação.\n");
        printf("12 - Carregar/Salvar.\n");
        printf("13 - Informacao dos desenvolvedores.\n");
        printf("14 - Sair\n");
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
            printf("\nPaciente Cadastrado com sucesso.\n\n");
        }

        else if(opcao == 2){
            printf("LISTA CADASTRO:\n");
            mostrar_lista_cadastro(lista);

        }

        else if (opcao == 3){
            printf("Digite o RG do paciente que voce deseja consultar: \n");
            scanf("%s",&rg);
            limpa_buffer();

            Registro * r1 = encontra_paciente(lista, rg);

            if(r1 == NULL){
                printf("\nPaciente nao cadastrado\n\n");
            }
            else{
                printf("Informacoes do paciente:\n");
                printf("RG: %s\n",r1->rg);
                printf("Nome: %s\n",r1->nome);
                printf("Idade: %d\n",r1->idade);
                printf("Data de Entrada: %.2d/%.2d/%d\n\n", r1->Entrada->dia, r1->Entrada->mes, r1->Entrada->ano);
            }

        }

        else if (opcao == 4){
            printf("Atualizar os dados do paciente:\n");
        }

        else if (opcao == 5){
            printf("Remocao de paciente:\n");
            printf("Digite o RG do paciente que voce deseja remover da lista: \n");
            scanf("%s",&rg);
            limpa_buffer();

            Registro * r1 = encontra_paciente(lista, rg);

            if(r1 == NULL){
                printf("O paciente que deseja remover nao existe na lista de cadastrado.\n\n");
            }
            else{
                remover(lista,r1);
                printf("Paciente removido com sucesso.\n");

            }
            
        }

        else if(opcao == 6)
        {

            printf("Digite RG do paciente cadastrado para insercao de atendimento: ");
            scanf("%s",&rg);
            limpa_buffer();

            Registro * r1 = encontra_paciente(lista, rg);

            if(r1 == NULL)
            {
                printf("\nPaciente nao cadastrado\n\n");
            }
            else
            {
                enqueue(fila,r1);
                printf("\nPaciente cadastrado");
            }
        }

        else if (opcao ==7){
            printf("Fila de atendimento:\n");
            Show(fila);
        }

        else if (opcao ==8){
            printf("Paciente removido da fila de atendimento.\n");
            dequeue(fila);
        }

        else if (opcao ==9){
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

        if(opcao ==14){            
            printf("Saindo do programa");
            break;
        }

    
    }
    
}