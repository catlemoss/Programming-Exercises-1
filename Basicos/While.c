#include <stdio.h>

int main(){

    int i = 0; //Sempre é necessário inicializar a variável antes do loop

    while (i <= 10) {
        printf("%d ", i);
        i++;
    }

    return 0;
}
// This code demonstrates a simple while loop in C that prints the value of i from 0 to 9.
// The loop continues as long as the condition (i <= 10) is true, incrementing i by 1 in each iteration.
// The while loop is useful when the number of iterations is not known beforehand, as it continues
// until the condition becomes false. In this case, it will stop when i exceeds 10.