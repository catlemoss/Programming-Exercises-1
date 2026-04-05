#include <stdio.h>

/* Um programa que calcule o perímetro de um 
retângulo.*/

int main(){
	
	float altura, largura;
	scanf("%f %f", &altura, &largura);
	
	float perimetro = (altura + largura) * 2;
	
	printf("%.2f", perimetro);
	return 0;
}