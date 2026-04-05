#include <stdio.h>

/* Um programa que calcule o perímetro de um 
retângulo pelas suas coordenadas.*/

int main(){
	
	float x1, y1, x2, y2;
	scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
	
	float altura = y2 - y1;
	float largura = x2 - x1;
	
	float perimetro = (altura + largura) * 2;
	
	printf("%.2f", perimetro);
	return 0;
}