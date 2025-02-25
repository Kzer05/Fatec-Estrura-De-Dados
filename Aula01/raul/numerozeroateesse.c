#include <stdio.h>
int main() {
    int i = 0;
    int num;
    printf("Digite um numero maior que 0\n");
    scanf("%d", &num);
    while(i <= num) {
        printf("%d\n", i);
        i++;
    }
}