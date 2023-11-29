#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* criar_ponteiro_no(float valor, No* proximo_no){

    No* no  = malloc(sizeof(No));
    no-> valor = valor;
    no-> proximo_no = proximo_no;
    return no;
}

void lista_inserir_no(No* no_cabeca_lista, No* no){

    if(no_cabeca_lista != NULL){
        if(no_cabeca_lista -> proximo_no == NULL){
            no_cabeca_lista ->proximo_no = no;
        }else{
            lista_inserir_no(no_cabeca_lista->proximo_no,no);
        }

    }else{
        printf("Lista vazia!");
    }
}

void lista_imprimir(No* no_cabeca_lista){

 if(no_cabeca_lista != NULL){
    printf("%.2f ", no_cabeca_lista -> valor);
    lista_imprimir(no_cabeca_lista->proximo_no);
 }
}



No* lista_copiar(No* no_cabeca_lista){
   
   if(no_cabeca_lista != NULL){
       return criar_ponteiro_no(no_cabeca_lista -> valor, lista_copiar(no_cabeca_lista->proximo_no));
   }
   return NULL;
}

void lista_concatenar(No* no_cabeca_lista, No* no_cabeca_concatenar){

    lista_inserir_no(no_cabeca_lista, no_cabeca_concatenar);
  
}

void lista_liberar(No* no_cabeca_lista){
    if(no_cabeca_lista != NULL){
        lista_liberar(no_cabeca_lista->proximo_no);
        free(no_cabeca_lista);
    }
}

int lista_quantidade_nos(No* no_cabeca_lista){
    if(no_cabeca_lista != NULL){
       return 1 + lista_quantidade_nos(no_cabeca_lista -> proximo_no);
    }

    return 0;
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1; 
        }
        atual = atual->proximo_no;
    }
    return 0; 
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo_no;
    }
    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L == NULL) {
        return;
    }
    lista_imprimir_inversa(L->proximo_no);
    printf("%.2f ", L->valor);
}

void lista_inserir_no_i(No* L, int i) {
    if (i < 0) {
        printf("Posição inválida para inserção.\n");
        return;
    }

    No* novo_no = criar_ponteiro_no(0.0, NULL);
    No* atual = L;

    if (i == 0) {
        novo_no->proximo_no = L;
        L = novo_no;
        return;
    }

    int pos = 0;
    while (atual != NULL && pos < i - 1) {
        atual = atual->proximo_no;
        pos++;
    }

    if (atual == NULL) {
        printf("Posição inválida para inserção.\n");
        free(novo_no);
        return;
    }

    novo_no->proximo_no = atual->proximo_no;
    atual->proximo_no = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    if (i < 0) {
        printf("Posição inválida para remoção.\n");
        return;
    }

    No* atual = L;

    if (i == 0) {
        L = L->proximo_no;
        free(atual);
        return;
    }

    int pos = 0;
    while (atual != NULL && pos < i - 1) {
        atual = atual->proximo_no;
        pos++;
    }

    if (atual == NULL || atual->proximo_no == NULL) {
        printf("Posição inválida para remoção.\n");
        return;
    }

    No* no_a_remover = atual->proximo_no;
    atual->proximo_no = no_a_remover->proximo_no;
    free(no_a_remover);
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            if (anterior != NULL) {
                anterior->proximo_no = atual->proximo_no;
            } else {
                L = atual->proximo_no;
            }
            free(atual);
            atual = anterior;
        }
        anterior = atual;
        atual = atual->proximo_no;
    }
}