#include <stdio.h>

int main(){
    int numero;

    printf("Informe um numero: \n");
    scanf("%d",&numero);     

    int i = 0;
    while ( i <= numero) {
        printf("%d\n", i);
        i ++;
    }

    return 0;
}