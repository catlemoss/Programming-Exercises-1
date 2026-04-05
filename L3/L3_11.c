#include <stdio.h>

/*  Um programa que dado a relação de números par ou
 impar, retorne os N primeiros números desse tipo.
*/

int EhPar (int x){
    if (x % 2 == 0) return 1;
    else return 0;
}

void PrintaPares (int N){
    for (int i = 2; i <= N; i++){
        if (EhPar(i)){
            printf("%d ", i);
        }
    }
}

void PrintaImpares (int N){
    for (int i = 1; i <= N; i++){
        if (!EhPar(i)){
            printf("%d ", i);
        }
    }
}

int main(){

    int tipo, N;
    scanf("%d %d", &tipo, &N);

    int contador = 0, num = 0;

    if (tipo < 0 || tipo > 1){
        printf("Opcao Invalida\n");
        return 0;
    }

    if (tipo == 0){
        while (contador < N){
            if (EhPar(num)){
                contador++;
            }
            num += 2;
        }

        PrintaPares(num);

    } else if (tipo == 1){
        while (contador < N){
            if (!EhPar(num)){
                contador++;
            }
            num++;
        }

        PrintaImpares(num);
    }
    return 0;
}