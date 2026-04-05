#include <stdio.h>
 
/* Um programa que calcule a média de duas notas e 
diga se o aluno está aprovado caso sua média seja maior ou igual a 7.0, reprovado 
caso média menor que 5.0 ou de recuperação caso contrário.  */

int main(){
	
	float nota1, nota2;
	scanf("%f %f", &nota1, &nota2);
	
	float media = (nota1 + nota2) / 2;
	
	if (media >= 7.0){
		printf("%.1f - Aprovado", media);
		
	} else if (7.0 > media && media >= 5.0){
		printf("%.1f - De Recuperacao", media);
		
	} else {
		printf("%.1f - Reprovado", media);
	}
	
	return 0;
}