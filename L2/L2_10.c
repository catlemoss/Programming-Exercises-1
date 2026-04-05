#include <stdio.h>

/* Um programa que imprima na tela as tabuadas de n
até m. */

int main(){

    int n, m, mult;
    scanf("%d %d", &n, &m);

    for (int i = n; i <= m; i++){

        for (int j = 1; j <= 10; j++){

            mult = i * j;
            printf("%d x %d = %d\n", i, j, mult);
        }
    }

    return 0;
}