#include "celula.h"

#define MAX_DESCR 50
#define MAX_instruct 100
#define MAX_processos 4


typedef struct
{
    int numArgs;
    char** Args;
}INSTRUCAO;


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



CELULA* instrucao_add(INSTRUCAO instruc){
    CELULA* cel;
    HORARIO* hrs;
    cel = celula_criar();
    
    hrs = horario_parser(instruc.Args[2]);
    celula_set(cel,atoi(instruc.Args[1]),hrs,instruc.Args[3]);
    
    return cel;
}



int main(int argc, char const *argv[])
{
    
    CELULA* processos[MAX_processos];
    INSTRUCAO test;
    char str[MAX_instruct];

    for (int i = 0; i < MAX_processos; i++)
    {
        fgets(str, MAX_instruct, stdin);
        test = instrucao_parser(str);
        processos[i] = instrucao_add(test);
        instrucao_free(test);
    }
     
    for (int i = 0; i < MAX_processos; i++)
    {
        celula_print(processos[i]);
        celula_free(processos[i]);
    }
    // //processos_print(processos);

    // mergeSort_prior(processos,0,MAX_processos);

    // printf("\n\n");
    // processos_print(processos);



    return 0;
}
