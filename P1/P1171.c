#include <stdio.h>

int main(){

    int n, m;
    char c;
    int resp = 0;

    scanf("%d %d", &n, &m);
    scanf(" %c",&c);

    if (c == '+'){
        resp= n + m;
        printf("RESP:%d", resp);

    } else if (c == '-'){
        resp= n - m;
        printf("RESP:%d", resp);

    } else if (c == '*'){
        resp= n * m;
        printf("RESP:%d", resp);

    } else if (c == '/'){
        resp= n / m;
        printf("RESP:%d", resp);

    } else {
        printf("Invalido");

    }
    return 0;
}