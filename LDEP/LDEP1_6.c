#include <stdio.h>

/* Um código capaz de imprimir a
soma das linhas de uma matriz, seguido, no final, pela soma de todos os valores da
matriz. */

int main(){
	
	int linha, coluna;
	int soma = 0, somaLinha = 0, num;

	scanf("%d %d", &linha, &coluna);

	
	for (int i = 0; i < linha; i++){

		for (int j = 0; j < coluna; j++){

			scanf("%d", &num);
			somaLinha += num;

		}
        printf("%d\n", somaLinha); // dentro do primeiro for para imprimir a soma de cada linha
        soma += somaLinha;
        somaLinha = 0;
	}

	printf("%d", soma);
	return 0;
}