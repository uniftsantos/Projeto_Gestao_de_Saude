#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "arvore.h"
#include "lista_cadastro.h"
#include "biblioteca_geral.h"

int main(){

    int chek = 1;
    Lista *lista = inicicializa_lista_cadastro(); //Lista de cadastro

    Queue * fila = cria_queue(); //Lista de atendimento

    Arvore * arvore_idade = cria_arvore(); //arvore binaria ordenada pela idade
    Arvore * arvore_dia   = cria_arvore(); //arvore binaria ordenada pelo dia
    Arvore * arvore_mes   = cria_arvore(); //arvore binaria ordenada pelo mes
    Arvore * arvore_ano   = cria_arvore(); //arvpre binaria ordenada pelo ano

    while (chek)
    {
        
        Registro * paciente = inicia_registro();

        char nome[100];
        char rg[15];
        int idade, dia, mes, ano, opcao;

        menu();

        scanf("%d", &opcao);

        switch(opcao)
        {
            case(1):
                system("cls");

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

                inserir_ordenado_idade(arvore_idade, paciente);
                inserir_ordenado_ano(arvore_ano, paciente);
                inserir_ordenado_mes(arvore_mes, paciente);
                inserir_ordenado_dia(arvore_dia, paciente);

                printf("\nPaciente Cadastrado com sucesso.\n\n");
                aguarda_retorno();
            break;

            case(2):
                mostrar_lista_cadastro(lista);
            break;
            
            case(3):
                printf("Digite o RG do paciente que voce deseja consultar: \n");
                scanf("%s",&rg);
                limpa_buffer();

                Registro * r1 = encontra_paciente(lista, rg);

                if(r1 == NULL)
                {
                    printf("\nPaciente nao cadastrado\n\n");
                }
                else
                {
                    printf("Informacoes do paciente:\n");
                    printf("RG: %s\n",r1->rg);
                    printf("Nome: %s\n",r1->nome);
                    printf("Idade: %d\n",r1->idade);
                }
            break;

            case(4):
                atualiza_cadastro(lista);
            break;

            case(5):
                printf("Remocao de paciente:\n");
                printf("Digite o RG do paciente que voce deseja remover da lista: \n");
                scanf("%s",&rg);
                limpa_buffer();

                r1 = encontra_paciente(lista, rg);

                if(r1 == NULL)
                {
                    printf("O paciente que deseja remover nao existe na lista de cadastrado.\n\n");
                }
                else
                {
                    remover(lista,r1);
                    printf("Paciente removido com sucesso.\n");
                }
            break;

            case(6):
                printf("Digite RG do paciente cadastrado para insercao de atendimento: ");
                scanf("%s",&rg);
                limpa_buffer();

                r1 = encontra_paciente(lista, rg);

                if(r1 == NULL)
                {
                    printf("\nPaciente nao cadastrado\n\n");
                }
                else
                {
                    enqueue(fila,r1);
                    printf("\nPaciente cadastrado");
                }
            break;

            case(7):
                printf("Fila de atendimento:\n");
                Show(fila);
            break;

            case(8):
                printf("Paciente removido da fila de atendimento.\n");
                dequeue(fila);
            break;
            
            case(9):
                in_ordem(arvore_idade->raiz);
            break;
            
            case(10):
                in_ordem(arvore_ano->raiz);
            break;
            
            case(11):
                in_ordem(arvore_mes->raiz);
            break;
            
            case(12):
                in_ordem(arvore_dia->raiz);
            break;

            case(13):
                //CTRL Z
            break;
            
            case(14):
                carregar_lista(lista);
            break;

            case(15):
                salvar_lista(lista);
            break;

            case(16):
                //Sobre
            break;

            case(17):
                chek = 0;
            break;
            
        }    
    }
    system("cls");
    printf("Codigo encerrado.");
}