#include <stdio.h>
 
/* Dado dois pares de 
pontos que definem duas retas, determinar se as retas são paralelas, 
perpendiculares ou nenhum dos dois  */

int main(){

    int x1, y1, x2, y2; // primeira reta
    int x3, y3, x4, y4; // segunda reta
    float m1, m2; // coeficientes angulares

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

    m1 = (float)(y2 - y1) / (x2 - x1); // coeficiente angular da primeira reta
    m2 = (float)(y4 - y3) / (x4 - x3); // coeficiente angular da segunda reta

    if (m1 == m2) {
        printf("PARALELAS\n");
    } 
    else if (m1 * m2 == -1) {
        printf("PERPENDICULARES\n");
    } 
    else {
        printf("NENHUM\n");
    }

    return 0;
}