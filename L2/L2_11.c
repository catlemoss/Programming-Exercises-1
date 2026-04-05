#include <stdio.h>

/* Observe a seguinte propriedade que alguns números 
maiores que 1000 e menores que 9999 possuem: 
Número:  
    abcd 
   (ab) + (cd) = (ef) 
   𝑒𝑓∗𝑒𝑓 = abcd  */

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    if (n > 1000 && m < 9999){
        for (n = n + 1; n < m; n++){
            int ab = n / 100; // divisão inteira
            int cd = n % 100; // resto da divisão
            int ef = ab + cd;

            if (ef * ef == n){
                printf("%d\n", n);
            }
        }
    }
    return 0;
}