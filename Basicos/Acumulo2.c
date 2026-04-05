#include <stdio.h>

int main(){

    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int numfolhas;
    scanf("%d", &numfolhas);

    int tipo, t1 = 0, t2 = 0, t3 = 0, soma = 0;

    for (int i = 0; i < numfolhas; i++){
        scanf("%d", &tipo);

        if (tipo == 1){
            soma += a;
            t1++;
        } else if (tipo == 2){
            soma += b;
            t2++;
        } else if (tipo == 3){
            soma += c;
            t3++;
        }
    }

    printf("Tipo 1: %d folha(s)\nTipo 2: %d folha(s)\nTipo 3: %d folha(s)\nCusto: %d\n", t1, t2, t3, soma);
    return 0;
}