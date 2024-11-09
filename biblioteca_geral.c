#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_cadastro.h"


void limpa_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}


