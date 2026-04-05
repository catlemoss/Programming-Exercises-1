#include <stdio.h>
 
/* Um programa para apresentar todos os números 
contidos em um intervalo e que sejam múltiplos de 3, 4 ou 7.  */

int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = n + 1; i < m; i++){
		
		if (i % 3 == 0 || i % 4 == 0 || i % 7 == 0){
			printf("%d ", i);
		}
	}
	
	return 0;
}