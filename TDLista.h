#ifndef TDLISTA
#define TDLISTA
#include <stdbool.h>

typedef struct _no TNo;
typedef struct _lista Lista;

TNo* TNo_createNFill (int);
Lista* Lista_create ();
void Lista_destroy (Lista*);
bool Lista_ins_begin (Lista*, int);
bool Lista_ins_end (Lista*, int);
bool Lista_inserir_ordenado (Lista*, int);
void Lista_print (Lista*);
void Lista_print_invertido (Lista*);

#endif