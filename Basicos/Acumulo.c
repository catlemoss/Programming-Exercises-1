#include <stdio.h>

int main(){

    int n = 0;
    scanf("%d", &n);

    int soma = 0;
    
    for (int i = 0; i < 6; i++){
        soma += i;
        }
    
    printf("%d\n", soma);
    return 0;
}