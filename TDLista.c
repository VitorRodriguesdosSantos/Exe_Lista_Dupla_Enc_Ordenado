#include "TDLista.h"
#include <stdio.h>
#include <stdlib.h>

struct _no {
    int info;
    struct _no* prox, *ant;
};

struct _lista {
    TNo* inicio, *fim;
    int size;
};

TNo* TNo_createNFill (int info) {
    TNo* novo = malloc(sizeof(TNo));

    if (novo != NULL) {
        novo->info = info;
        novo->prox = NULL;
        novo->ant = NULL;

        return novo;
    }
}

Lista* Lista_create () {
    Lista* lista = malloc(sizeof(Lista));

    if (lista != NULL) {
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->size = 0;

        return lista;
    }
}

bool Lista_ins_begin (Lista* lista, int info) {
    if (lista == NULL) {
        return false;
    }

    TNo* novo = TNo_createNFill(info);
    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->size++;

        return true;
    }
    else {
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;
        lista->size++;

        return true;
    }
}

bool Lista_ins_end (Lista* lista, int info) {
    if (lista == NULL) {
        return false;
    }

    TNo* novo = TNo_createNFill(info);
    TNo* aux = lista->inicio;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
        lista->size++;

        return true;
    }
    else {
        lista->fim->prox = novo;
        novo->ant = lista->fim;
        lista->fim = novo;
        lista->size++;

        return true;
    }
}

bool Lista_inserir_ordenado (Lista* lista, int info) {
    if (lista == NULL) {
        return false;
    }

    TNo* novo = TNo_createNFill(info);
    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;

        return true;
    }
    else if (novo->info < lista->inicio->info) {
        novo->prox = lista->inicio;
        lista->inicio->ant = novo;
        lista->inicio = novo;

        return true;
    }
    else {
        TNo* aux = lista->inicio;
        while (aux != NULL && aux->prox->info < info) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        novo->ant = aux;

        if (aux->prox != NULL) {
            aux->prox->ant = novo;
        }
        else {
            lista->fim = novo;
        }

        aux->prox = novo;

        return true;
    }
}

void Lista_print (Lista* lista) {
    if (lista != NULL) {
        TNo* aux = lista->inicio;
        puts("\n==============================================");
        printf("Inicio -> ");
        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->prox;
        }
        printf("NULL \n");
        printf("Lista->end: %d \n", lista->fim->info);
        puts("==============================================");
    }
}

void Lista_print_invertido (Lista* lista) {
    if (lista != NULL) {
        TNo* aux = lista->fim;
        puts("\n==============================================");
        printf("NULL -> ");
        while (aux != NULL) {
            printf("%d -> ", aux->info);
            aux = aux->ant;
        }
        printf("Inicio \n");
        printf("Lista->begin: %d \n", lista->inicio->info);
        puts("==============================================");
    }
}

void Lista_destroy (Lista* lista) { 
    if (lista != NULL) {
        TNo* aux = lista->inicio;

        while (aux != NULL) {
            TNo* temp;
            temp = aux->prox;
            free(aux);
        }
        free(lista);
    }
}