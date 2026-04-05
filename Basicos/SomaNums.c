#include <stdio.h>

int somaDigitos(int n) {
    int soma = 0;

    if (n < 0) { // if num negativo
        n = -n;
    }

    while (n > 0) {
        soma += n % 10;  // pega o último dígito e soma+
        n = n / 10;      // remove- o último dígito
    }

    return soma;
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    printf("A soma dos dígitos é: %d\n", somaDigitos(numero));

    return 0;
}