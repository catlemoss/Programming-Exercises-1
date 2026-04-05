#include <stdio.h>
 
/* Um programa que diga se um ponto está contido em 
um retângulo dado os cantos opostos do mesmo. */

int main(){

    float x1, y1, x2, y2, px, py;
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &px, &py);

    float xmin = (x1 < x2) ? x1 : x2;
    float xmax = (x1 > x2) ? x1 : x2;
    float ymin = (y1 < y2) ? y1 : y2;
    float ymax = (y1 > y2) ? y1 : y2;

    if (px >= xmin && px <= xmax && py >= ymin && py <= ymax){
        printf("Dentro");

    } else {
        printf("Fora");
    }

    return 0;
}
