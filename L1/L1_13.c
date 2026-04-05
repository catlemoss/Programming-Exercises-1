#include <stdio.h>
 
/* Um programa que distribuía itens para um grupo de 
pessoas, e retorne quem foi a última pessoa a receber um item. */

int main(){
	
	int pessoas, itens;
	scanf("%d %d", &pessoas, &itens);
	
	int ultimaPessoa = (itens - 1) % pessoas + 1; // cálculo da última pessoa a receber um item
	
	printf("RESP:%d", ultimaPessoa);
	
	return 0;
}

