#ifndef CELULA_H
#define CELULA_H
#include "horario.h"
#include <string.h>

typedef struct _celula CELULA;
#define MAX_DESCR 50

CELULA* celula_criar();
void celula_free(CELULA* cel);
void celula_set(CELULA* cel,int prior,HORARIO* horario,char descricao[MAX_DESCR]);
void celula_print(CELULA* cel);



#endif