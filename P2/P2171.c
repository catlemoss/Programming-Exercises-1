#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    if (n == 0){
        return 0;
    }

    int num, menor, posicao_menor = 1;
    scanf("%d", &num);

    menor = num;

    for (int i = 2; i <= n; i++){
        scanf("%d", &num);

        if (num < menor){
            menor = num;
            posicao_menor = i;
        }
    }
    printf("POS:%d\n", posicao_menor);
    return 0;
}
