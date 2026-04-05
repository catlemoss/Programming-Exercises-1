#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int nums, tipo, par = 0, impar = 0;
    scanf("%d", &nums);
    if (nums % 2 == 0){
        tipo = 0;
        par++;
    } else if (nums % 2 != 0){
        tipo = 1;
        impar++;
    }
    for (int i = 1; i < n; i++){
        scanf("%d", &nums);

        if (nums % 2 == 0){
            par++;
        } else if (nums % 2 != 0){
            impar++;
        }
    }
    if (tipo == 0){
        printf("QTD PARES:%d\n", par);
    } else {
        printf("QTD IMPARES:%d\n", impar);
    }
    return 0;
}