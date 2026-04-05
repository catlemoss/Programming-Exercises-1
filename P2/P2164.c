#include <stdio.h>

/*  Após estudar muita programação, um certo 
aluno não conseguia mais escrever textos com números normais. Ao invés de usar 
números simples, ele estava escrevendo em forma de expressões com notação pós
fixada (i.e. operando da esquerda, operando da direita e operador) entre parênteses. 
Antes de passar o texto para outras pessoas lerem, ele precisa de sua ajuda para 
converter os valores das expressões entre parênteses para números comuns com 
precisão de duas casas decimais. Além disso ele precisa imprimir, no final, o maior 
valor que apareceu no texto.   
*/

float FazOperacao(float num1, float num2, char op){
    switch(op){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num2 == 0 ? 0 : num1 / num2;
    }
    return 0;
}

float ResolveExpressao(){
    float resultado, num;
    int c;

    if (scanf("%f", &resultado) != 1) return 0;

    while (1){

        do { c = getchar(); } while (c == ' ' || c == '\n' || c == '\t' || c == '\r');

        if (c == ')') return resultado;

        ungetc(c, stdin); // nova aquisição: devolve um caractere (c) ao fluxo de entrada (stdin)

        if (scanf("%f", &num) != 1) return resultado;

        do { c = getchar(); } while (c == ' ' || c == '\n' || c == '\t' || c == '\r');

        if (c == '+' || c == '-' || c == '*' || c == '/'){
            resultado = FazOperacao(resultado, num, (char)c);
        } else if (c == ')'){
            return resultado;
        } else {
            continue;
        }
    }
}

int main(){
    int c;
    float valor;
    float maior = -999999;

    while ((c = getchar()) != EOF){
        if (c == '.') {
            putchar('.'); // nova aquisição: escreve um caractere na saída
            if (maior > -999999) 
                printf(" MAIOR:%.2f\n", maior);
            else
                printf(" MAIOR:0.00\n");
                maior = -999999;
                break;
        }

        if (c == '('){
            valor = ResolveExpressao();
            if (valor > maior) maior = valor;
            printf("%.2f", valor);
        } else {
            putchar(c);
        }
    }
    return 0;
}