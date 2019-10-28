#include "celula.h"

struct _celula
{
	int prior;
	HORARIO* chegada;
	char descricao[MAX_DESCR];
};

CELULA* celula_criar(){
    CELULA* cel;
    cel = (CELULA*)malloc(sizeof(CELULA));
    cel->prior = -1;
    cel->descricao[0] = '\0';
    return cel;
}

void celula_free(CELULA* cel){
    horario_free(cel->chegada);
    free(cel);
}

void celula_set(CELULA* cel,int prior,HORARIO* horario,char descricao[MAX_DESCR]){
    cel->prior = prior;
    cel->chegada = horario;
    strcpy(cel->descricao,descricao);
}

void celula_print(CELULA* cel){
    printf("prioridade: %d\n", cel->prior);
    printf("horario: ");
    horario_print(cel->chegada);
    printf("descricao: %s\n",cel->descricao);
}