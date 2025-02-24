#include <stdio.h>

int main()
{
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade >= 18)
    {
        printf("\nMaior de idade!");
        return 0;
    }

    printf("\nMenor de idade!");
    return 0;
}