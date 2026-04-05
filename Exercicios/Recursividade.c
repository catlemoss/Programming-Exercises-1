/* Exercicio */

/* Funções Recursivas */
#include <stdio.h>

// Fatorial
long int fatorial(int n){
    if (n < 2) return 1; // passo de parada

    return n * fatorial(n - 1); // passo recursivo
}

// Máximo Divisor Comum
int MDC(int a, int b){
    if (a == b) return a; // passo de parada

    if (a > b) return MDC(a-b, b);
    else return MDC(a, b-a);
}

// Soma de Dígitos
int somaD(int n){
    if (!n) return 0;

    return n % 10 + somaD(n/10);
}

// Número Par
int ehPar(int n){
    if (n < 0) n = -n; // se for negativo, vira positivo

    if (n == 0) return 1;
    if (n == 1) return 0;

    return ehPar(n - 2);
}

// Potência
int potencia(int base, int expoente){
    if (expoente == 0) return 1;

    return base * potencia(base, expoente - 1);
}

// Número Primo
int ehPrimoRec(int n, int i){
    if (n < 2) return 0; // nao tem primo negativo
    if (i * i > n) return 1; // passou da raiz é primo
    if (n % i == 0) return 0; // tem divisor? nao é primo

    return ehPrimoRec(n, i + 1);
}
int ehPrimo(int n){
    return ehPrimoRec(n, 2);
}

// Palíndromo
int inverte(int n, int invertido){
    if (n == 0) return invertido;

    return inverte(n / 10, invertido * 10 + (n % 10));
}
int ehPalindromo(int n){
    return n == inverte(n, 0);
}

int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    long int fat = fatorial(b);
    int mdc = MDC(a, b);
    int soma = somaD(a);
    int par = ehPar(b);
    long int pot = potencia(a, b);
    int primo = ehPrimo(a);
    int palin = ehPalindromo(a);

    printf("Fatorial (b): %ld\nMDC: %d\nSoma dos Dig (a): %d\nPotencia: %ld\n", 
        fat, mdc, soma, pot);

    if (par) printf("B eh Par!\n");
    else printf("B nao eh Par\n");

    if (primo) printf("A eh Primo!\n");
    else printf("A nao eh primo\n");

    if (palin) printf("A eh palindromo!\n");
    else printf("A nao eh palindromo\n");

    return 0;
}

/* 

MODELO MUNDIAL DE RECURSÃO:

int func(int n){
    if(n == 0) return 0;   // caso base
    
    return n + func(n-1); // chamada recursiva
}
    
*/