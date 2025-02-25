#include <stdio.h>

int main(){

    int senha = 1234;
    int num;
    do
    {
        printf("Tente adivinha a senha (Dica e bem dificil): \n");
        scanf("%d",&num);
    } while (num != senha);

    printf("Acertou");

    return 0;
}