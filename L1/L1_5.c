#include <stdio.h>
 
/* Um programa que dado dois números, mostre o 
maior deles. Caso sejam iguais, mostre que são iguais. */

int main(){
	
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	
	if (num1 > num2){
		printf("N1 = %d", num1);
			
	} else if (num2 > num1){
		printf("N2 = %d", num2);
		
	} else if (num1 == num2){
		printf("N1 = N2");
	}
	
	return 0;
}