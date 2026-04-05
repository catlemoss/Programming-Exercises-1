#include <stdio.h>
 
/*  Observe a seguinte propriedade que alguns números 
maiores que 1000 e menores que 9999 possuem: 
Número:  abcd 
   (ab) + (cd) = (ef) 
   𝑒𝑓∗𝑒𝑓 = abcd 
 
 Exemplo: 3025 
   30+25 = 55 
   55∗55 = 3025

a) A verificação da propriedade de um número deverá ser feita por uma função (a ser 
implementada) que receberá um número num e retornará verdadeiro caso num 
satisfaça a propriedade, ou falso caso contrário. A função deverá ter o seguinte 
cabeçalho: int Propriedade(int num);  */

int Propriedade(int num){

    int ab = num / 100;
    int cd = num % 100;
    int ef = ab + cd;

    if (ef * ef == num){
        printf("%d\n", num);
    }
    return 1;
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    if (n > 1000 && m < 9999){
        for (n = n + 1; n < m; n++){
            Propriedade(n);
        }
    }
    return 0;
}