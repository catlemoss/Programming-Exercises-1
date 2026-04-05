#include <stdio.h>

/*  Um programa para dizer os quatro pontos 
representando os cantos de um retângulo em um plano cartesiano. O retângulo será 
inicialmente descrito por dois pontos representando cantos opostos. 
*/

int main(){

    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    
    int x_min, x_max, y_min, y_max;

    x_min = (x1 < x2) ? x1 : x2;
    x_max = (x1 > x2) ? x1 : x2;
    y_min = (y1 < y2) ? y1 : y2;
    y_max = (y1 > y2) ? y1 : y2;

    printf("(%d,%d)(%d,%d)(%d,%d)(%d,%d)\n",
               x_min, y_max,   // superior esquerdo
               x_min, y_min,   // inferior esquerdo
               x_max, y_min,   // inferior direito
               x_max, y_max);  // superior direito

    return 0;
}