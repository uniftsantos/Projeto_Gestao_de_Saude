#ifndef LISTA_CADASTRO_H
#define LISTA_CADASTRO_H

//Para facilitar na hora do input:
void limpa_buffer();

//Declarando as estruturas solicitados para o desenvolvimento do projeto.

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;


typedef struct {
    char nome[100];
    int idade;
    char rg[15];
    Data * Entrada;

} Registro;


//Estrtura: Lista Dinâmica Encadeada, para realização do cadastro.
typedef struct Elista{
    Registro dados;
    struct Elista *proximo;

}Elista;

typedef struct {
    Elista * inicio;
    int qtde;

}Lista;


//Funcao para inicializar a lista  que contem a Elista. 
Lista * inicicializa_lista_cadastro();

//Funcao onde incializamos a Elista, que contem as informacoes de registro do paciente e a data que ele foi.
Elista * inicicializa_elista_cadastro(Registro paciente);

void inserir_lista_cadastro(Lista *lista, Registro registro);

void mostrar_lista_cadastro (Lista * lista);

#endif //LISTA_CADASTRO_H