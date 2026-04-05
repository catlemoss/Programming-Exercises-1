#include <stdio.h>
#include <string.h>

#define TAM 50

struct tipo_pessoa{
    int idade;
    float peso;
    char nome[TAM];
};

typedef struct tipo_pessoa tipo_pessoa;

int main(){

    // Criando e inicializando
    tipo_pessoa pes = {0, 0.0, "Teste"};

    printf("Inicio:\n");
    printf("pes.idade: %d\n", pes.idade);
    printf("pes.peso: %f\n", pes.peso);
    printf("Pes.nome: %s\n", pes.nome);

    // Atribuindo aos valores
    pes.idade = 10;
    pes.peso = 99.99;
    strcpy(pes.nome, "Cabra");

    printf("\nAlterando os campos via codigo:\n");
    printf("pes.idade: %d\n", pes.idade);
    printf("pes.peso: %f\n", pes.peso);
    printf("Pes.nome: %s\n", pes.nome);

    // Solicitando inserções via teclado
    printf("\nInsira sua idade:\n");
    scanf("%d", &pes.idade);
    printf("Insira seu peso:\n");
    scanf("%f", &pes.peso); 
    printf("Insira seu nome:\n");
    scanf(" %49s", pes.nome); // Limita a leitura a 49 caracteres, pois o 50 é o '\0'

    printf("\nAlternando com dados do usuario:\n");
    printf("pes.idade: %d\n", pes.idade);
    printf("pes.peso: %.2f\n", pes.peso);
    printf("Pes.nome: %s\n", pes.nome);

    return 0;
}