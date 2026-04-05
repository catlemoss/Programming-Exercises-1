#include <stdio.h>

/* Um programa que receba um caractere e dois 
números sendo c1 o caractere e n1 e n2 os números. Posteriormente, intercale os 
dígitos de n1 com os dígitos de n2 para formar um único número. 
Caso c1 seja uma 
letra, o primeiro dígito (dígito mais à direita) do novo número será o primeiro dígito 
de n1 (também o dígito mais à direita) enquanto os seguintes serão intercalados 
(i.e., de n2, de n1, de n2, etc.). 
Caso contrário, o primeiro dígito será de n2 enquanto 
os outros serão intercalados (i.e., de n1, de n2, de n1, etc.). 
Caso não haja mais 
dígitos de algum dos números para intercalar, o dígito zero deve ser usado.  
*/

int main() {
    char c1;
    int n1, n2;
    scanf(" (%c,%d,%d)", &c1, &n1, &n2);

    int resultado = 0;
    int multiplicador = 1;

    int inicio; 
    if ((c1 >= 'A' && c1 <= 'Z') || (c1 >= 'a' && c1 <= 'z')) inicio = 1; // começa n1
    else inicio = 2; // começa n2

    while (n1 > 0 || n2 > 0){
        int novo_num;

        if (inicio == 1){
            novo_num = (n1 > 0 ? n1 % 10 : 0);
            n1 /= 10;
            inicio = 2;

        } else {
            novo_num = (n2 > 0 ? n2 % 10 : 0);
            n2 /= 10;
            inicio = 1;
        }

        resultado += novo_num * multiplicador;
        multiplicador *= 10;
    }

    printf("(%d)\n", resultado);
    return 0;
}