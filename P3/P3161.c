/* Imagine um cenário em que você receba pacotes 
de mensagens transmitidos via internet e que você tenha que processar os pacotes 
recebidos para formar as mensagens originais. A primeira tarefa, é ler os pacotes 
corretamente. Para isso, faça um programa para ler o conteúdo de cada pacote dado 
e imprimi-los na sequência. */

#include <stdio.h>

typedef struct {
    int idMens;
    int idPac;
    int tamMens;
    char mensagem[10]; // 9 + \0
    int erro;
} tPacote;

void LePacote(tPacote p[]){

    scanf("%3d %3d %1d", &p->idMens, &p->idPac, &p->tamMens);

    int i;
    for (i = 0; i < 9; i++){
       scanf("%c", &p->mensagem[i]);
    }
    p->mensagem[10] = '\0';

    scanf("%4d", &p->erro);
}

void ImprimePacote(tPacote p[]){
    printf("PCT: %d,%d,%d,", p->idMens, p->idPac, p->tamMens);

    int i;
    for (i = 0; i < p->tamMens; i++){
        printf("%c", p->mensagem[i]);
    }

    printf(",%d\n", p->erro);
}

int main(){

    int pacotes;
    scanf("%d", &pacotes);

    tPacote p;
    int i;
    for (i = 0; i < pacotes; i++){
        LePacote(&p);
        ImprimePacote(&p);
    }
    return 0;
}