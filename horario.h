#ifndef HORARIO_H
#define HORARIO_H


#include <stdio.h>
#include <stdlib.h>

typedef struct _horario HORARIO;


HORARIO* horario_criar();
void horario_free(HORARIO* hrs);
HORARIO* horario_parser(char horas[]);
void horario_print(HORARIO* hrs);
void horario_set(HORARIO* hrs,int hh,int mm,int ss);


#endif