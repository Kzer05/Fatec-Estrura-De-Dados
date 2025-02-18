#include <stdio.h>

int main(){
    int x, y;
    printf("Insira dois numeros:\n");
    scanf("%d %d", &x, &y);
    printf("%d + %d = %f\n", x, y, x+y);
    printf("%d - %d = %f\n", x, y, x*y);
    printf("%d * %d = %f\n", x, y, x*y);
    printf("%d / %d = %f\n", x, y, x/y);
    printf("%d // %d = %f\n", x, y, x%y);
    return 0;
}