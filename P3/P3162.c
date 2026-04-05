/* Imagine o mesmo cenário da questão anterior, 
porém agora você quer identificar pacotes transmitidos com erro. A identificação é 
feita conferindo o código de erro que é transmitido juntamente com o pacote.  */

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

int verificaErro(tPacote p[]){
    int ERRO = p->idMens + p->idPac + p->tamMens;

    int M = 0, i;
    for (i = 0; i < p->tamMens; i++){
        M += p->mensagem[i];
    }

    ERRO += M;

    if (ERRO == p->erro) return 1;
    else return 0;
}

void ImprimePacote(tPacote p[]){

    if (verificaErro(p)){
        printf("PCT: %d,%d,%d,", p->idMens, p->idPac, p->tamMens);

        int i;
        for (i = 0; i < p->tamMens; i++){
            printf("%c", p->mensagem[i]);
        }

        printf(",%d\n", p->erro);

    } else printf("FALHA!\n");
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