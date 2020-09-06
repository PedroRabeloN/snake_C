#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // kbhit e getch
#include <unistd.h> // usleep
#include <time.h> // time
#include <windows.h> // Beep e SetConsoleTitle
#include "lista.h"
#include "listaFrutas.h"
#include "console.h"

// para a leitura de teclas
char tecla, tem_tecla;
// para o relogio
int tempo;
time_t inicial, atual;
int statusJogo;
int pontuacao;
// personagem
struct personagem {
    int x,y;
    char avatar;
};
typedef struct personagem Personagem;
Personagem p;
// mapa
Lista* mapa1;

ListaFruta* frutas;

// cria mapa e objetos
void inicializaJogo() {
    iniciaFrutas();
    statusJogo= EM_JOGO;
    pontuacao = 0;



    // para o relogio
    tempo = 0;
    time(&inicial);

    // posicao inicial do personagem
    p.x = 5;
    p.y = 5;
    // avatar
    p.avatar = 'o'; // char

    // inicializa objetos no mapa
    mapa1 = lst_cria();

    // cria mapa
    criaMapa();

    insereFrutaAleatoria();

}
void iniciaFrutas(){
    frutas = lst_fruta_cria;
    lst_fruta_insere(frutas,100,'o',COLOR_RED,COLOR_BLACK,FRUTA1);
    lst_fruta_insere(frutas,200,'o',COLOR_GREEN,COLOR_BLACK,FRUTA2);
    lst_fruta_insere(frutas,500,'o',COLOR_BLUE,COLOR_BLACK,FRUTA3);
}

void insereFrutaAleatoria(){
    int randonFruta = rand() % 2;
    int x = 2 + rand() % (20-2);
    int y = 2 + rand() % (60-2);


}

void

void criaMapa(){
    criaMapaLinhaHorizontal(2,60,2);
    criaMapaLinhaHorizontal(2,60,20);
    criaMapaLinhaVertical(2,20,2);
    criaMapaLinhaVertical(2,20,60);

    criaMapaLinhaHorizontal(10,15,6);
    criaMapaLinhaHorizontal(10,15,7);
    criaMapaLinhaHorizontal(10,15,8);


    criaMapaLinhaVertical(13,20,40);
    criaMapaLinhaVertical(13,20,41);
    criaMapaLinhaHorizontal(30,40,13);



}
void criaMapaLinhaHorizontal(int inicio,int fim,int coluna){
    for (inicio; inicio <= fim;inicio++){
        mapa1 = lst_insere(mapa1, inicio, coluna,(char)219,COLOR_YELLOW,COLOR_YELLOW,PAREDE);
    }
}

void criaMapaLinhaVertical (int inicio,int fim,int linha){
    for (inicio; inicio <= fim;inicio++){
        mapa1 = lst_insere(mapa1, linha , inicio,(char)219,COLOR_YELLOW,COLOR_YELLOW,PAREDE);
    }
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
        case TECLA_ESQUERDA:
            p.x--;
            break;
        case TECLA_DIREITA:
            p.x++;
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


    // desenha objetos
    lst_imprime(mapa1);
    // desenha personagem
    desenhaPersonagem();

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

    gotoxy(0,21);
    printf("Pontos : %d    ", pontuacao);

    printf("p.x=%d p.y=%d", p.x, p.y);

}
void desenhaPersonagem(){

    colisao();
    gotoxy(p.x,p.y);
    setColor(COLOR_RED);
    setBackgroundColor(COLOR_GREEN);
    printf("%c", p.avatar);
}

void colisao(){
    if (lst_temElemento(mapa1,p.x,p.y) == PAREDE){
        morreu();
    }
        if (lst_temElemento(mapa1,p.x,p.y) == FRUTA1){
        pegaFruta(100,p.x,p.y);
    }
        if (lst_temElemento(mapa1,p.x,p.y) == FRUTA2){
        morreu();
    }
        if (lst_temElemento(mapa1,p.x,p.y) == FRUTA3){
        morreu();
    }
}
void pegaFruta(int valor,int x, int y){
    mapa1 =lst_retira(mapa1,x,y);
    pontuacao = pontuacao + valor;
}
void morreu(){
    int tecla;
    statusJogo=MORTO;
    setBackgroundColor(COLOR_BLACK);
    system("cls");
    gotoxy (1,1);
    printf("%s","morreu morreu ainda bem que nao foi eu \n precina 1 pra começa dnovo");
    scanf("%d",&tecla);
    if(tecla == 1){
        inicializaJogo();
        updateGame();

        return;
    }else{
        exit(666);
    }

}

int main() {
    setWindow(100,25); // define tamanho da janela: linhas, colunas
    SetConsoleTitle("Nome do Seu Jogo"); // titulo da janela

    inicializaJogo();
    updateGame();

}

void updateGame(){
    while(statusJogo == EM_JOGO) {
        leTeclado();
        controle();
        atualizaMapa();
        usleep(1000); // aguarda um tempo
    }
}
