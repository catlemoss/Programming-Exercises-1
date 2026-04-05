#include <stdio.h>

/* Imagine um cenário em que você receba pacotes de
mensagens transmitidos via internet e que você tenha que processar os pacotes
recebidos para formar as mensagens originais. A primeira tarefa, é ler os pacotes
corretamente. Para isso, faça um programa para ler o conteúdo de cada pacote dado
e imprimi-los na sequência. */

typedef struct {
    int id_mens;
    int id_pac;
    int tam_cont;
    char men_pac[10]; // prestar mais atencao, o enunciado avisou q sao 9 chars fixos
    int erro;
} tPacote;

tPacote LePacote(){
    tPacote p;
    char lixo[10]; // 9 chars + o \0
    int i;

    scanf("%3d %3d %1d", &p.id_mens, &p.id_pac, &p.tam_cont); // num com 0 esq

    for (i = 0; i < 9; i++){ scanf("%c", &lixo[i]); }
    lixo[9] = '\0';

    for (i = 0; i < p.tam_cont; i++){ p.men_pac[i] = lixo[i]; }
    p.men_pac[p.tam_cont] = '\0';

    scanf("%4d", &p.erro);

    return p;
}

void ImprimePacote(tPacote p){
    printf("PCT: %d,%d,%d,%s,%d\n", p.id_mens, p.id_pac, p.tam_cont, p.men_pac, p.erro);
}

int main(){

    int pacotes;
    scanf("%d", &pacotes);

    if (pacotes < 0) return 0;

    tPacote p;
    int i;
    for (i = 0; i < pacotes; i++){
        p = LePacote();
        ImprimePacote(p);
    }
    return 0;
}