#include <stdio.h>

int main(){

    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a > b && b > c){
        printf("DECRESCENTE");

    } else if (a < b && b < c){
        printf("CRESCENTE");

    } else {
        printf("TUDO DOIDO");
    }
    return 0;
}