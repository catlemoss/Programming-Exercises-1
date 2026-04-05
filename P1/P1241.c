#include <stdio.h>

int main(){
    
    int temp, agua, criadouro, casos, dia;

    scanf("%d %d %d %d %d", &temp, &agua, &criadouro, &casos, &dia);

    if ((temp > 30 && agua > 50) || (criadouro == 1 && casos > 100) || (((dia - 1) / 7) + 1) % 2 == 0){
        printf("Risco alto");

    } else if ((temp >= 25 && temp <= 30 && agua >= 20 && agua <= 50) || (criadouro == 1 && casos >= 50 && casos <= 100)){
        printf("Risco medio");

    } else {
        printf("Risco baixo");

    }
    return 0;
}