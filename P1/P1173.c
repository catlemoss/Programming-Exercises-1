#include <stdio.h>

/* Um programa para comparar dois códigos 
alfanuméricos se eles forem válidos. Cada código contém dois caracteres que só 
podem ser letras ou números, qualquer outro caractere invalida o código. Os códigos 
são considerados iguais quando seus respectivos caracteres são iguais 
indiferentemente da letra ser maiúscula ou minúscula. 
*/

int ehNumero(char c){
    if (c >= '0' && c <= '9') return 1;
    if (c >= 'A' && c <= 'Z') return 1;
    if (c >= 'a' && c <= 'z') return 1;
    return 0;
}

char paraMinuscula(char c){
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

int ehEspaco(int x){
    return x == ' ' || x == '\t' || x == '\n' || x == '\r';
}

int main(){
    int codigo;

    codigo = getchar();
    if (codigo == EOF){ 
        printf("Invalido\n"); 
        return 0; 
    }
    char a = (char)codigo; //11

    codigo = getchar();
    if (codigo == EOF){ 
        printf("Invalido\n"); 
        return 0; 
    }
    char b = (char)codigo; // 12

    // espaco
    codigo = getchar();
    if (codigo == EOF){ 
        printf("Invalido\n"); 
        return 0; 
    }

    if (!ehEspaco(codigo)){
        while (codigo != EOF && !ehEspaco(codigo)) codigo = getchar();
        printf("Invalido\n");
        return 0;
    }

    codigo = getchar();
    if (codigo == EOF){ 
        printf("Invalido\n"); 
        return 0; 
    }
    char c = (char)codigo; // 21

    codigo = getchar();
    if (codigo == EOF){ 
        printf("Invalido\n"); 
        return 0; 
    }
    char d = (char)codigo; //22

    codigo = getchar();
    if (codigo != EOF && !ehEspaco(codigo)) {
        while (codigo != EOF && !ehEspaco(codigo)) codigo = getchar();
        printf("Invalido\n");
        return 0;
    }

    if (!ehNumero(a) || !ehNumero(b) || !ehNumero(c) || !ehNumero(d)) {
        printf("Invalido\n");
        return 0;
    }

    if (paraMinuscula(a) == paraMinuscula(c) && paraMinuscula(b) == paraMinuscula(d)) printf("IGUAIS\n");
    else printf("DIFERENTES\n");

    return 0;
}