#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

struct tipo_pessoa{
    int idade;
    float peso;
    char nome[50];
};

typedef struct tipo_pessoa tipo_pessoa;

int main(){

    tipo_pessoa lista[TAM];
    int i;

    for (i = 0; i < TAM; i++) {
        printf("Insira os dados da pessoa %d:\n", i + 1);

        printf("Nome: ");
        fgets(lista[i].nome, sizeof(lista[i].nome), stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = '\0'; // Remove o '\n'

        printf("Idade: ");
        scanf("%d", &lista[i].idade);
        getchar(); // Limpa o '\n' do buffer

        printf("Peso: ");
        scanf("%f", &lista[i].peso);
        getchar(); // Limpa o '\n' do buffer
    }

    printf("\nSeus dados:\n");
    for (i = 0; i < TAM; i++){
        printf("----- Pessoa %d -----\n", i + 1);
        printf("\tNome: %s\n", lista[i].nome);
        printf("\tIdade: %d\n", lista[i].idade);
        printf("\tPeso: %.2f\n", lista[i].peso);
    }
    return 0;
}