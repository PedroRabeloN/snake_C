#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // kbhit e getch
#include <unistd.h> // usleep
#include <time.h> // time
#include <windows.h> // Beep e SetConsoleTitle
#include "lista.h"
#include "console.h"

// para a leitura de teclas
char tecla, tem_tecla;
// para o relogio
int tempo;
time_t inicial, atual;
// personagem
struct personagem {
    int x,y;
    char avatar;
};
typedef struct personagem Personagem;
Personagem p;
// mapa
Lista* mapa1;

// cria mapa e objetos
void inicializaJogo() {
    // para o relogio
    tempo = 0;
    time(&inicial);

    // posicao inicial do personagem
    p.x = 5;
    p.y = 5;
    // avatar
    p.avatar = 'P'; // char

    // inicializa objetos no mapa
    mapa1 = lst_cria();

    // insere 2 paredes
    mapa1 = lst_insere(mapa1, 5, 2,(char)219);
    mapa1 = lst_insere(mapa1, 6, 2,(char)219);
    // insere 1 objeto
    mapa1 = lst_insere(mapa1, 10, 5,(char)003);
}

// faz controle
void controle() {
    // atualiza relogio
    time(&atual);
    tempo = atual - inicial;

    // teclado
    if(tem_tecla == 1) {
        switch(tecla) {
        case TECLA_CIMA:
            p.y--;
            break;
        case TECLA_BAIXO:
            p.y++;
            break;
        case TECLA_ESC:
            exit(0);
            break;
        }
        tem_tecla=0;
    }
}

// rotina de leitura do teclado
void leTeclado() {
    if(kbhit()) { // se houve toque no teclado
        tecla = getch(); // armazena tecla pressionada
        tem_tecla = 1;
    }
}

// desenha mapa
void atualizaMapa() {
    // limpa a tela
    system("cls");

    // desenha objetos
    lst_imprime(mapa1);

    // desenha personagem
    gotoxy(p.x,p.y);
    printf("%c", p.avatar);

    // relogio
    setColor(COLOR_YELLOW);
    setBackgroundColor(COLOR_BLUE);
    gotoxy(0,22);
    printf("Tempo : %d    ", tempo);
    setBackgroundColor(COLOR_BLACK);
    setColor(COLOR_WHITE);
    gotoxy(0,23);
    printf("                 ");
    gotoxy(0,23);
    printf("p.x=%d p.y=%d", p.x, p.y);
}

int main() {
    setWindow(80,25); // define tamanho da janela: linhas, colunas
    SetConsoleTitle("Nome do Seu Jogo"); // titulo da janela

    inicializaJogo();

    while(1) {
        leTeclado();
        controle();
        atualizaMapa();
        usleep(1000); // aguarda um tempo
    }
}
