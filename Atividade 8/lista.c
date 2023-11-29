#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));

    no->valor = valor;
    no->proximo_no = proximo_no;

    return no;
}

void lista_inserir_no(No* H, No* no){
    if (H != NULL){
        if(H->proximo_no == NULL){
            H->proximo_no = no;
        }else{
            lista_inserir_no(H->proximo_no,no);
        }
    }
}

void lista_imprimir(No* H){
    if(H != NULL){
        printf("%c ", H->valor);
        lista_imprimir(H->proximo_no);
    }
}

No* lista_copiar(No* H){
    if(H != NULL){
        return no(H->valor, lista_copiar(H->proximo_no));
    }
    
    return NULL;
}

void lista_concatenar(No* H, No* Hc){
    lista_inserir_no(H, Hc);
}

void lista_liberar(No* H){
    if (H != NULL){
        lista_liberar(H->proximo_no);
        free(H);
    }
}

int lista_quantidade_nos(No* H){
    if(H != NULL){
        return 1 + lista_quantidade_nos(H->proximo_no);
    }

    return 0;
}

int lista_verificar_existencia(No* H, char valor_busca){
    int valor_existe = 0;

    if(H != NULL){
        if (H->valor == valor_busca){
            valor_existe = 1;
        } else {
            valor_existe = lista_verificar_existencia(H->proximo_no, valor_busca);
        }
    }

    return valor_existe;
}

int lista_verificar_ocorrencias(No* H, char valor_busca){
    int valor_ocorrencias = 0;

    if(H != NULL){
        if(H->valor == valor_busca){
            valor_ocorrencias = 1 + lista_verificar_ocorrencias(H->proximo_no,valor_busca);
        } else {
            valor_ocorrencias = lista_verificar_ocorrencias(H->proximo_no, valor_busca);
        }
    }

    return valor_ocorrencias;
}

void lista_imprimir_inversa(No* H){
    No* H_inverso;

    if(H->proximo_no != NULL){
        lista_imprimir_inversa(H->proximo_no);
        printf("%c ", H->valor);
    } else {
        printf("\n%c ", H->valor);
    }
}

void lista_inserir_no_i(No* H, int i){
}

void lista_remover_no_i(No* H, int i){
    if (H != NULL && i >= 0) {
        if (i == 0 && H->proximo_no != NULL) {
            No* no_remover = H->proximo_no;
            H->proximo_no = H->proximo_no->proximo_no;
            free(no_remover);
        } else {
            lista_remover_no_i(H->proximo_no, i - 1);
        }
    }    
}

void lista_remover_no(No* H, char valor_busca) {
    if (H != NULL) {
        if (H->proximo_no != NULL && H->proximo_no->valor == valor_busca) {
            No* no_remover = H->proximo_no;
            H->proximo_no = H->proximo_no->proximo_no;
            free(no_remover);
        } else {
            lista_remover_no(H->proximo_no, valor_busca);
        }
    }
}