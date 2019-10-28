#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCR 50
#define MAX_instruct 100

typedef struct {
	int hh;
	int mm;
	int ss;
} horario;

typedef struct {
	int prior;
	horario chegada;
	char descricao[MAX_DESCR];
} celula;

typedef struct
{
    int numArgs;
    char** Args;
}INSTRUCAO;


horario horario_parser(char horas[]){
    char hh[3];
    char mm[3];
    char ss[3];
    horario hrs;
    hh[2] = '\0';
    mm[2] = '\0';
    ss[2] = '\0';


    hh[0] = horas[0];
    hh[1] = horas[1];

    mm[0] = horas[3];
    mm[1] = horas[4];
    ss[0] = horas[6];
    ss[1] = horas[7];

    hrs.hh = atoi(hh);
    hrs.mm = atoi(mm);
    hrs.ss = atoi(ss);

    return hrs;

}

void horario_print(horario hrs){
    printf("%d:%d:%d\n",hrs.hh,hrs.mm,hrs.ss);
}


void instrucao_free(INSTRUCAO instruc){
    
    for (int i = 0; i < instruc.numArgs; i++)
    {
        free(instruc.Args[i]);
    }
    free(instruc.Args);


}

INSTRUCAO instrucao_parser(char instrucao[MAX_instruct]){

    INSTRUCAO instruct;
    char* tokenAux;
    
    instruct.Args = (char**)malloc(sizeof(char*));
    instruct.numArgs = 0;
    tokenAux = strtok(instrucao," ");

    while (tokenAux != NULL)
    {
        //printf("tokenAux: %s\n",tokenAux);
        instruct.Args[instruct.numArgs] = (char*)malloc(strlen(tokenAux)+1);
        strcpy(instruct.Args[instruct.numArgs],tokenAux);
        //instruct.Args[instruct.numArgs] = tokenAux;
        instruct.numArgs++;

        instruct.Args = (char**)realloc(instruct.Args,(instruct.numArgs+1) * sizeof(char*));
        
        tokenAux = strtok(NULL, " \n");
    }
    
    return instruct;
}

void instrucao_print(INSTRUCAO instruc){
    printf("numArgs:%d\n\n",instruc.numArgs);
    printf("Args:\n");
    for (int i = 0; i < instruc.numArgs; i++)
    {
        printf("%d: %s\n",i,instruc.Args[i]);
    }
    
}

celula celula_add(INSTRUCAO instruc){
    celula cel;
    horario hrs;

    cel.prior = atoi(instruc.Args[1]);
    hrs = horario_parser(instruc.Args[2]);
    cel.chegada = hrs;
    strcpy(cel.descricao,instruc.Args[3]);
    return cel;
}

void celula_print(celula cel){
    printf("prioridade: %d\n", cel.prior);
    printf("horario: ");
    horario_print(cel.chegada);
    printf("descricao: %s\n",cel.descricao);
}

int main(int argc, char const *argv[])
{
    
    INSTRUCAO test;
    char str[MAX_instruct];
    fgets(str, 100, stdin);
    //scanf("%s",&str);
    test = instrucao_parser(str);
    //instrucao_print(test);
    celula celtest;
    celtest = celula_add(test);
    celula_print(celtest); 
    
    instrucao_free(test);


    return 0;
}
