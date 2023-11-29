#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char* argv) {
    No* n0_ptr = criar_ponteiro_no(2.0, NULL);
    No* n1_ptr = criar_ponteiro_no(3.23, criar_ponteiro_no(1.0, criar_ponteiro_no(3.6, NULL)));
    No* n2_ptr = criar_ponteiro_no(0.53, NULL);

    lista_inserir_no(n0_ptr, n1_ptr);
    lista_inserir_no(n0_ptr, n2_ptr);

    No* ListaCopia = lista_copiar(n0_ptr);

    lista_imprimir(n0_ptr);
    printf("\n");
    lista_imprimir(ListaCopia);

    printf("\nVerificar existencia de 3.23 na lista: %d\n", lista_verificar_existencia(n0_ptr, 3.23));
    printf("Quantidade de ocorrencias de 3.23 na lista: %d\n", lista_verificar_ocorrencias(n0_ptr, 3.23));
    
    printf("Imprimir lista inversa:\n");
    lista_imprimir_inversa(n0_ptr);
    printf("\n");

    printf("Inserir 4.0 na posicao 2:\n");
    lista_inserir_no_i(n0_ptr, 2);
    lista_imprimir(n0_ptr);
    printf("\n");

    printf("Remover no na posicao 1:\n");
    lista_remover_no_i(n0_ptr, 1);
    lista_imprimir(n0_ptr);
    printf("\n");

    printf("Remover nos com valor 3.23:\n");
    lista_remover_no(n0_ptr, 3.23);
    lista_imprimir(n0_ptr);
    printf("\n");

    printf("Quantidade de nos na lista: %d\n", lista_quantidade_nos(n0_ptr));

    lista_liberar(n0_ptr);

    return 0;
}