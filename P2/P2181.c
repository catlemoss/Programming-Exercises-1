#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int soma = 0;

    for (int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);

        if (i % 2 == 0 && num % 2 == 0){
            soma += num;
        }
        if (i % 2 == 1 && num % 2 == 1){
            soma += num;
        }
    }

    printf("SOMA:%d", soma);
    return 0;
}
