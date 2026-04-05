#include <stdio.h>

/* Imagine o mesmo cenário da questão anterior, porém 
agora você quer identificar pacotes transmitidos com erro. A identificação é feita 
conferindo o código de erro que é transmitido juntamente com o pacote.  */

typedef struct {
    int id_mens;
    int id_pac;
    int tam_cont;
    char men_pac[10];
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
    p.men_pac[p.tam_cont] = '\0'; // para termnira frase

    scanf("%4d", &p.erro);

    return p;
}

int verificaErro(tPacote p){
    int ERRO = p.id_mens + p.id_pac + p.tam_cont;

    int numLet = 0;
    int i;
    for (i = 0; i < p.tam_cont; i++){
        numLet += p.men_pac[i];
    }

    ERRO += numLet;

    if (ERRO == p.erro) return 1;
    else return 0;
}

void ImprimePacote(tPacote p){
    if (verificaErro(p)){
    printf("PCT: %d,%d,%d,%s,%d\n", p.id_mens, p.id_pac, p.tam_cont, p.men_pac, p.erro);

    } else printf("FALHA!\n");
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