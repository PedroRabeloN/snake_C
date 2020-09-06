#include <stdio.h>
#include <stdlib.h>
#include "listaFrutas.h"
#include "console.h"

struct listaFruta {
    char simbolo;
    int cor, corFundo;
    int valor;
    int tipo;
    struct ListaFruta* prox;
};

ListaFruta* lst_fruta_cria() {
    return NULL;
}

ListaFruta* lst_fruta_insere(ListaFruta* l,int valor, char simbolo,int cor,int corFundo, int tipo) {
    ListaFruta* novo = (ListaFruta*) malloc(sizeof(ListaFruta));
    novo->simbolo = simbolo;
    novo->prox = l;
    novo->cor = cor;
    novo->corFundo = corFundo;
    novo->tipo = tipo;
    novo->valor = valor;
    return novo;
}

ListaFruta* lst_fruta_pega (ListaFruta* l,int tipo) {
    ListaFruta* p;
    for(p = l; p != NULL; p = p->prox) {
        if (p->tipo == tipo){
            return p;
        }
    }
    return 0;
}
