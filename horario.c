#include "horario.h"

struct _horario{
	int hh;
	int mm;
	int ss;
};

HORARIO* horario_criar(){
    HORARIO* hrs;
    hrs = (HORARIO*)malloc(sizeof(HORARIO));
    hrs->hh = -1;
    hrs->mm = -1;
    hrs->ss = -1;

    return hrs;
}

void horario_free(HORARIO* hrs){
    free(hrs);
}

HORARIO* horario_parser(char horas[]){
    char hh[3];
    char mm[3];
    char ss[3];
    HORARIO* hrs;
    hrs = horario_criar();
    hh[2] = '\0';
    mm[2] = '\0';
    ss[2] = '\0';


    hh[0] = horas[0];
    hh[1] = horas[1];

    mm[0] = horas[3];
    mm[1] = horas[4];
    ss[0] = horas[6];
    ss[1] = horas[7];

    hrs->hh = atoi(hh);
    hrs->mm = atoi(mm);
    hrs->ss = atoi(ss);

    return hrs;

}

void horario_print(HORARIO* hrs){
    printf("%d:%d:%d\n",hrs->hh,hrs->mm,hrs->ss);
}

void horario_set(HORARIO* hrs,int hh,int mm,int ss){
    hrs->hh = hh;
    hrs->mm = mm;
    hrs->ss = ss;
}