/*  A sua segunda tarefa é simular a execução de várias partidas na 
sequência utilizando um mesmo grupo de cartelas, agora ordenadas*/

#include <stdio.h>
#include <string.h> // Necessário para memcpy

#define MAX_CARTELAS 100
#define MAX_DIM 7

typedef struct {
    int id_cartela;
    int dimensao;
    int matriz[MAX_DIM][MAX_DIM];     // Matriz de jogo (sofre alterações)
    int gabarito[MAX_DIM][MAX_DIM];   // Matriz original (apenas leitura)
    int acertos;                      // Contador de marcações
} BingoCard;

typedef struct {
    int total_participantes;
    BingoCard lista[MAX_CARTELAS];
} GerenciadorJogo;

void resetar_cartela(BingoCard *c) {
    c->acertos = 0;

    memcpy(c->matriz, c->gabarito, sizeof(c->matriz));
}

void cadastrar_cartela(BingoCard *c) {
    int lin, col;
    scanf("%d %d", &c->id_cartela, &c->dimensao);


    for (col = 0; col < c->dimensao; col++) {
        for (lin = 0; lin < c->dimensao; lin++) {
            scanf("%d", &c->gabarito[lin][col]);
        }
    }

    resetar_cartela(c);
}

void computar_jogada(BingoCard *c, int numero_sorteado) {
    int i, j;
    for (i = 0; i < c->dimensao; i++) {
        for (j = 0; j < c->dimensao; j++) {
            if (c->matriz[i][j] == numero_sorteado) {
                c->matriz[i][j] = -1; // Marcação
                c->acertos++;
            }
        }
    }
}

int checar_vitoria(BingoCard c) {
    return (c.acertos == (c.dimensao * c.dimensao));
}

void ranquear_cartelas(GerenciadorJogo *jogo) {
    int i, j, melhor_idx;
    BingoCard temp;

    for (i = 0; i < jogo->total_participantes - 1; i++) {
        melhor_idx = i;
        
        for (j = i + 1; j < jogo->total_participantes; j++) {

            if (jogo->lista[j].acertos > jogo->lista[melhor_idx].acertos) {
                melhor_idx = j;
            }

            else if (jogo->lista[j].acertos == jogo->lista[melhor_idx].acertos) {
                if (jogo->lista[j].id_cartela < jogo->lista[melhor_idx].id_cartela) {
                    melhor_idx = j;
                }
            }
        }

        if (melhor_idx != i) {
            temp = jogo->lista[i];
            jogo->lista[i] = jogo->lista[melhor_idx];
            jogo->lista[melhor_idx] = temp;
        }
    }
}

void exibir_cartela(BingoCard c) {
    int i, j;
    printf("ID:%d QTDMARCADAS:%d\n", c.id_cartela, c.acertos);
    
    for (i = 0; i < c.dimensao; i++) {
        for (j = 0; j < c.dimensao; j++) {
            if (c.matriz[i][j] == -1) {
                printf("---");
            } else {
                printf("%03d", c.matriz[i][j]);
            }
  
            if (j < c.dimensao - 1) printf("|");
        }
        printf("\n");
    }
}

void executar_partida(GerenciadorJogo *jogo) {
    int bola, i;
    int fim_de_jogo = 0;


    for (i = 0; i < jogo->total_participantes; i++) {
        resetar_cartela(&jogo->lista[i]);
    }


    while (scanf("%d", &bola) && bola != -1) {

        if (!fim_de_jogo) {
            for (i = 0; i < jogo->total_participantes; i++) {
                computar_jogada(&jogo->lista[i], bola);
            }

            for (i = 0; i < jogo->total_participantes; i++) {
                if (checar_vitoria(jogo->lista[i])) {
                    fim_de_jogo = 1;
                }
            }
        }

    }

    ranquear_cartelas(jogo);
    
    for (i = 0; i < jogo->total_participantes; i++) {
        exibir_cartela(jogo->lista[i]);
    }
}

int main() {
    GerenciadorJogo jogo;
    int num_partidas, i;


    scanf("%d", &jogo.total_participantes);
    for (i = 0; i < jogo.total_participantes; i++) {
        cadastrar_cartela(&jogo.lista[i]);
    }

    scanf("%d", &num_partidas);
    for (i = 0; i < num_partidas; i++) {
        printf("PARTIDA %d\n", i + 1);
        executar_partida(&jogo);
        
        if (i < num_partidas - 1) {
            printf("\n");
        }
    }

    return 0;
}