/* TAD Lista Jogo */

typedef struct listaFruta ListaFruta;

// Cria uma nova lista
ListaFruta* lst_fruta_cria();

// Insere um novo elemento na lista com as coordenadas informadas
ListaFruta* lst_fruta_insere(ListaFruta* l,int valor, char simbolo,int cor,int corFundo, int tipo);

ListaFruta* lst_fruta_pega (ListaFruta* l,int tipo);
