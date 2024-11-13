#ifndef BIBLIOTECA_GERAL_H
#define BIBLIOTECA_GERAL_H

void aguarda_retorno();
void limpa_buffer();
void menu();

void salvar_lista(Lista * lista);
void carregar_lista(Lista *lista, Arvore * arvore_idade, Arvore * arvore_dia, Arvore * arvore_mes, Arvore * arvore_ano); 
#endif //LISTA_CADASTRO_H