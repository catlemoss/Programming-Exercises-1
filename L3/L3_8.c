#include <stdio.h>

/* Um programa que, dado o tamanho de uma matriz e seus valores, que
nunca são iguais, transforma seus valores no próximo número primo
maior que o próprio valor se o valor é positivo e 
menor que o próprio valor se o valor é negativo. 
Caso o valor já seja primo ou se o primo
transformado extrapolar os intervalos de entrada possível, o programa
não deve fazer nenhuma mudança. */

int verificaPrimo(int n){
	
    if (n < 0) n = -n; // agora existem numeros primos negativos
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int verificaNegativo(int n){
	
	if (n < 0) return 1;
	return 0;
}

int transformaPrimo(int n){
	
	int proximo;
	
	if (verificaPrimo(n)) return n;
		
	if (verificaNegativo(n)){

        int proximo = n - 1;

        while (proximo >= -32000){
            
            if (verificaPrimo(proximo)) return proximo;
            proximo--;
        }
        return n;

    } else {

        int proximo = n + 1;

        while (proximo <= 32000){

            if (verificaPrimo(proximo)) return proximo;
            proximo++;
        }
        return n;
    }
}

int main(){
	
	int linha, coluna;
	scanf("%d %d", &linha, &coluna);

    int matriz[100][100]; // é necessário definir um tamanho máximo para a matriz 
	
	for (int i = 0; i < linha; i++){
		
		for (int j = 0; j < coluna; j++){
			
			scanf("%d", &matriz[i][j]);
			
			matriz[i][j] = transformaPrimo(matriz[i][j]);

            printf("%d ", matriz[i][j]);
		}

        printf("\n");
	}
	
	return 0;
}