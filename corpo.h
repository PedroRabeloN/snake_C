typedef struct corpo Corpo;

// Cria uma nova lista
Corpo* corpo_cria();

// Insere um novo elemento na lista com as coordenadas informadas
Corpo* corpo_insere(Corpo* l, int x, int y);

void corpo_imprime(Corpo* l);

