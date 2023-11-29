#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hash.h"
#include<ctype.h>


int hash(char* chave){
    return toupper (chave[0])-65;
}

char** tabela_hash(){
    char** tabela = malloc(sizeof(char*)*TAM_TABELA);


for(int i = 0; i<TAM_TABELA;i++){
    tabela[i] = malloc(sizeof(char)*TAM_VALOR);
}


    return tabela;
}