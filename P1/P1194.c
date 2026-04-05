#include <stdio.h>

/* Um programa que verifique a validade de um CPF.
Um CPF é composto por 11 dígitos numéricos #1#2#3.#4#5#6.#7#8#9-#10#11, 
sendoos nove primeiros a base e os dois últimos os verificadores.
*/

int main(){

    int a, b, c, d, e, f, g, h, i, j, k; 
    int soma_j = 0, soma_k = 0, resto_j, resto_k; 
    int digito1, digito2; 

    scanf("%1d%1d%1d.%1d%1d%1d.%1d%1d%1d-%1d%1d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k);

    if (a==b && b==c && c==d && d==e && e==f && f==g && g==h && h==i && i==j && j==k){
            printf("CPF invalido: digitos iguais!\n");
            return 0;
        }
    
    // Cálculo do dígito verificador #10: 
    soma_j = a*10 + b*9 + c*8 + d*7 + e*6 + f*5 + g*4 + h*3 + i*2; 
    resto_j = soma_j % 11;
    digito1 = (resto_j < 2) ? 0 : 11 - resto_j;
    
    // Cálculo do dígito verificador #11: 
    soma_k = a*11 + b*10 + c*9 + d*8 + e*7 + f*6 + g*5 + h*4 + i*3 + digito1*2;
    resto_k = soma_k % 11;
    digito2 = (resto_k < 2) ? 0 : 11 - resto_k;

    if (digito1 == j && digito2 == k){
        printf("CPF valido!\n");

    } else if (digito1 == j && digito2 != k){
        printf("CPF invalido: segundo digito!\n");

    } else if (digito1 != j && digito2 == k){
        printf("CPF invalido: primeiro digito!\n");

    } else {
        printf("CPF invalido: dois digitos!\n");
    }
    
    return 0;
}