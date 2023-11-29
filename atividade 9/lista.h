typedef struct No {
    float valor;
    struct No* proximo_no;
} No;

No* criar_ponteiro_no(float valor, No* proximo_no);
void lista_inserir_no(No* no_cabeca_lista, No* no);
void lista_imprimir(No* no_cabeca_lista);
No* lista_copiar(No* no_cabeca_lista);
void lista_concatenar(No* no_cabeca_lista, No* no_cabeca_concatenar);
void lista_liberar(No* no_cabeca_lista);
int lista_quantidade_nos(No* no_cabeca_lista);

int lista_verificar_existencia(No* L, char valor_busca);
int lista_verificar_ocorrencias(No* L, char valor_busca);
void lista_imprimir_inversa(No* L);
void lista_inserir_no_i(No* L, int i);
void lista_remover_no_i(No* L, int i);
void lista_remover_no(No* L, char valor_busca);