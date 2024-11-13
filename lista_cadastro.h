#ifndef LISTA_CADASTRO_H
#define LISTA_CADASTRO_H

//Declarando as estruturas solicitados para o desenvolvimento do projeto.

//Estrutura da Data
typedef struct 
{
    int dia;
    int mes;
    int ano;
} Data;

//Estrutura de Registro
typedef struct 
{
    char nome[100];
    char rg[15];
    int idade;
    Data * Entrada;
} Registro;

//Estrtura: Lista Dinâmica Encadeada, para realização do cadastro.
typedef struct Elista
{
    Registro * dados;
    struct Elista *proximo;

}Elista;

typedef struct 
{
    Elista * inicio;
    int quantidade;

}Lista;

//Declaracao das funcoes usadas na "bilioteca.c"

Data * inicia_data();
Lista * inicicializa_lista_cadastro();
Registro * inicia_registro();
Registro * encontra_paciente (Lista * lista, char rg[15]);
Elista * inicicializa_elista_cadastro(Registro * paciente);

void consulta_paciente(Lista * lista);
void inserir_lista_cadastro(Lista *lista, Registro * registro);
void atualiza_cadastro(Lista * lista);
void mostrar_lista_cadastro (Lista * lista);
void remover(Lista *lista, Registro * registro);

#endif //LISTA_CADASTRO_H