#include <stdio.h>

/* Imagine o mesmo cenário das questões a e b, porém 
agora em sua última tarefa, você quer reconstruir e imprimir as mensagens enviadas 
nos pacotes.  */

typedef struct {
    int id_mens;
    int id_pac;
    int tam_cont;
    char men_pac[10];
    int erro;
} tPacote;                      // UM pacote

tPacote LePacote(){
    tPacote p;
    char lixo[10];
    int i;
    scanf("%3d %3d %1d", &p.id_mens, &p.id_pac, &p.tam_cont);
    for (i = 0; i < 9; i++){ scanf("%c", &lixo[i]); }
    lixo[9] = '\0';
    for (i = 0; i < p.tam_cont; i++){ p.men_pac[i] = lixo[i]; }
    p.men_pac[p.tam_cont] = '\0';
    scanf("%4d", &p.erro);
    return p;
}

typedef struct {
    int qnt;
    tPacote pacotes[101];
} tMensagens;                   // conjunto de pacotes

tMensagens mensagensInicializa(){
    tMensagens m;
    m.qnt = 0;
    return m;
}

tMensagens mensagensInserePacote(tMensagens m, tPacote p){
    m.pacotes[m.qnt] = p;
    m.qnt++;
    return m;
}

int ComparaPacote(tPacote a, tPacote b){
    if (a.id_mens > b.id_mens) return 1;
    else if (a.id_mens < b.id_mens) return -1;
    else {
        if (a.id_pac > b.id_pac) return 1;
        else if (a.id_pac < b.id_pac) return -1;
        else return 0;
    }
}

tMensagens mensagensOrdena(tMensagens m){
    int i, j;
    tPacote aux;

    for (i = 0; i < m.qnt; i++){
        for (j = i + 1; j < m.qnt; j++){
            if (ComparaPacote(m.pacotes[i], m.pacotes[j]) > 0){
                aux = m.pacotes[i];
                m.pacotes[i] = m.pacotes[j];
                m.pacotes[j] = aux;
            }
        }
    }
    return m;
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

void mensagensImprime(tMensagens m){
    int i = 0;

    while (i < m.qnt){
        int idAtual = m.pacotes[i].id_mens;

        while (i < m.qnt && m.pacotes[i].id_mens == idAtual){

            if (verificaErro(m.pacotes[i])) printf("%s", m.pacotes[i].men_pac);
            else printf("##FALHA##");
            i++;
        }
        printf("\n");
    }
}

int main(){

    int n; // pacotes
    scanf("%d", &n);

    tMensagens msgs = mensagensInicializa();

    int i;
    for (i = 0; i < n; i++){
        tPacote p = LePacote();
        msgs = mensagensInserePacote(msgs, p);
    }

    msgs = mensagensOrdena(msgs);
    mensagensImprime(msgs);

    return 0;
}