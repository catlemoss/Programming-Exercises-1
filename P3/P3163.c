#include <stdio.h>

/* Imagine o mesmo cenário das questões a e b, porém 
agora em sua última tarefa, você quer reconstruir e imprimir as mensagens enviadas 
nos pacotes.  */

typedef struct {
    int idMens;
    int idPac;
    int tamMens;
    char mensagem[10]; // 9 caracteres + '\0'
    int erro;
} tPacote;

typedef struct {
    int qnt;
    tPacote pacotes[101];
} tMensagens;

// Ajustado para receber ponteiro e não retornar nada (altera direto na memória)
void mensagensInicializa(tMensagens *m) {
    m->qnt = 0;
}

void mensagensInserePacote(tMensagens *m, tPacote p) {
    m->pacotes[m->qnt] = p;
    m->qnt++;
}

void LePacote(tPacote *p) {
    // Lê os IDs e o tamanho
    if (scanf("%d %d %d", &p->idMens, &p->idPac, &p->tamMens) != 3) return;
    
    // Consumir o espaço em branco antes dos caracteres da mensagem
    scanf(" "); 
    
    int i;
    for (i = 0; i < 9; i++) {
        scanf("%c", &p->mensagem[i]);
    }
    p->mensagem[9] = '\0'; // O índice máximo é 9 para um array de 10
    
    scanf("%d", &p->erro);
}

int verificaErro(tPacote p) {
    int somaCheck = p.idMens + p.idPac + p.tamMens;
    int i;
    for (i = 0; i < p.tamMens; i++) {
        somaCheck += (unsigned char)p.mensagem[i];
    }
    return (somaCheck == p.erro);
}

int ComparaPacote(tPacote a, tPacote b) {
    if (a.idMens > b.idMens) return 1;
    if (a.idMens < b.idMens) return -1;
    if (a.idPac > b.idPac) return 1;
    if (a.idPac < b.idPac) return -1;
    return 0;
}

void mensagensOrdena(tMensagens *m) {
    int i, j;
    tPacote aux;
    for (i = 0; i < m->qnt - 1; i++) {
        for (j = i + 1; j < m->qnt; j++) {
            if (ComparaPacote(m->pacotes[i], m->pacotes[j]) > 0) {
                aux = m->pacotes[i];
                m->pacotes[i] = m->pacotes[j];
                m->pacotes[j] = aux;
            }
        }
    }
}

void mensagensImprime(tMensagens *m) {
    int i = 0;
    while (i < m->qnt) {
        int idAtual = m->pacotes[i].idMens;
        while (i < m->qnt && m->pacotes[i].idMens == idAtual) {
            if (verificaErro(m->pacotes[i])) {
                // Imprime apenas a quantidade de caracteres definida em tamMens
                for (int j = 0; j < m->pacotes[i].tamMens; j++) {
                    printf("%c", m->pacotes[i].mensagem[j]);
                }
            } else {
                printf("##FALHA##");
            }
            i++;
        }
        printf("\n");
    }
}

int main() {
    int numPacotes;
    if (scanf("%d", &numPacotes) != 1) return 0;

    tMensagens msgs;
    mensagensInicializa(&msgs);

    for (int i = 0; i < numPacotes; i++) {
        tPacote p;
        LePacote(&p);
        mensagensInserePacote(&msgs, p);
    }

    mensagensOrdena(&msgs);
    mensagensImprime(&msgs);

    return 0;
}