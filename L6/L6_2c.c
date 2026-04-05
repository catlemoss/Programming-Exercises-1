#include <stdio.h>

#define MAX 7
#define MAX_CARTELAS 100

/* Imagine o mesmo cenário das questões a e b. Porém 
agora, você já leu as cartelas da partida conforme a questão anterior. A sua terceira 
tarefa é simular a execução de várias partidas na sequência utilizando um mesmo 
grupo de cartelas.  */

typedef struct {
    int id;
    int tam_cart;
    int nums[MAX][MAX];
    int original[MAX][MAX];
} tCartela;

tCartela LeCartela(){
    tCartela c;
    int i, j;
    if (scanf("%d %d", &c.id, &c.tam_cart) != 2) return c;

    for (i = 0; i < c.tam_cart; i++){
        for (j = 0; j < c.tam_cart; j++){

            scanf("%d", &c.nums[i][j]);
            c.original[i][j] = c.nums[i][j];
        }
    }
    return c;
}

tCartela MarcaCartela(tCartela c, int num){
    int i, j;

    for (i = 0; i < c.tam_cart; i++){
        for (j = 0; j < c.tam_cart; j++){

            if (c.nums[i][j] == num) {
                c.nums[i][j] = -1; // marca com -1
            }
        }
    }
    return c;
}

int VenceuCartela(tCartela c){
    int i, j;

    // para vencer todos os num devem ser -1
    for (i = 0; i < c.tam_cart; i++){
        for (j = 0; j < c.tam_cart; j++){

            if (c.nums[i][j] != -1) return 0;
        }
    }
    return 1;
}

tCartela ResetaCartela(tCartela c){
    int i, j;

    for (i = 0; i < c.tam_cart; i++){
        for (j = 0; j < c.tam_cart; j++){

            c.nums[i][j] = c.original[i][j];
        }
    }
    return c;
}

void ImprimeCartela(tCartela c){
    int i, j;

    printf("ID:%d\n", c.id);

    for (i = 0; i < c.tam_cart; i++){
        for (j = 0; j < c.tam_cart; j++){

            if (j > 0) printf("|");
            printf("%03d", c.original[j][i]);
        }
        printf("\n");
    }
}

typedef struct {
    int qnt;
    tCartela cartelas[MAX_CARTELAS];
} tPartida;

tPartida LeCartelasPartida(){
    tPartida p;

    scanf("%d", &p.qnt);

    for (int i = 0; i < p.qnt; i++){
        p.cartelas[i] = LeCartela();
    }
    return p;
}

tPartida ResetaPartida(tPartida p){

    for (int i = 0; i < p.qnt; i++){
        p.cartelas[i] = ResetaCartela(p.cartelas[i]);
    }
    return p;
}

void JogaPartida(tPartida p){

    int num, i, algumVenceu = 0;
    
    while (scanf("%d", &num) && num != -1){ // le nums ate -1

        if (!algumVenceu){

            // marca cartelas
            for (i = 0; i < p.qnt; i++){
                p.cartelas[i] = MarcaCartela(p.cartelas[i], num);
            }

            // alguem venceu?
            for (i = 0; i < p.qnt; i++){
                if (VenceuCartela(p.cartelas[i])){
                    algumVenceu = 1;
                    break;
                }
            }
        }
    }

    if (algumVenceu){

        printf("COM VENCEDOR\n");

        for (i = 0; i < p.qnt; i++){
            if (VenceuCartela(p.cartelas[i])){

                ImprimeCartela(p.cartelas[i]);
            }
        }

    } else {
        printf("SEM VENCEDOR\n");
    }
}

int main(){

    tPartida partida; 
    int qtdPartidas, i;

    partida = LeCartelasPartida();

    scanf ("%d", &qtdPartidas);

    for (i = 0; i < qtdPartidas; i++){ 
        if ( i!=0 ) printf("\n");

        printf("PARTIDA %d\n", i+1);
        
        partida = ResetaPartida(partida); 
        JogaPartida(partida); 
    } 
    return 0; 
}