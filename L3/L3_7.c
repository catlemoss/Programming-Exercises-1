#include <stdio.h>

/* Dado as coordenadas x e y das extremidades inferior 
esquerda e superior direita de dois retângulos, calcule a área total ocupada por eles. 
a) O cálculo da área total deverá ser realizado por uma função (a ser implementada) 
que receberá as coordenadas das extremidades de cada retângulo e retornará o 
resultado. 
A função deverá ter o seguinte cabeçalho: 
int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2); 
b) O cálculo da área de um retângulo deverá ser realizado por uma função (a ser 
implementada) que receberá as coordenadas das extremidades desse retângulo e 
retornará o resultado. A função deverá ter o seguinte cabeçalho: 
int area (int x1, int y1, int x2, int y2); */

int area (int x1, int y1, int x2, int y2){

    return (x2 - x1) * (y2 - y1);
}

int area_total (int r1_x1, int r1_y1, int r1_x2, int r1_y2, int r2_x1, int r2_y1, int r2_x2, int r2_y2){

    int area_r1 = area(r1_x1, r1_y1, r1_x2, r1_y2);
    int area_r2 = area(r2_x1, r2_y1, r2_x2, r2_y2);

    int meio_x1 = (r1_x1 > r2_x1) ? r1_x1 : r2_x1; // If Else diferente e mais bonito (clean né)
    int meio_y1 = (r1_y1 > r2_y1) ? r1_y1 : r2_y1;
    int meio_x2 = (r1_x2 < r2_x2) ? r1_x2 : r2_x2;
    int meio_y2 = (r1_y2 < r2_y2) ? r1_y2 : r2_y2;

    // int resultado = (condição) ? valor_se_verdadeiro : valor_se_falso;

    int area_meio = 0; // Inicilizar porque pode ser que não haja meio

    if (meio_x1 < meio_x2 && meio_y1 < meio_y2){

        area_meio = area(meio_x1, meio_y1, meio_x2, meio_y2);
    }

    return area_r1 + area_r2 - area_meio;
}
// Esta função calcula a área total ocupada por dois retângulos, 
// subtraindo a área de interseção, se existir.

int main(){

    int r1_x1, r1_y1, r1_x2, r1_y2;
    int r2_x1, r2_y1, r2_x2, r2_y2;

    scanf("%d %d %d %d", &r1_x1, &r1_y1, &r1_x2, &r1_y2);
    scanf("%d %d %d %d", &r2_x1, &r2_y1, &r2_x2, &r2_y2);

    int area_totalizada = area_total(r1_x1, r1_y1, r1_x2, r1_y2, r2_x1, r2_y1, r2_x2, r2_y2);
    
    printf("RESP:%d", area_totalizada);

    return 0;
}