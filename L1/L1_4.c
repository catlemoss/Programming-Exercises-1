#include <stdio.h>
#include <math.h>
 
/* Um programa para calcular a área de um círculo 
e o raio de um círculo com metade desta área.*/

#define pi 3.141592

int main(){
	
	float raio;
	scanf("%f", &raio);
	
	float area = pi * raio * raio;
	float raio2 = sqrt(area / (2 * pi));
	
	printf("%.2f %.2f", area, raio2);
	return 0;
}