#include <stdio.h>
 
/* Um programa em que dada uma temperatura em 
Celsius ou Fahrenheit converta esta temperatura para a outra unidade.*/

int main(){
	
	float temperatura;
	char unidade;
	scanf("%f %c", &temperatura, &unidade);
	
	float conversao;
	
	if (unidade == 'f' || unidade == 'F'){ // lembrar que char eh aspas simples
		conversao = 5.0 / 9 * (temperatura - 32); // lembrar de usar 5.0 para float
		
		printf("%.2f (C)", conversao);
		
	} else if (unidade == 'c' || unidade == 'C'){
		conversao = (temperatura * 9 / 5) + 32;
		
		printf("%.2f (F)", conversao);
	}
	
	return 0;
}