#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cadastro.h"


//Declarando as estruturas solicitados para o desenvolvimento do projeto.

// typedef struct {
//     int dia;
//     int mes;
//     int ano;
// } Data;


// typedef struct {
//     char nome[100];
//     int idade;
//     char rg[15];
//     Data * Entrada;

// } Registro;



// //Estrtura: Lista Dinâmica Encadeada, para realização do cadastro.

// typedef struct Elista{
//     Registro dados;
//     struct Elista *proximo;

// }Elista;

// typedef struct {
//     Elista * inicio;
//     int qtde;

// }Lista;



int main(){

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
            Lista *lista = inicicializa_lista_cadastro();
            Registro paciente;
            Data data;
            char nome[100];
            char rg[15];
            int idade;
            int dia;
            int mes;
            int ano;
            printf("Digite seu nome: ");
            fgets(nome, sizeof(nome), stdin);
            limpa_buffer();
            // nome[strcspn(nome, "\n")] = '\0';
            

            // Entrada para idade
            printf("\nDigite sua idade: ");
            scanf("%d", &idade);
            // while(getchar() != '\n'); // Limpa o buffer
            limpa_buffer();

            // Entrada para RG
            printf("\nDigite seu documento: ");
            fgets(rg, sizeof(rg), stdin);
            limpa_buffer();
            // rg[strcspn(rg, "\n")] = '\0'; // Remove o newline ao final

            // Entrada para data de entrada
            printf("\nDigite dia de entrada: ");
            scanf("%d", &dia);
            limpa_buffer();
           
            printf("Digite mes de entrada: ");
            scanf("%d", &mes);
            limpa_buffer();
           
            printf("Digite ano de entrada: ");
            scanf("%d", &ano);
            limpa_buffer();

            // Atribuição aos campos da estrutura
            data.dia = dia;
            data.mes = mes;
            data.ano = ano;

            // Copia valores para a estrutura paciente
            strcpy(paciente.nome, nome);
            paciente.idade = idade;
            strcpy(paciente.rg, rg);
            paciente.Entrada = &data;
            inserir_lista_cadastro(lista,paciente);
            mostrar_lista_cadastro(lista);



        }
        if(opcao ==7){
            //Lista *lista = inicicializa_lista_cadastro();
            
            printf("Saindo do programa");
            break;
        }

    
    }
    
    // Lista *lista = inicicializa_lista_cadastro();
    // Registro p1;
    // Registro p2;
    // Data d1;

    // d1.dia = 19;
    // d1.mes = 06;
    // d1.ano = 2007;

    // strcpy(p1.nome, "Tiago Fagundes");
    // p1.idade = 20;
    // strcpy(p1.rg, "12345");
    // p1.Entrada = &d1;

    // strcpy(p2.nome, "Henrique Finatti");
    // p2.idade = 19;
    // strcpy(p2.rg, "54321");
    // p2.Entrada = &d1;

    // inserir_lista_cadastro(lista, p1);
    // inserir_lista_cadastro(lista,p2);

    // mostrar_lista_cadastro(lista);

    

   




}