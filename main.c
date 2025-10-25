#include "TDLista.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
    Lista* lista = Lista_create();


    Lista_ins_begin(lista, 8);
    Lista_ins_begin(lista, 10);
    Lista_ins_begin(lista, 9);

    // Lista_ins_end(lista, 13);

    Lista_inserir_ordenado(lista, 7);

    Lista_print(lista);
    Lista_print_invertido(lista);
}