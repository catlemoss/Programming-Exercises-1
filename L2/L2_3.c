#include <stdio.h>
 
/* Um programa que leia n números positivos e retorne 
o maior e o menor destes, a quantidades de pares, a quantidade de ímpares, e a 
média deles. */

int main(){
	
	int quant, maior = -999, menor = 999, par = 0, impar = 0, somaNums = 0;
	float media;
	scanf("%d", &quant);
	
		for (int i = 0; i < quant; i++){
		
			int nums;
			scanf("%d", &nums);
		
			if (nums > maior) maior = nums;
			if (nums < menor) menor = nums;
			
			if (nums % 2 == 0) par++;
				else impar++;
				 
            somaNums += nums; // variável acumuladora
			media = (float)somaNums / quant; 
		}
	
	printf("%d %d %d %d %f", maior, menor, par, impar, media);
	return 0;
}