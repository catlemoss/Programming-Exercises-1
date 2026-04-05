#include <stdio.h>

int main(){

    int = inteiros + %d; // Inteiros são números sem casas decimais
    unsigned long = inteiros positivos grandes + %lu;// Inteiros positivos grandes são números sem sinal e sem casas decimais
    long = inteiros grandes + %ld; // Inteiros grandes são números sem casas decimais
    unsigned = inteiros positivos + %u; // Inteiros positivos são números sem sinal e sem casas decimais
    short = inteiros pequenos + %hd; // Inteiros pequenos são números sem casas decimais
    float = decimais + %f; // Decimais são números com casas decimais
    double = reais (mais precisão) + %lf; // Reais são números com casas decimais e mais precisão
    char = caracteres (texto) + %c; // Caracteres são letras ou símbolos
    long long int = inteiros grandes + %lld; // Inteiros grandes são números sem sinal e sem casas decimais
    unsigned long long int = inteiros positivos grandes + %llu; // Inteiros positivos grandes são números sem sinal e sem casas decimais
    unsigned char = caracteres (texto) + %c; // Caracteres são letras ou símbolos
    unsigned int = inteiros positivos + %u;// Inteiros positivos são números sem sinal e sem casas decimais
    short int = inteiros pequenos + %hd;// Inteiros pequenos são números sem casas decimais

    scanf("%d", &escolha_da_pessoa);
    printf("Texto na tela\n");

    \n = pular linha;
    \t = espaço;

    != diferente de;
    == igual a;
    += adicionar e atribuir;
    -= subtrair e atribuir;
    *= multiplicar e atribuir;
    /= dividir e atribuir;
    %= resto da divisão e atribuir;
    ++ = incrementar;
    -- = decrementar;
    && = e lógico;
    || = ou lógico;
    ! = negação lógica;
    & = endereço de memória;
    * = ponteiro;

    n % 2 == 0	Ver se o número é par	6 → par (sim);
    n % 10	Pegar o dígito da unidade	382 → 2;
    n / 10	Pegar o número sem a unidade	382 → 38;

    sizeof(tipo) = tamanho do tipo em bytes;
    pow(base, expoente) = base ^ expoente;
    sqrt(numero) = raiz quadrada de numero;
    int resultado = (condição) ? valor_se_verdadeiro : valor_se_falso;


    if(comparação entre duas variáveis){
        // Código que será executado se a condição for verdadeira
        printf("Texto se for verdadeiro\n");
    } else {
        printf("Texto se for falso\n");
    }

    switch (variável) {
        case valor1:
            // Código para valor1
            printf("Texto para valor1\n");
            break;
        case valor2:
            // Código para valor2
            printf("Texto para valor2\n");
            break;
        default:
            // Código se nenhum caso for atendido
            printf("Texto padrão\n");
    }
    
    while(condiçãoque pode ser verdadeira ou falsa){
        // Código que será executado enquanto a condição for verdadeira
        printf("Texto enquanto a condição for verdadeira\n");
    }

    for (valor inicial; condição; incremento){
        (int i = 0; i < x; i++) {
        // Código que será executado enquanto a condição for verdadeira
        printf("Texto dentro do loop for\n");
        }
    }

    int vetor[x]; // Declaração de um vetor de inteiros com x posições
    vetor[0] = 1; // Atribuição de valor à primeira posição do vetor
    vetor[1] = 2; // Atribuição de valor à segunda posição do vetor

    for (int i = 0; i < x; i++) {
        scanf("%d", &vetor[i]);
        printf("Valor do vetor na posição %d: %d\n", i, vetor[i]);
    }

    int matriz[x][y]; // Declaração de uma matriz de inteiros com x linhas e y colunas
    matriz[0][0] = 1; // Atribuição de valor à primeira posição da matriz
    matriz[0][1] = 2; // Atribuição de valor à segunda posição da matriz
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &matriz[i][j]);
            printf("Valor da matriz na posição [%d][%d]: %d\n", i, j, matriz[i][j]);
        }
    }
    
    for (int linha = 1; linha <= 3; linha++) {
        for (int coluna = 1; coluna <= 3; coluna++) {
            printf("(%d,%d)\n", linha, coluna);
        }
    } // Exemplo de loop aninhado para imprimir coordenadas de uma matriz 3x3

    return 0;
}

// Fim do programa sem erros



int ehPrimo(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}