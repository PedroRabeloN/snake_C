#include <stdio.h>
#include <stdlib.h>
#include "corpo.h"
#include "console.h"

struct corpo{
    int x,y;
    int status;
    struct Corpo* prox;
    };
Corpo* corpo_cria() {
    return NULL;
}

Corpo* corpo_insere(Corpo* l, int x, int y) {
    Corpo* novo = (Corpo*) malloc(sizeof(Corpo));
    novo->x = x;
    novo->y = y;
    novo->prox=l;
    novo->status=1;
    return novo;
}

void corpo_imprime(Corpo* p) {


        setColor(COLOR_BLUE);
        setBackgroundColor(COLOR_GREEN);
        if(p->status==1){
        gotoxy(p->x, p->y);
        printf("%c", 'b');
        }

}

void apagarUltimo(Corpo* c){
    setBackgroundColor(COLOR_BLACK);
    Corpo* p;
    for(p = c; p != NULL; p = p->prox) {
        Corpo* proxCorpo;
        proxCorpo=p->prox;
        if(p->prox==NULL){
            gotoxy(p->x,p->y);
            printf("%c",' ');
            p->status=0;
        }else if(proxCorpo->status==0){
            gotoxy(p->x,p->y);
            printf("%c",' ');
            p->status=0;
        }
    }
}
