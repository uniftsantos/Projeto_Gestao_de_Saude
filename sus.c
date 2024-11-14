#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "arvore.h"
#include "lista_cadastro.h"
#include "biblioteca_geral.h"
#include "pilha.h"

int main(){

    int chek = 1;
    Lista *lista = inicicializa_lista_cadastro(); //Lista de cadastro

    Queue * fila = cria_queue(); //Lista de atendimento

    Arvore * arvore_idade = cria_arvore(); //arvore binaria ordenada pela idade
    Arvore * arvore_dia   = cria_arvore(); //arvore binaria ordenada pelo dia
    Arvore * arvore_mes   = cria_arvore(); //arvore binaria ordenada pelo mes
    Arvore * arvore_ano   = cria_arvore(); //arvpre binaria ordenada pelo ano

    Stack * pilha = criar_pilha();

    while (chek)
    {
        Registro * paciente = inicia_registro(); //Inicialiazando nosso registro toda vez que o loop acabar.

        char nome[100];
        char rg[15];
        int idade, dia, mes, ano, opcao;

        menu();

        scanf("%d", &opcao);

        switch(opcao)
        {
            case(1): //opcao 1, cadastro o usuario na lista.
                system("cls");
                //solicitando todas as informacoes necessarias.
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

                Registro *x = encontra_paciente(lista, rg); //Consultamos se esse RG existe na lista atual
                int y = consulta_arquivo(rg); //Consultamos se esse RG existe no arquivo

                if(x == NULL || y == 1)
                {
                    printf("Ja existe um paciente cadastrado com esse RG\n");
                }
                else
                {
                    inserir_lista_cadastro(lista, paciente); //insere na lista de cadastro.
                    inserir_ordenado_idade(arvore_idade, paciente); //insere na arvore de idade
                    inserir_ordenado_ano(arvore_ano, paciente);//insere na arvore de ano
                    inserir_ordenado_mes(arvore_mes, paciente);//insere na arvore de mes
                    inserir_ordenado_dia(arvore_dia, paciente);//insere na arvore de dia

                    printf("\nPaciente Cadastrado com sucesso.\n\n");
                }

                aguarda_retorno();
            break;

            case(2):
                mostrar_lista_cadastro(lista); //mostra todos os pacientes cadastrados.
            break;
            
            case(3):
                consulta_paciente(lista);//funcao de consultar paciente especifico ja existente na lista
            break;

            case(4):
                atualiza_cadastro(lista);//funcao de atualizar cadastro ja existente na lista.
            break;

            case(5):
                printf("Remocao de paciente:\n");
                printf("Digite o RG do paciente que voce deseja remover da lista: \n");
                scanf("%s",&rg);//solicita ao usuario o rg que ele quer remover.
                limpa_buffer();

                Registro * r1 = encontra_paciente(lista, rg);//vai retornar o Registro caso esse rg exista na lista_cadastro


                if(r1 == NULL)
                {
                    printf("O paciente que deseja remover nao existe na lista de cadastrado.\n\n");
                }
                else
                {
                    remover(lista,r1);//removendo o paciente da lista.
                    printf("Paciente removido com sucesso.\n");
                }
            break;

            case(6):
                printf("Digite RG do paciente cadastrado para insercao de atendimento: "); 
                scanf("%s",&rg);//solicita ao usuario um rg para inserir na fila
                limpa_buffer();

                r1 = encontra_paciente(lista, rg); //vai retornar o Registro caso esse rg exista na lista_cadastro

                if(r1 == NULL)
                {
                    printf("\nPaciente nao cadastrado\n\n");
                }
                else
                {
                    enqueue(fila,r1); //enfilera
                    push(pilha, r1, 1); //salva na pilha para realizar o ctrl + z
                    printf("\nPaciente cadastrado\n\n");
                }
            break;

            case(7):
                if(fila->qtde == 0){//Verificao se a fila esta vazia.
                    printf("Nao ha pacientes na fila.\n\n");
                }
                else{
                    Show(fila); //printa todos os elementos da fila.
                }
            break;

            case(8):
                if(fila->qtde > 0) push(pilha, fila->head->registro, 0);//verifacao se a fila esta vazia para poder desenfilerar.
                dequeue(fila); //desenfilerar a fila
            break;
            
            case(9):
                in_ordem(arvore_idade->raiz); //mostra ordenado pela idade
            break;
            
            case(10):
                in_ordem(arvore_ano->raiz); //mostra ordenado pelo ano
            break;
            
            case(11):
                in_ordem(arvore_mes->raiz); //mostra ordenado pelo mes
            break;
            
            case(12):
                in_ordem(arvore_dia->raiz); //mostra ordenado pelo dia
            break;

            case(13):
                desafazer(pilha, fila); // ctrl + z
            break;
            
            case(14):
                carregar_lista(lista, arvore_idade, arvore_dia, arvore_mes, arvore_ano);//carrega os registros para a lista_cadastro.
            break;

            case(15):
                salvar_lista(lista); //salvando os cadastros atuais na nossa lista_cadastro no "registrosArmazenados.txt"
            break;

            case(16):
                sobre();//chamando funcao que printa as informacoes sobre os desenvolvedores.
            break;

            case(17):
                chek = 0; // para acabar com o codigo, encerrando o loop.
            break;
            
        }    
    }
    system("cls");
    printf("Codigo encerrado.");
}