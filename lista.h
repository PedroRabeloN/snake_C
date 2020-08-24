/* TAD Lista Jogo */

typedef struct lista Lista;

// Cria uma nova lista
Lista* lst_cria();

// Insere um novo elemento na lista com as coordenadas informadas
Lista* lst_insere(Lista* l, int x, int y, char simbolo);

// Imprime objetos da lista
void lst_imprime(Lista* l);

// Verifica se nas coordenadas informadas (x e y) existe um elemento
int lst_temElemento(Lista* l, int x, int y);

// Retira um elemento que esteja nas coordenadas x e y
Lista* lst_retira(Lista* l, int x, int y);
