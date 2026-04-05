#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int n;
    scanf("%d", &n);

    int tipo, total = 0;

    for (int i = 0; i < n; i++){
        scanf("%d", &tipo);
        if (tipo == 1){
            total += a;

        } else if (tipo == 2){
            total += b;

        } else if (tipo == 3){
            total += c;
        }
    }

    printf("CUSTO:%d\n", total);

    return 0;
}