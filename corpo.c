#include <stdio.h>
#include <stdlib.h>
#include "corpo.h"
#include "console.h"

struct corpo{
    int x,y;
    struct Corpo* prox;
    };
Corpo* corpo_cria() {
    return NULL;
}

Corpo* corpo_insere(Corpo* l, int x, int y) {
    Corpo* novo = (Corpo*) malloc(sizeof(Corpo));
    novo->x = x;
    novo->y = y;
    return novo;
}

void corpo_imprime(Corpo* l) {
    Corpo* p;
    for(p = l; p != NULL; p = p->prox) {
        setColor(COLOR_BLUE);
        setBackgroundColor(COLOR_GREEN);
        gotoxy(p->x, p->y);
        printf("%c", 'b');
    }
}
